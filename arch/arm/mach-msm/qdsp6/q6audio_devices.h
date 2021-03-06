/*
 * Certain software is contributed or developed by TOSHIBA CORPORATION.
 *
 * Copyright (C) 2010 TOSHIBA CORPORATION All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by FSF, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * This code is based on q6audio_devices.h.
 * The original copyright and notice are described below.
 */
/* arch/arm/mach-msm/qdsp6/q6audio_devices.h
 *
 * Copyright (C) 2009 Google, Inc.
 * Author: Brian Swetland <swetland@google.com>
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

struct q6_device_info {
	uint32_t id;
	uint32_t cad_id;
	uint32_t path;
	uint32_t rate;
	uint8_t dir;
	uint8_t codec;
	uint8_t hw;
};

#define Q6_ICODEC_RX		0
#define Q6_ICODEC_TX		1
#define Q6_ECODEC_RX		2
#define Q6_ECODEC_TX		3
#define Q6_SDAC_RX		6
#define Q6_SDAC_TX		7
#define Q6_CODEC_NONE		255

#define Q6_TX		1
#define Q6_RX		2
#define Q6_TX_RX	3

#define Q6_HW_HANDSET	0
#define Q6_HW_HEADSET	1
#define Q6_HW_SPEAKER	2
#define Q6_HW_TTY	3
#define Q6_HW_BT_SCO	4
#define Q6_HW_BT_A2DP	5

#define Q6_HW_COUNT	6

#define CAD_HW_DEVICE_ID_HANDSET_MIC		0x01
#define CAD_HW_DEVICE_ID_HANDSET_SPKR		0x02
#define CAD_HW_DEVICE_ID_HEADSET_MIC		0x03
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_MONO	0x04
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_STEREO	0x05
#define CAD_HW_DEVICE_ID_SPKR_PHONE_MIC		0x06
#define CAD_HW_DEVICE_ID_SPKR_PHONE_MONO	0x07
#define CAD_HW_DEVICE_ID_SPKR_PHONE_STEREO	0x08
#define CAD_HW_DEVICE_ID_BT_SCO_MIC		0x09
#define CAD_HW_DEVICE_ID_BT_SCO_SPKR		0x0A
#define CAD_HW_DEVICE_ID_BT_A2DP_SPKR		0x0B
#define CAD_HW_DEVICE_ID_TTY_HEADSET_MIC	0x0C
#define CAD_HW_DEVICE_ID_TTY_HEADSET_SPKR	0x0D

#define CAD_HW_DEVICE_ID_DEFAULT_TX		0x0E
#define CAD_HW_DEVICE_ID_DEFAULT_RX		0x0F


#define CAD_HW_DEVICE_ID_SPKR_PHONE_DUAL_MIC_BROADSIDE      0x2B
#define CAD_HW_DEVICE_ID_SPKR_PHONE_DUAL_MIC_ENDFIRE        0x2D
#define CAD_HW_DEVICE_ID_HANDSET_DUAL_MIC_BROADSIDE         0x2C
#define CAD_HW_DEVICE_ID_HANDSET_DUAL_MIC_ENDFIRE           0x2E

/* Logical Device to indicate A2DP routing */
#define CAD_HW_DEVICE_ID_BT_A2DP_TX             0x10
#define CAD_HW_DEVICE_ID_HEADSET_MONO_PLUS_SPKR_MONO_RX		0x11
#define CAD_HW_DEVICE_ID_HEADSET_MONO_PLUS_SPKR_STEREO_RX	0x12
#define CAD_HW_DEVICE_ID_HEADSET_STEREO_PLUS_SPKR_MONO_RX	0x13
#define CAD_HW_DEVICE_ID_HEADSET_STEREO_PLUS_SPKR_STEREO_RX	0x14

#define CAD_HW_DEVICE_ID_VOICE			0x15

#define CAD_HW_DEVICE_ID_I2S_RX                 0x20
#define CAD_HW_DEVICE_ID_I2S_TX                 0x21

/* AUXPGA */
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_STEREO_LB 0x22
#define CAD_HW_DEVICE_ID_HEADSET_SPKR_MONO_LB   0x23
#define CAD_HW_DEVICE_ID_SPEAKER_SPKR_STEREO_LB 0x24
#define CAD_HW_DEVICE_ID_SPEAKER_SPKR_MONO_LB   0x25

#define CAD_HW_DEVICE_ID_NULL_RX		0x2A

/* acdb setting */
#define CAD_HW_DEVICE_ID_BT_SCO_MIC_ECO_OFF     0x30
#define CAD_HW_DEVICE_ID_BT_SCO_SPKR_ECO_OFF    0x31
#define CAD_HW_DEVICE_ID_VOICE_RECOG_SPK_MIC    0x42

//#define CAD_HW_DEVICE_ID_MAX_NUM                0x2F
#define CAD_HW_DEVICE_ID_MAX_NUM                0x4F  //acdb setting

#define CAD_HW_DEVICE_ID_INVALID                0xFF

#define CAD_RX_DEVICE  0x00
#define CAD_TX_DEVICE  0x01

static struct q6_device_info q6_audio_devices[] = {
	{
		.id	= ADSP_AUDIO_DEVICE_ID_HANDSET_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_HANDSET_SPKR,
		//.path	= ADIE_PATH_HANDSET_RX,
		.path	= ADIE_PATH_HANDSET_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_HANDSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_HEADSET_SPKR_MONO,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_SPKR_MONO,
		//.path	= ADIE_PATH_HEADSET_MONO_RX,
		.path	= ADIE_PATH_HEADSET_MONO_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_HEADSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_HEADSET_SPKR_STEREO,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_SPKR_STEREO,
		//.path	= ADIE_PATH_HEADSET_STEREO_RX,
		.path	= ADIE_PATH_HEADSET_STEREO_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_HEADSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_MONO,
		.cad_id	= CAD_HW_DEVICE_ID_SPKR_PHONE_MONO,
		//.path	= ADIE_PATH_SPEAKER_RX,
		.path	= ADIE_PATH_SPEAKER_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_STEREO,
		.cad_id	= CAD_HW_DEVICE_ID_SPKR_PHONE_STEREO,
		//.path	= ADIE_PATH_SPEAKER_STEREO_RX,
		.path	= ADIE_PATH_SPEAKER_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_MONO_W_MONO_HEADSET,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_MONO_PLUS_SPKR_MONO_RX,
		//.path	= ADIE_PATH_SPKR_MONO_HDPH_MONO_RX,
		.path	= ADIE_PATH_HEADSET_SPEAKER_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_MONO_W_STEREO_HEADSET,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_STEREO_PLUS_SPKR_MONO_RX,
		//.path	= ADIE_PATH_SPKR_MONO_HDPH_STEREO_RX,
		.path	= ADIE_PATH_HEADSET_SPEAKER_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_STEREO_W_MONO_HEADSET,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_MONO_PLUS_SPKR_STEREO_RX,
		//.path	= ADIE_PATH_SPKR_STEREO_HDPH_MONO_RX,
		.path	= ADIE_PATH_HEADSET_SPEAKER_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_STEREO_W_STEREO_HEADSET,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_STEREO_PLUS_SPKR_STEREO_RX,
		//.path	= ADIE_PATH_SPKR_STEREO_HDPH_STEREO_RX,
		.path	= ADIE_PATH_HEADSET_SPEAKER_SOUND_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_TTY_HEADSET_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_TTY_HEADSET_SPKR,
		.path	= ADIE_PATH_TTY_HEADSET_RX,
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_TTY,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_HANDSET_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_HANDSET_MIC,
		.path	= ADIE_PATH_HANDSET_TX,
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_HANDSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_HEADSET_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_MIC,
		.path	= ADIE_PATH_HEADSET_MONO_TX,
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_HEADSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_SPKR_PHONE_MIC,
		.path	= ADIE_PATH_SPEAKER_TX,
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_VOICE_RECOG_SPK_MIC,
		.path	= ADIE_PATH_SPEAKER_TX,
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_HANDSET_DUAL_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_HANDSET_DUAL_MIC_ENDFIRE,
		.path	= ADIE_CODEC_HANDSET_SPKR_EF_TX,
		.rate	= 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_HANDSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_HANDSET_DUAL_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_HANDSET_DUAL_MIC_BROADSIDE,
		.path	= ADIE_CODEC_HANDSET_SPKR_BS_TX,
		.rate	= 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_HANDSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_DUAL_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_SPKR_PHONE_DUAL_MIC_ENDFIRE,
		.path	= ADIE_CODEC_HANDSET_SPKR_EF_TX,
		.rate	= 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_SPKR_PHONE_DUAL_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_SPKR_PHONE_DUAL_MIC_BROADSIDE,
		.path	= ADIE_CODEC_HANDSET_SPKR_BS_TX,
		.rate	= 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_TTY_HEADSET_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_TTY_HEADSET_MIC,
		.path	= ADIE_PATH_TTY_HEADSET_TX,
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_HEADSET,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_BT_SCO_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_BT_SCO_SPKR,
		.path	= 0, /* XXX */
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ECODEC_RX,
		.hw	= Q6_HW_BT_SCO,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_BT_SCO_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_BT_SCO_SPKR_ECO_OFF,
		.path	= 0, /* XXX */
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ECODEC_RX,
		.hw	= Q6_HW_BT_SCO,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_BT_A2DP_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_BT_A2DP_SPKR,
		.path	= 0, /* XXX */
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ECODEC_RX,
		.hw	= Q6_HW_BT_A2DP,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_BT_SCO_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_BT_SCO_MIC,
		.path	= 0, /* XXX */
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ECODEC_TX,
		.hw	= Q6_HW_BT_SCO,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_BT_SCO_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_BT_SCO_MIC_ECO_OFF,
		.path	= 0, /* XXX */
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ECODEC_TX,
		.hw	= Q6_HW_BT_SCO,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_I2S_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_I2S_RX,
		.path	= 0, /* XXX */
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_SDAC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= ADSP_AUDIO_DEVICE_ID_I2S_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_I2S_TX,
		.path	= 0, /* XXX */
		.rate   = 16000,
		.dir	= Q6_TX,
		.codec	= Q6_SDAC_TX,
		.hw	= Q6_HW_SPEAKER,
	},
	{ //RX TEST HANDSET
		.id	= ADSP_AUDIO_DEVICE_ID_TEST_LB_HANDSET_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_HANDSET_SPKR,
		.path	= (0x01074f06),
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_HANDSET,
	},
	{ //RX TEST HEADSET
		.id	= ADSP_AUDIO_DEVICE_ID_TEST_LB_HEADSET_SPKR,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_SPKR_STEREO,
		.path	= (0x01074f07),
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_HEADSET,
	},
	{ //RX TEST SPEAKER
		.id	= ADSP_AUDIO_DEVICE_ID_TEST_LB_SPKR_PHONE,
		.cad_id	= CAD_HW_DEVICE_ID_SPKR_PHONE_STEREO,
		.path	= (0x01074f08), 
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{ //TX TEST HANDSET
		.id	= ADSP_AUDIO_DEVICE_ID_TEST_LB_HANDSET_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_HANDSET_MIC,
		.path	= (0x01074f09),
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_HANDSET,
	},
	{ //TX TEST HEADSET
		.id	= ADSP_AUDIO_DEVICE_ID_TEST_LB_HEADSET_MIC,
		.cad_id	= CAD_HW_DEVICE_ID_HEADSET_MIC,
		.path	= (0x01074f0A),
		.rate   = 8000,
		.dir	= Q6_TX,
		.codec	= Q6_ICODEC_TX,
		.hw	= Q6_HW_HEADSET,
	},
	{ //DUMMY RX
		.id	= ADSP_AUDIO_DEVICE_ID_NULL_SINK,
		.cad_id	= CAD_HW_DEVICE_ID_NULL_RX,
		.path	= ADIE_PATH_DUMMY_RX, 
		.rate   = 48000,
		.dir	= Q6_RX,
		.codec	= Q6_ICODEC_RX,
		.hw	= Q6_HW_SPEAKER,
	},
	{
		.id	= 0,
		.cad_id	= 0,
		.path	= 0,
		.rate   = 8000,
		.dir	= 0,
		.codec	= Q6_CODEC_NONE,
		.hw	= 0,
	},
};

