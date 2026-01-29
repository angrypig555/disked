#include<iostream>
#include"manage-disk.hpp"

int main() {
    std::cout << "WARNING: THIS PROGRAM IS MEANT TO RUN AS ROOT / SUDO DUE TO INTERFACING WITH DISKS, IF NOT THINGS WILL BREAK!!!" << std::endl;

    char diskpath[50];
    std::cout << "hello from disked backend interface" << std::endl;
    std::cout << "please enter path to disk 1: ";
    std::cin >> diskpath;
    store_path(diskpath, 1);
}