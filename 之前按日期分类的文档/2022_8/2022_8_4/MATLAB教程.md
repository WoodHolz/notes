# MATLAB教程

```matlab
>> 公式(函数)
```

示例

```matlab
>> B = hilb(3)
```

max(`A`)

* 如果 `A` 是向量，则 `max(A)` 返回 `A` 的最大值。
* 如果 `A` 为矩阵，则 `max(A)` 是包含每一列的最大值的行向量。
* 如果 `A` 是多维数组，则 `max(A)` 沿大小不等于 `1` 的第一个数组维度计算，并将这些元素视为向量。此维度的大小将变为 `1`，而所有其他维度的大小保持不变。如果 `A` 是第一个维度长度为零的空数组，则 `max(A)` 返回与 `A` 大小相同的空数组。

max(B,[],2)

如果 `B` 为矩阵，则 `max(B,[],2)` 是每个矩阵行中的最大元素。

find(max(B,[],2))

找到每个矩阵行中的最大元素的最大值。

```matlab
>> B(B>0.25)=3
```

triu()

```matlab
U = triu(B) 返回矩阵B的[上三角]部分
```

tril()

> 矩阵的下三角部分

syms 

quad()

vpa()

subs()

plot()

## 曲线

## 曲面

示例

```matlab
>> [X,Y] = meshgrid(1:0.5:10,1:20);
>> Z = sin(X) + cos(Y);
>> surf(X,Y,Z)
```

## 线性插值

## 拟合

### 简单线性回归

示例

```matlab
x = 1:50; 
y = -0.3*x + 2*randn(1,50); 
p = polyfit(x,y,1);
```

```matlab
f = polyval(p,x); 
plot(x,y,'o',x,f,'-') 
legend('data','linear fit') 
```

