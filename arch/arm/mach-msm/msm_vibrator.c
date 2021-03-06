/*
* Certain software is contributed or developed by TOSHIBA CORPORATION.
* Copyright (C) 2010 TOSHIBA CORPORATION All rights reserved.
* This software is licensed under the terms of the GNU General Public
* License version 2, as published by FSF, and
* may be copied, distributed, and modified under those terms.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* This code is based on msm_vibrator.c.
* The original copyright and notice are described below.
*/

/* include/asm/mach-msm/htc_pwrsink.h
 *
 * Copyright (C) 2008 HTC Corporation.
 * Copyright (C) 2007 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/err.h>
#include <linux/hrtimer.h>
#include <../../../drivers/staging/android/timed_output.h>
#include <linux/sched.h>

#include <mach/msm_rpcrouter.h>

#define PM_LIBPROG      0x30000061
#if 0
#if (CONFIG_MSM_AMSS_VERSION == 6220) || (CONFIG_MSM_AMSS_VERSION == 6225)
#define PM_LIBVERS      0xfb837d0b
#else
#define PM_LIBVERS      0x10001
#endif
#else
#define PM_LIBVERS      0x10001
#endif

#if 0
#define HTC_PROCEDURE_SET_VIB_ON_OFF	21
#else
#define HTC_PROCEDURE_SET_VIB_ON_OFF	22
#endif

#define PMIC_VIBRATOR_LEVEL	(3000)

static int vibrator_value;
static struct work_struct work_vibrator_on;
static struct delayed_work work_vibrator_off;
static struct hrtimer vibe_timer;
static struct mutex vib_mutex;
static void timed_vibrator_off(struct timed_output_dev *sdev, int delay);
static void timed_vibrator_on(struct timed_output_dev *sdev);
static int vibrator_get_time(struct timed_output_dev *dev);

static int vibrator_timer_active(void)
{
   int ret = 0;
   mutex_lock(&vib_mutex);
   if (hrtimer_active(&vibe_timer)) {
	   ret = 1;
   }
   mutex_unlock(&vib_mutex);
   return ret;
}

static void set_pmic_vibrator(int on)
{
	static struct msm_rpc_endpoint *vib_endpoint;
	struct set_vib_on_off_req {
		struct rpc_request_hdr hdr;
		uint32_t data;
	} req;

	if (!vib_endpoint) {
		vib_endpoint = msm_rpc_connect(PM_LIBPROG, PM_LIBVERS, 0);
		if (IS_ERR(vib_endpoint)) {
			printk(KERN_ERR "init vib rpc failed!\n");
			vib_endpoint = 0;
			return;
		}
	}


	if (on)
		req.data = cpu_to_be32(PMIC_VIBRATOR_LEVEL);
	else
		req.data = cpu_to_be32(0);

	msm_rpc_call(vib_endpoint, HTC_PROCEDURE_SET_VIB_ON_OFF, &req,
		sizeof(req), 5 * HZ);
}

static void pmic_vibrator_on(struct work_struct *work)
{
        hrtimer_start(&vibe_timer,ktime_set(vibrator_value / 1000, (vibrator_value % 1000) * 1000000),HRTIMER_MODE_REL);	     set_pmic_vibrator(1);
	if (!vibrator_timer_active()) {
		/* No timer active, there may in infinite vibration, so switch off */
		timed_vibrator_off(NULL, 0);
	}
}

static void pmic_vibrator_off(struct work_struct *work)
{
	set_pmic_vibrator(0);
	if (vibrator_timer_active()) {
		/* Make it on, timer will switch it off */
		set_pmic_vibrator(1);
	}
}

static void timed_vibrator_on(struct timed_output_dev *sdev)
{
	schedule_work(&work_vibrator_on);
}

static void timed_vibrator_off(struct timed_output_dev *sdev, int delay)
{
        schedule_delayed_work(&work_vibrator_off, msecs_to_jiffies(delay));
}

static void vibrator_enable(struct timed_output_dev *dev, int value)
{
        int vibrator_time = 0;
	if (value == 0) {
		if (vibrator_timer_active()) {
                   vibrator_time = vibrator_get_time(dev);
		//	hrtimer_cancel(&vibe_timer);
			/* Put a delay of 10 ms, in case the vibrator is off immediately */
                       if (vibrator_time < 10 || vibrator_time > 50)   
                          {
                            hrtimer_cancel(&vibe_timer);
                            vibrator_time = 0;
                          }

                        vibrator_value = value;
                        timed_vibrator_off(dev, vibrator_time + 10);
		}
	}
	else {
                vibrator_value = (value > 15000 ? 15000 : value);
		hrtimer_cancel(&vibe_timer);
		timed_vibrator_on(dev);
	}
}

static int vibrator_get_time(struct timed_output_dev *dev)
{
	if (hrtimer_active(&vibe_timer)) {
		ktime_t r = hrtimer_get_remaining(&vibe_timer);
		return r.tv.sec * 1000 + r.tv.nsec / 1000000;
	} else
		return 0;
}

static enum hrtimer_restart vibrator_timer_func(struct hrtimer *timer)
{
	timed_vibrator_off(NULL,0);
	return HRTIMER_NORESTART;
}

static struct timed_output_dev pmic_vibrator = {
	.name = "vibrator",
	.get_time = vibrator_get_time,
	.enable = vibrator_enable,
};

void __init msm_init_pmic_vibrator(void)
{
	mutex_init(&vib_mutex);
	INIT_WORK(&work_vibrator_on, pmic_vibrator_on);
	INIT_DELAYED_WORK(&work_vibrator_off, pmic_vibrator_off);

	hrtimer_init(&vibe_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	vibe_timer.function = vibrator_timer_func;

	timed_output_dev_register(&pmic_vibrator);
}

MODULE_DESCRIPTION("timed output pmic vibrator device");
MODULE_LICENSE("GPL");

