# 常规数据域

* `ktime_ttstamp`



# 额外的知识点

经常碰到`__u8` ,`__u32`这些

`u8`,`u32`是什么 

>  都是C的数据类型；其中u8是unsigned char，u16是unsigned short，u32是unsigned long。

`__u8`和`u8`等的区别

**本质**上一样，只是`__un`是`linux`系统的特殊定义(其早于C99标准)，无可移植性[^1]。



---



[^1]: https://stackoverflow.com/questions/16232557/difference-between-u8-and-uint8-t

