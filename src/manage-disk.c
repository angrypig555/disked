#include<stdio.h>
#include"disks.h"

// manage-disk.c is for handling the disk status

int stire_path(char path_to_disk, int drive) {
    int psize = sizeof(path_to_disk);
    int* psize_point = &psize;
    switch(drive) {
        case 1:
            disk1_path[psize_point] = path_to_disk;
            printf(*psize_point);
    }
}