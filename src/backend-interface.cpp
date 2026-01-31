// disked backend interface, for debugging
// see LICENSE for more license information
// under the MIT license, c 2026 angrypig555

#include<iostream>
#include<filesystem>
#include"manage-disk.hpp"

int main() {
    std::cout << "WARNING: THIS PROGRAM IS MEANT TO RUN AS ROOT / SUDO DUE TO INTERFACING WITH DISKS, IF NOT THINGS WILL BREAK!!!" << std::endl; // this is actually important, please run this as sudo or root

    std::string diskpath;
    char yesnoin;
    std::cout << "hello from disked backend interface" << std::endl;
    std::cout << "please note 4 disks are required, this will be removed later. if you dont have 4 disks run the disk.sh file to generate 1G ext4 img files at loop" << std::endl;
disk_entry:
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
    try {
      mount_disk(); // mounts the disks, found in manage-disk.cpp
    } catch (const std::filesystem::filesystem_error& error) { // catches error if not root or sudo
      std::cerr << "[critical] filesystem error, are you running as sudo or root? "<< error.what() << std::endl;
      return 1;
    } catch (const std::runtime_error& rerror) {
      std::cerr << "[critical] " << rerror.what() << std::endl;
      return 1;
    }
}
