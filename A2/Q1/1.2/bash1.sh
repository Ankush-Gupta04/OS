#!/bin/sh
mkdir a1
cd a1
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.8.tar.xz
tar -xvJf linux-5.19.8.tar.xz
cd linux-5.19.8
wget https://raw.githubusercontent.com/gopi487krishna/ArtixConfig/main/config-rev-9-gold
cp config-rev-9-gold .config
make menuconfig 
make -j4