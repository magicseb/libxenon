/* modified for libxenon */

/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2002 by Björn Stenberg
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/
#ifndef _DISK_H_
#define _DISK_H_

#include <diskio/diskio.h>
#include <fat/fat_rb.h>

/////////////////////////////////////////////////////////////////////////////////////
// Begin libxenon edits
/////////////////////////////////////////////////////////////////////////////////////

#define NUM_VOLUMES_PER_DRIVE 1 // TODO: be able to mount more than 1 volume per drive

/////////////////////////////////////////////////////////////////////////////////////
// End libxenon edits
/////////////////////////////////////////////////////////////////////////////////////

struct partinfo {
    unsigned long start; /* first sector (LBA) */
    unsigned long size;  /* number of sectors */
    unsigned char type;
};

#define PARTITION_TYPE_FAT32                0x0b
#define PARTITION_TYPE_FAT32_LBA            0x0c
#define PARTITION_TYPE_FAT16                0x06
#define PARTITION_TYPE_OS2_HIDDEN_C_DRIVE   0x84

/* returns a pointer to an array of 8 partinfo structs */
struct partinfo* disk_init(IF_MD_NONVOID(int drive));
struct partinfo* disk_partinfo(int partition);
int disk_mount_all(void); /* returns the # of successful mounts */
int disk_mount(int drive, int volume);
int disk_unmount(int drive);

int storage_read_sectors(int drive, unsigned long start, int count, void* buf);
int storage_write_sectors(int drive, unsigned long start, int count, const void* buf);

#endif