## bpftrace脚本格式

// 这些换行不是必须的

/***采用与 C 语言类似的注释***/

BEGIN{

  // 开始时执行一次的代码

}

probe/filter/ {

  // 事件与 prob 和 filter 匹配时执行（uprobe和kprobe）

}

END{

  // 结束时执行一次

}



bpf工具因为需要调用linux内核的相关内容，因此使用bpf时需要sudo或者开启root用户***（有例外，可以调用特定参数避免进入验证器，进而避开内核态而直接到用户态）***



## 实例一：Hello,world!

sudo bpftrace -e 'BEGIN{printf("Hello, World!\n");}END{printf("Bye, World!\n")}'



在pbftrace执行开始时打印Hello,World!\n  按ctrl+c推出结束时执行打印Bye,World!\n 

![img](D:\note\2022_7\2022_7_16\KQZOIAQAR4.png)



## 实例二：返回进程最近的检测值

bpftrace -e 'kprobe: vfs_read {@ID = pid;}'

@ID=pid是定义一个变量，其名为ID, 将检测的进程号赋值给变量ID

***补充：相对于传统工具,以cat为例，cat最快只能捕捉到秒，但bpf的频率可以在目标每次运行时进行捕捉检测***



## 实例三：按使用者规定的时间周期反复返回检测的值

> bpftrace -e 'kprobe: vfs_read {@ID = pid;} interval:s:2 {printf("ID:%d\n", @ID);}' 

//在根用户模式下， 否则请在语句最前方补上sudo

![img](D:\note\2022_7\2022_7_16\OQZ6IAQAVQ.png)



vfs_read是内核中文件的读取操作，这里打入探针检测其进程

interval是bpftrace内置的的CPU单核探针，其会在使用者设定的时间周期不断被触发。格式为interval:[时间单位]:[时间数] {触发执行的内容}

s:2 其中s为时间单位; 这里设置时间周期为2秒

这里interval的触发执行的内容为printf("ID:%d\n", pid);



## 实例四：返回vfs_read进程运行的时间

> bpftrace -e 'kprobe: vfs_read {@str[pid] = nsecs} kretprobe:vfs_read {@time[comm] = nsecs - @str[pid]; delete(@str[pid])}' //问题语句



bpftrace -e 'kprobe: vfs_read {@str[pid] = nsecs} kretprobe:vfs_read /@str[pid]/ {@time[comm] = nsecs - @str[pid]; delete(@str[pid])}'//正确语句

![img](D:\note\2022_7\2022_7_16\3QZ6IAQAAA.png)



nsecs是内置的变量，其可获取系统时间

kretprobe是在进程结束时返回检测值

delete删除@str[pid]的内容，因为并没有在打印后被删除

我的问题:学长在讲这个的时候把它说为数组，那看作数组的话，数组下标为进程号，不断改变，可以不删除吗？

如果不删除，当其下一次执行的时候，pid进程号并没有被删除或覆盖，会出现错误赋值给之前检测返回的start数组元素。



为什么正确语句要在kretprobe加/@str[pid]/的限定条件/筛选器/判断条件？

因为有可能在打入探针时vfs_read进程已经开始，在这种情况下只能获取到进程结束时的系统时间，而导致显示的运行时间有误。所以加入限定条件只在打入探针并获取到内核读取文件进程开始的系统时间后才执行后面的语句。

***\*这里还要注意筛选器放置的位置，只能放置在要在筛选后进行的探针之后，该探针执行内容之前。\****



## 实例五：检测用户态程序的函数参数

程序：

![img](D:\note\2022_7\2022_7_16\BMT6IAQAPY.png)

结果

![img](D:\note\2022_7\2022_7_16\VITOIAQAIA.png)

这里检测使用用户态的探针，注意程序调用可以使用绝对地址和间接地址(但需要在同一目录下)，路径不能包含中文字符。

![img](D:\note\2022_7\2022_7_16\IAV6IAQA4Y.png)





## 后面的想法

沿用学长的方法，先接触相关传统工具，了解其过程，再通过bpf实现，了解二者异同。

选用的传统工具：pktstat、iptraf

![img](D:\note\2022_7\2022_7_16\SYYOIAQAKM.png)