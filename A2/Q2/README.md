Commands followed to be run in root:
1) mkdir A2_Q2 //create a folder
2) cd A2_Q2
3) wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.8.tar.xz  
4) tar -xvJf linux-5.19.8.tar.xz // untar the kernel
6)  cd linux-5.19.8
7)  cd kernel
8)  vim sys.c
![image](https://user-images.githubusercontent.com/100823564/202852818-b09ac4a9-308f-4726-a34e-8f8aaf0e4c79.png)
9) cd ..
10) cd arch/x86/entry/syscalls
11) vim syscall_64.tbl
 ++ 451 common  kernel_2d_memcpy  sys_kernel_2d_memcpy
12) cd .. // tab tak karo jab tak linux-5.19.8 aajaye xdd..
 patch -p0 < diff
13)  wget https://raw.githubusercontent.com/gopi487krishna/ArtixConfig/main/config-rev-9-gold
14)  cp config-rev-9-gold .config
15)  make menuconfig 
16)  make -j4
17)  make modules_install
18)  cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-linuxpatched
19)  mkinitcpio -k 5.19.8 -g /boot/initramfs-linuxpatched.img
20)  cp System.map /boot/System.map-linuxpatched
21)  cp /boot/System.map-linuxpatched System.map
22)  grub-mkconfig -o /boot/grub/grub.cfg
23)  reboot

finally commands hogyai xdd...

now testing time 
write a demo.c programme
run makefile
output: ![2022-11-19](https://user-images.githubusercontent.com/100823564/202853528-7cb52c5f-4878-4821-bc28-d315b9973775.png)

