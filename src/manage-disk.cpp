#include<iostream>
#include"disks.hpp"
#include"manage-disk.hpp"

// manage-disk.c is for handling the disk status

int store_path(std::string path_to_disk, int drive) {
    switch(drive) {
        case 1:
            disk1_path = path_to_disk;
            return 0;
            break;
        case 2:
            disk2_path = path_to_disk;
            return 0;
            break;
        case 3:
            disk3_path = path_to_disk;
            return 0;
            break;
        case 4:
            disk4_path = path_to_disk;
            return 0;
            break;
        default:
            return 1;
            break;
    }
    return 0;
}