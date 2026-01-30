// disked backend interface, for debugging
// see LICENSE for more license information
// under the MIT license, c 2026 angrypig555

#include<iostream>
#include<filesystem>
#include"manage-disk.hpp"

int main() {
    std::cout << "WARNING: THIS PROGRAM IS MEANT TO RUN AS ROOT / SUDO DUE TO INTERFACING WITH DISKS, IF NOT THINGS WILL BREAK!!!" << std::endl; // this is actually important, please run this as sudo or root

    std::string diskpath;
    std::cout << "hello from disked backend interface" << std::endl;
    std::cout << "please enter path to disk 1: ";
    std::cin >> diskpath;
    store_path(diskpath, 1);
    try {
      mount_disk(diskpath, 1); // placeholder for testing
    } catch (const std::filesystem::filesystem_error& error) { // catches error if not root or sudo
      std::cout << "[critical] filesystem error, are you running as sudo or root? "<< error.what() << std::endl;
      return 1;
    }
}
