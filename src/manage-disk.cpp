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
  std::string disk1_command = "mount " + disk1_path + " " + disk1_mount;
  std::string disk2_command = "mount " + disk2_path + " " + disk2_mount;
  std::string disk3_command = "mount " + disk3_path + " " + disk3_mount;
  std::string disk4_command = "mount " + disk4_path + " " + disk4_mount;
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

int safe_exit() {
  std::system("sync"); // syncing and unmounting everything to prevent unintentional writes
  std::string disk1_umountc = "umount -l " + disk1_path; // these are raw commands that will be converted into dskXu that will be checked if it failed
  std::string disk2_umountc = "umount -l " + disk2_path; // the abstract variable names like dsk1u literally mean dsk = disk 1 = drive number u = unmount
  std::string disk3_umountc = "umount -l " + disk3_path; // readable var = string; abstract = system command
  std::string disk4_umountc = "umount -l " + disk4_path;
  std::cout << "[ok] unmounting disks..." << std::endl;
  int dsk1u = std::system(disk1_umountc.c_str());
  if (dsk1u != 0) {
    throw std::runtime_error("Disk 1 unmount failed, please unmount manually");
  }
  int dsk2u = std::system(disk2_umountc.c_str());
  if (dsk2u != 0) {
    throw std::runtime_error("Disk 2 unmount failed, please unmount manually");
  }
  int dsk3u = std::system(disk3_umountc.c_str());
  if (dsk3u != 0) {
    throw std::runtime_error("Disk 3 unmount failed, please unmount manually");
  }
  int dsk4u = std::system(disk4_umountc.c_str());
  if (dsk4u != 0) {
    throw std::runtime_error("Disk 4 unmount failed, please unmount manually");
  }
  return 0; // the reason that it doesnt exit if theres an error because it attempts to unmount the disks if they are saveable
}

int partition_disk() {
part_disk_begin:
        char yesnoin;
        int disk_to_part; // 1-4
        std::string disk_to_parts; // path in string
        specify:
        std::cout << "please specify a disk from 1-4 ";
        std::cin >> disk_to_part;
        switch(disk_to_part) {
          case 1:
            disk_to_parts = disk1_path;
            break;
          case 2:
            disk_to_parts = disk2_path;
            break;
          case 3:
            disk_to_parts = disk3_path;
            break;
          case 4:
            disk_to_parts = disk4_path;
            break;
          default:
            goto specify;
            break;
        }
        std::string cfdisk_command = "cfdisk " + disk_to_parts;
        std::cout << "[ok] calling cfdisk on " << disk_to_parts << std::endl;
        std::system(cfdisk_command.c_str());
        std::cout << "would you like to partition another disk?" << std::endl;
        std::cin >> yesnoin;
        switch(yesnoin) {
          case 'y':
            goto part_disk_begin;
            break;
          case 'n':
            break;
        }
        return 0;
}

int format_disks() {
  char yesnoin;
  int format;
  std::cout << "format disks?(DESTROYS DATA!!!) y/n";
  std::cin >> yesnoin;
  switch(yesnoin) {
    case 'y':
      int format;
      format_start:
      std::cout << "[info] all disks will be formatted the same" << std::endl;
      std::cout << "please specify format number: 1. ext4; 2. vfat;" << std::endl;
      std::cin >> format;
      std::string disk1_format_ext4 = "mkfs.ext4 " + disk1_path; // declaring the commands, same with the string names as before
      std::string disk2_format_ext4 = "mkfs.ext4 " + disk2_path;
      std::string disk3_format_ext4 = "mkfs.ext4 " + disk3_path;
      std::string disk4_format_ext4 = "mkfs.ext4 " + disk4_path;
      std::string disk1_format_vfat = "mkfs.vfat " + disk1_path;
      std::string disk2_format_vfat = "mkfs.vfat " + disk2_path;
      std::string disk3_format_vfat = "mkfs.vfat " + disk3_path;
      std::string disk4_format_vfat = "mkfs.vfat " + disk4_path;
      switch(format) {
        case 1: {
          std::cout << "[ok] formatting all disks specified as ext4" << std::endl;
          int dsk1ext4 = std::system(disk1_format_ext4.c_str());
          if (dsk1ext4 != 0) {
            throw std::runtime_error("Failed formatting disk 1 as ext4");
          }
          int dsk2ext4 = std::system(disk2_format_ext4.c_str());
          if (dsk2ext4 != 0) {
            throw std::runtime_error("Failed formatting disk 2 as ext4");
          }
          int dsk3ext4 = std::system(disk3_format_ext4.c_str());
          if (dsk3ext4 != 0) {
            throw std::runtime_error("Failed formatting disk 3 as ext4");
          }
          int dsk4ext4 = std::system(disk4_format_ext4.c_str());
          if (dsk4ext4 != 0) {
            throw std::runtime_error("Failed formatting disk 4 as ext4");
          }
          break;
        }
        case 2: {
          std::cout << "[ok] formatting all disks specified as vfat" << std::endl;
          int dsk1vfat = std::system(disk1_format_vfat.c_str());
          if (dsk1vfat != 0) {
            throw std::runtime_error("Failed formatting disk 1 as vfat");
          }
          int dsk2vfat = std::system(disk2_format_vfat.c_str());
          if (dsk2vfat != 0) {
            throw std::runtime_error("Failed formatting disk 2 as vfat");
          }
          int dsk3vfat = std::system(disk3_format_vfat.c_str());
          if (dsk3vfat != 0) {
            throw std::runtime_error("Failed formatting disk 3 as vfat");
          }
          int dsk4vfat = std::system(disk4_format_vfat.c_str());
          if (dsk4vfat != 0) {
            throw std::runtime_error("Failed formatting disk 4 as vfat");
          }
          break;
        }
        default:
          std::cout << "[error] filesystem not found" << std::endl;
          goto format_start;
        
      }

  }
  return 0;
}

int show_disks() { // prints the disks before beginning the dangerous stuff
  std::cout << "[info] disks from lsblk:" << std::endl;
  std::system("lsblk");
  return 0;
}
