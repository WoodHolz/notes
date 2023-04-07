# uCore 和 rCore的阅读笔记

## 应用程序与基本执行环境

系统的链接脚本(kernel.ld)决定了elf程序的内存地址的虚拟映射，__程序中的绝对地址在链接时确定__。我们需要把系统放置在物理地址0x80200000处，需要进行这步操作的原因是在这个运行时刚进入S态，并没有激活虚存机制。~~我还不知道为什么是这个地址~~。

啊啊啊啊啊啊啊啊啊啊啊啊汇编好难难难难难难难难难难啊啊啊啊啊啊啊啊啊啊啊

### entry.s

``` assembly
    .section .text.entry #在下一个新的部分结束，即.section .bss.stack
    .globl _entry #声明全局符号_entry
_entry:
    la sp, boot_stack_top # (sp) = (boot_stack_top)
    call main # 调用main函数，进入Cの世界 ^_^

    .section .bss.stack
    .globl boot_stack
boot_stack:
    .space 4096 * 16 # 2^16B == 4KB * 16 == 64KB
    				 # 定义堆栈空间大小需要满足大小是4KB的整数倍。
    .globl boot_stack_top
boot_stack_top:

```

这是chatgpt的回答

> 这是一个汇编语言源文件，可以作为可执行程序的启动代码。下面是逐行解释： 
>
> 1. `.section .text.entry`: 这行代码表示将下面的代码放置在名为 ".text.entry" 的代码段中。 
> 2. `.globl _entry`: 这行代码定义了一个全局符号 "_entry"，该符号是程序的入口点，在程序启动时执行。 
> 3.  `_entry:`: 这行代码是 _entry 符号的标签，代表程序的入口点。 
> 4.  `la sp, boot_stack_top`: 这行代码使用 la 命令生成代码，将 boot_stack_top 符号的地址加载到 sp 寄存器中，将栈指针设置为堆栈的顶部。 
> 5.  `call main`: 这行代码通过 call 指令调用名为 "main" 的函数。 
> 6.  `.section .bss.stack`: 这行代码将下面的代码放置在名为 ".bss.stack" 的未初始化数据段中。 
> 7.  `.globl boot_stack`: 这行代码定义了一个全局符号 "boot_stack"，用于表示堆栈的起始位置。 
> 8. `boot_stack:`: 这行代码是 boot_stack 符号的标签，表示变量存储在此处。 
> 9.  `.space 4096 * 16`: 这行代码使用 space 命令在内存中分配 4096 * 16 字节的空间。这是堆栈的空间大小。 
> 10.  `.globl boot_stack_top`: 这行代码定义了一个全局符号 "boot_stack_top"，该符号用于表示堆栈的顶部位置，即栈指针初始值。 
> 11.  `boot_stack_top:`: 这行代码是 boot_stack_top 符号的标签，表示指针存储在此处。

#### 小知识点

* `.globl`是什么？

`.globl`指示符表示一个全局符号/标签；例：`.globl _entry`: 这行代码定义了一个全局符号 "_entry"

* 以下代码中`la`是什么意思？

``` assembly
la sp, boot_stack_top # (sp) = (boot_stack_top)
```

"la"是RISC-V指令集中的一个伪指令(pseudo-instruction），它的全称为“load address”，通常用于将地址加载到寄存器中。

下面是"la"伪指令的语法格式：

```assembly
la rd, symbol
```

其中，"rd"表示目标寄存器，"symbol"表示要加载的地址符号。

例如，下面的代码将符号"array"的地址加载到寄存器x1中：

```assembly
la x1, array
```

当汇编器处理这个伪指令时，它将使用类似于以下实际指令的指令序列来替代它：

```assembly
auipc x1, %pcrel_hi(array)
addi x1, x1, %pcrel_lo(array)
```

这个指令序列使用了两个新的伪指令：%pcrel_hi和%pcrel_lo。这两个伪指令用于计算符号的高位和低位偏移，在这个例子中，将符号"array"的地址作为立即数加载到寄存器x1中。
