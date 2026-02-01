// disked backend interface, for debugging
// see LICENSE for more license information
// under the MIT license, c 2026 angrypig555

#include<iostream>
#include<filesystem>
#include"manage-disk.hpp"

int main() {
    std::cout << "[warn] WARNING: THIS PROGRAM IS MEANT TO RUN AS ROOT / SUDO DUE TO INTERFACING WITH DISKS, IF NOT THINGS WILL BREAK!!!" << std::endl; // this is actually important, please run this as sudo or root

    std::string diskpath;
    char yesnoin;
    std::cout << "[caution] this is experimental software, whatever you tell it to do it will. double check paths, filesystems, partitions. there are no safeguards" << std::endl; // warning message
    std::cout << "[info] hello from disked backend interface" << std::endl;
    std::cout << "[warn] please note 4 disks are required, this will be removed later. if you dont have 4 disks run the disk.sh file to generate 1G ext4 img files at loop" << std::endl;
disk_entry:
    show_disks();
    std::cout << "please enter path to disk 1: ";
    std::cin >> diskpath;
    store_path(diskpath, 1);
    std::cout << "please enter path to disk 2: ";
    std::cin >> diskpath;
    store_path(diskpath, 2);
    std::cout << "please enter path to disk 3: ";
    std::cin >> diskpath;
    store_path(diskpath, 3);
    std::cout << "please enter path to disk 4: ";
    std::cin >> diskpath;
    store_path(diskpath, 4);
    std::cout << "confirm, is this correct?, disks will be mounted after this. last chance y/n " << std::endl;
    print_paths();
    std::cout << "y/n ";
    std::cin >> yesnoin;
    switch(yesnoin) {
      case 'y':
        break;
      case 'n':
        goto disk_entry;
        break;
      default:
        goto disk_entry;
        break;
    }
    std::cout << "would you like to partition any disks? y/n ";
    std::cin >> yesnoin;
    switch(yesnoin) {
      case 'y':
        partition_disk();
      default:
          break;
        
    }
    try {
      format_disks();
    } catch (const std::runtime_error& ferror) {
      std::cerr << "[critical] " << ferror.what() << std::endl;
      return 1;
    }
    try {
      mount_disk(); // mounts the disks, found in manage-disk.cpp
    } catch (const std::filesystem::filesystem_error& error) { // catches error if not root or sudo
      std::cerr << "[critical] filesystem error, are you running as sudo or root? "<< error.what() << std::endl;
      return 1;
    } catch (const std::runtime_error& rerror) {
      std::cerr << "[critical] " << rerror.what() << std::endl;
      return 1;
    }
    std::cout << "[ok] setup complete, press q to quit, program will continue running until stopped." << std::endl;
    std::cout << "[warn] only exit with 'q', do not ctrl+c unless absolutely necessary" << std::endl;
    int running = 1;
    while (running == 1) {
      char exitchar;
      std::cin >> exitchar;
      switch(exitchar) { // loop to keep the backend interface alive
        case 'q':
          running = 0;
          break;
        default:
          break;
      }
    }
    // exit
  exit:
    try {
      safe_exit();
    } catch (const std::runtime_error& eerror) {
      std::cerr << "[critical] " << eerror.what() << std::endl;
    }
}
