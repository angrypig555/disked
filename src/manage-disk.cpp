#include<iostream>
#include<filesystem>
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

int mount_disk(std::string drive, int num) {
  std::string mnt_pathd = "/mnt/disked/";

  if (std::filesystem::exists(mnt_pathd) && std::filesystem::is_directory(mnt_pathd)) {
    std::cout << "[ok] disked mount found at /mnt/disked" << std::endl;
  } else {
    std::cout << "[warn] disked mount not found, creating at /mnt/disked/" << std::endl;
    std::filesystem::create_directory("/mnt/disked/");
  }
  return 0;
}
