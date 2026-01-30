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
    std::cout << "[ok] disked mount found at /mnt/disked/" << std::endl;
  } else {
    std::cout << "[warn] disked mount not found, creating at /mnt/disked/" << std::endl;
    std::filesystem::create_directory("/mnt/disked/");
  } // finds if the /mnt/disked/ exists, this is needed so theres a path to  mount the disks
  // creates the mounts for all the disks if they dont exist 
  
  if (std::filesystem::exists(disk1_mount) && std::filesystem::is_directory(disk1_mount)) {
    std::cout << "[ok] disk1 mount found at /mnt/disked/d1/" << std::endl;
  } else {
    std::cout << "[warn] disk1 mount not found, creating at /mnt/disked/d1/" << std::endl;
    std::filesystem::create_directory("/mnt/disked/d1/");
  }

  if (std::filesystem::exists(disk2_mount) && std::filesystem::is_directory(disk2_mount)) {
    std::cout << "[ok] disk2 mount found at /mnt/disked/d2/" << std::endl;
  } else {
    std::cout << "[warn] disk2 mount not found, creating at /mnt/disked/d2/" << std::endl;
    std::filesystem::create_directory("/mnt/disked/d2/");
  }

  if (std::filesystem::exists(disk3_mount) && std::filesystem::is_directory(disk3_mount)) {
    std::cout << "[ok] disk3 mount found at /mnt/disked/d3/" << std::endl;
  } else {
    std::cout << "[warn] disk3 mount not found, creating at /mnt/disked/d3/" << std::endl;
    std::filesystem::create_directory("/mnt/disked/d3/");
  }

  if (std::filesystem::exists(disk4_mount) && std::filesystem::is_directory(disk4_mount)) {
    std::cout << "[ok] disk4 mount found at /mnt/disked/d4/" << std::endl;
  } else {
    std::cout << "[warn] disk4 mount not found, creating at /mnt/disked/d4/" << std::endl;
    std::filesystem::create_directory("/mnt/disked/d4/");
  }
  return 0;
}
