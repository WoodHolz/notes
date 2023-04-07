## 来不及了来不及了.JPG

### 前面监测了函数的参数,想看看函数的返回值是否满足预期以确定函数的编写是否正确

``` C
#include<stdio.h>
int add(int a, int b)
    {
        return a + b;
    }
int main()
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("\n%d\n", add(a, b));
        return 0;
    }
```

bpftrace写为:
> bpftrace -e 'uprobe:./exp1:add {@arg0 = arg0; @arg1 = arg1;} uretprobe:./exp1:add {@re = retval;}'

retval: Return value from traced function

在使用**tracepoint**或**kfunc probes retval**时可以替换retval为args->ret()

结果图

![结果图](4.png)

![结果图](3.png)

### 采用bpftrace脚本的方式,检测程序某函数的运行时间

程序见附件student.c

bpftrace脚本程序

``` stutrace.bt
#!/usr/bin/env bpftrace
//#!/usr/local/bin/bpftrace

BEGIN
{
    printf("检测管理系统creat()函数的运行时间\n");
}
uprobe:./student:creat
{
    printf("\n开始\n");
    @start=nsecs;
    printf("pid: %ld, 开始时间:%s\t", pid, strftime("%H:%M:%S", @start));
}
uretprobe:./student:creat
/@start/
{
    @endtime=nsecs;
    @cost=@endtime-@start;
    printf("结束时间:%s, 运行时间: %ldms\n", strftime("%H:%M:%S", @endtime), (@endtime-@start) / 1000000);
    /*为使开始和结束时间显示更加直观,使用strftime()将获取的时间转换为时刻的格式.
      nsecs是以纳秒为单位的时间戳,因此在显示运行时间时将其转化为毫秒输出.
    */
    delete(@start);
}
END 
{
    printf("\n检测结束\n");
}
```

结果图

![结果图](2.png)

![结果图](1.png)

## 捕捉非正常终止的程序的函数参数

``` C
#include<stdio.h>
#include<unistd.h>
int test(const char * str)
    {
        printf("%s\n", str);
        return 0;
    }

int main()
    {
        char * p = NULL;
        test("this is a string.");
        *p = '1';
        sleep(10000);
        return 0;
    }
```

>bpftrace -e 'uprobe:./exp1:test{printf("%s\n", str(arg0))}'
>  
> 结果不理想。。。。

### 对bpftrace的初体悟

在基本熟悉bpftrace的相关语法使用以后,发现bpftrace相对于BCC是非常轻量级的,自己和网上的各种运用的案例代码量都很小,并且其提供了不少基础工具,因此,使用者可以根据实际的场景利用基础工具快速编写自己的bpf工具,并且可以保持被检测程序/进程/环境的运行从而较低成本地找到并解决问题;bpftrace作为一个性能检测和故障检测手段,对她的使用非常依赖于**需求分析**,非常考验使用者对要观测的进程/程序的运行过程的理解,根据使用情况选定适合的探针，并对返回数据进行分析和处理,这些工作实际占了运用ebpf的大头.而在自己的学习和项目过程中，更多的是通过这种工具去学习linux内核，去深入认识子系统不同层级的工作流程.

更进一步的数据可视化的实现,认为需要用到BCC和python,bpftrace过于简单可能难以实现.(bptrace的直方图？？？？？)

综上,我认为自己的编程和项目瓶颈在对***linux系统编程*** 和对***网络基础*** 的知识欠缺.

## 参考资料

<https://github.com/iovisor/bpftrace/blob/master/docs/reference_guide.md>

<https://ebpf.io/what-is-ebpf#maps>
