#!/bin/sh
mkdir a2
cd a2
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.8.tar.xz
tar -xvJf linux-5.19.8.tar.xz
cd linux-5.19.8
wget https://raw.githubusercontent.com/gopi487krishna/ArtixConfig/main/config-rev-9-gold
cp config-rev-9-gold .config
make menuconfig 
make -j4
cd /home/ankush/os/temp/q1/final
ls
echo "deleting a2"
rm -r a2
