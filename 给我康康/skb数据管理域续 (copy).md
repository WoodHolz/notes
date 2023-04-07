![image-20220925001346291](image-20220925001346291.png)

![image-20220925002233037](image-20220925002233037.png)

![image-20220925002654409](image-20220925002654409.png)

![image-20220925002544338](image-20220925002544338.png)

![image-20220925103140391](image-20220925103140391.png)

```c
#! /usr/bin/env bpftrace
BEGIN{
    printf("||   comm    |     strtime     |   runtime   ||\n");
    }
kprobe:__alloc_skb{
    if(comm == "Xwayland"){
        @strtime = nsecs;
        printf("|| %s | %s |", comm, strftime("%H:%M:%S", @strtime));
    }
}

kretprobe:__alloc_skb
/@strtime/ 
{
    if(comm == "Xwayland"){
        //@runtime = nsecs - @strtime;
        printf(" %-8d ||\n", nsecs - @strtime);
        @hist = lhist(nsecs - @strtime, 0, 200000, 5000);
        clear(@strtime);
    }
}

```

![image-20220925104054862](image-20220925104054862.png)

![image-20220925111404855](image-20220925111404855.png)