// manage-disk.cpp, disk managing interface, handling disks
// part of disked, under the MIT license
// see LICENSE for more information

#include<iostream>
#include<filesystem>
#include<cstdlib>
#include<stdexcept>
#include"disks.hpp"
#include"manage-disk.hpp"

// manage-disk.cpp is for handling the disk status

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

int print_paths() {
  // prints paths for confirmation
  std::cout << "disk 1: " << disk1_path << std::endl;
  std::cout << "disk 2: " << disk2_path << std::endl;
  std::cout << "disk 3: " << disk3_path << std::endl;
  std::cout << "disk 4: " << disk4_path << std::endl;
  return 0;
}

int mount_disk() {
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
  } // end of searching for mounts, now its mounting time
    //
  // defining the mnt command + where the device is 
  //
  std::cout << "[ok] calling mnt on disks..." << std::endl;
  std::string disk1_command = "mnt " + disk1_path + " " + disk1_mount;
  std::string disk2_command = "mnt " + disk2_path + " " + disk2_mount;
  std::string disk3_command = "mnt " + disk3_path + " " + disk3_mount;
  std::string disk4_command = "mnt " + disk4_path + " " + disk4_mount;
  // running the mounts
  int dsk1cmdr = std::system(disk1_command.c_str());
  if (dsk1cmdr != 0) {
    throw std::runtime_error("Disk 1 mount failed!!! Exiting to prevent damage...");
    return 1;
  }
  int dsk2cmdr = std::system(disk2_command.c_str());
  if (dsk2cmdr != 0) {
    throw std::runtime_error("Disk 2 mount failed!!! Exiting to prevent damage...");
    return 1;
  }
  int dsk3cmdr = std::system(disk3_command.c_str());
  if (dsk3cmdr != 0) {
    throw std::runtime_error("Disk 3 mount failed!!! Exiting to prevent damage...");
    return 1;
  }
  int dsk4cmdr = std::system(disk4_command.c_str());
  if (dsk4cmdr != 0) {
    throw std::runtime_error("Disk 4 mount failed!!! Exiting to prevent damage...");
    return 1;
  } // a LOT of error checking to not mess up stuff
  return 0;
}
