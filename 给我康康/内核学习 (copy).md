# `struct net_device`——内核链路层与上层网络协议栈的接口

`net_rx`  `skb`  `dev.c`中`netif_rx`

​	设备独立接口文件



`hard_start_xmit` 函数指针

```c
#! /usr/bin/env/bpftrace
BEGIN{
printf("hello ksoftirqd!\n");
}

kprobe: * hard_start_xmit
{
    if(comm == "ksoftirqd/0"){
    @counter[0] = count();
    @get_time[0] = nsecs;
    }
    else if(comm == "ksoftirqd/1"){
    @counter[1] = count();
    @get_time[1] = nsecs;
    }
}

kretprobe:* hard_start_xmit
/@get_time[0] || @get_time[1]/ 
{
    if(comm == "ksoftirqd/0"){
        @runtime_0 = nsecs - @get_time[0];
        printf("cpu:%d %d: %d\n", cpu, tid,  @runtime_0);
        clear(@get_time);
    }
    else if(comm == "ksoftirqd/1"){
        @runtime_1 = nsecs - @get_time[1];
        printf("cpu:%d %d: %d\n", cpu, tid,  @runtime_1);
        clear(@get_time);
    }
}

```



![image-20221008224349584](image-20221008224349584.png)