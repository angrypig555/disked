#!/bin/sh
# fake disk generating software, use at own risk as sudo
#
set -e 

echo "LAST CHANCE TO EXIT, MAKE SURE LOOP1-4 IS AVAILABLE, CONTIUNING IN 3 seconds"
sleep 3

echo "Creating disk images..."
dd if=/dev/zero of=disk1.img bs=500M count=0 seek=1 
dd if=/dev/zero of=disk2.img bs=500M count=0 seek=1 
dd if=/dev/zero of=disk3.img bs=500M count=0 seek=1 
dd if=/dev/zero of=disk4.img bs=500M count=0 seek=1 

echo "setting up loop device..."

losetup --find --show disk1.img 
losetup --find --show disk2.img 
losetup --find --show disk3.img 
losetup --find --show disk4.img 

lsblk

echo "please partition and format these disks as you wish."
echo "done, exiting..."
