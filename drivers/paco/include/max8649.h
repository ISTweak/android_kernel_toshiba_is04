/*
  max8649.h

  Copyright (C) 2010 TOSHIBA CORPORATION Mobile Communication Company.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*/
#ifndef __LINUX_I2C_MAX8649_H
#define __LINUX_I2C_MAX8649_H

#define MAX8649_MAX_DCDC2	1380	// move from board-tg03.c
#define MAX8649_MIN_DCDC2	750		// add

/* Set the output voltage for the DCDC2 convertor */
extern int max8649_set_dcdc2_level(int mvolts);

/* Read the output voltage from the DCDC2 convertor */
extern int max8649_get_dcdc2_level(int *mvolts);

#endif
