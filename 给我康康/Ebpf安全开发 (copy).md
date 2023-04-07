## Linux内核树源码编译

安装依赖

```bash
sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison binutils-dev libcap-dev libreadline-dev pahole -y
```

查看可用的源码版本

```bash
apt-cache search linux-source 
```

安装

```bash
# 复制配置文件
sudo cp /boot/config-$(uname -r) /usr/src/linux-source-5.15.0/linux-source-5.15.0/.config
cd linux-source-5.15.0/

# 如果需要修改配置
make menuconfig

# 复制签名
sudo cp -R ../debian .
sudo cp -R ../debian.master .
# 多线程编译
sudo make -j 8 modules
sudo make -C samples/bpf
sudo make modules_install
sudo make -j 8
sudo make install

# 安装启动项
sudo update-initramfs -c -k 5.15.60
sudo update-grub

# 卸载启动项：
sudo update-initramfs -d -k 5.15.60
sudo rm -rf /boot/*5.15.60*
sudo update-grub

dpkg --get-selections|grep linux
sudo apt-get remove linux-headers-5.15.0-43-generic linux-image-5.15.0-43-generic
sudo apt autoremove
```



## Linux内核tools子模块编译

进入linux-source目录下的tools文件夹直接make



## Linux跟踪文件系统

### Linux跟踪技术

* TRACEFS
* Ftrace手动Uprobe Hook
* Ftrace手动Kprobe Hook
* Hook技术



```bash
# 查看tracefs的挂载
mount | grep tracefs

# 查看bugfs的挂载
mount | grep bugfs
```



之前总结的ebpf的uprobe/kprobe工作机制与是传统的hook机制相似

实际使用Hook时，需要知道目标函数的偏移量