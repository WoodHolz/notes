# 小白的WSL(Windows Subsystem for Linux)安装及配置备忘

## `WSL`是什么

顾名思义, `WSL`就是`Windows`系统下的`Linux`子系统

## 安装

### 第一步

请在键盘上按下`<Win> + <s>`键(<Win>就是键盘上的`田`字形状的按键)打开搜索, 并且在输入`启用或关闭Windows功能`打开, 如下图:

![image-20230919112447312](https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919112447312.png)

勾选___适用于Linux的Windows子系统___ 和 ___虚拟机平台___ 这两个选项 , 如下图, 点击确定退出, __需要重启电脑__

<img src="https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919113252966.png" alt="image-20230919113252966" style="zoom:150%;" />

### 第二步

请打开微软商店, 其在`Window`下的图标, 如下图

<img src="https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919113444075.png" alt="image-20230919113444075" style="zoom: 200%;" />

在微软商店中搜索`wsl`, 如下图

<img src="https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919113753512.png" alt="image-20230919113753512" style="zoom:50%;" />

选择`Ubuntu22.04`下载安装就好

同上搜索安装`Windows Terminal`

## 第三步 启动Windows Terminal

如果你在使用`Win10`操作系统, 请使用`<Win> + <r>`打开`运行`并输入`wt`, 如下图 ~~Win11用户也可以这样打开~~

![image-20230919114453600](https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919114453600.png)

`Win11`用户在`开始`菜单的`所有应用`中应该也找得到, 可以按下鼠标右键将其固定到`开始`菜单以方便启动

---

打开的`Windows Terminal`, 点击圈起来的图标, 如下图

![image-20230919114708127](https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919114708127.png)

如果前面的`Ubuntu`下载完成, 应该可以看到, 如下图

![image-20230919115348293](https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919115348293.png)

鼠标点击启动就好, 之后会终端中会显示: 设置用户名和密码, 注意输入密码时是不会显示出来的 

完成! 

![image-20230919120008403](https://cdn.jsdelivr.net/gh/WoodHolz/cloudimg/picture/image-20230919120008403.png)