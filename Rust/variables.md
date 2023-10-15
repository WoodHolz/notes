跟着`rustlings`的练习学习rust

``` rust
// variables1.rs
fn main() {
    let x = 5; 
    println!("x has the value {}", x);
}
```

* `let`，声明变量关键词
* 输出的变量位用`{}`表示

``` rust
// variables4.rs
fn main() {
    let mut x = 3;
    println!("Number {}", x);
    x = 5; // don't change this line
    println!("Number {}", x);
}
```

* `mut`关键字搭配`let`代表声明**可变变量**

``` rust
// variables5.rs
fn main() {
    let number = "T-H-R-E-E"; // don't change this line
    println!("Spell a Number : {}", number);
    let number: i32 = 3; // don't rename this variable
    println!("Number plus two is : {}", number + 2);
}
```

* `let`声明的变量后面加`:i32`表示该变量的类型
* 注意，这段代码会导致变量`number`被多次声明。实际上，第二个`let`语句覆盖了第一个`let`语句中的变量`number`，并将其重新声明为具有类型`i32`的新变量。在Rust中，同一作用域内的变量名必须唯一，并且变量名与其类型是紧密关联的。因此，不能在同一作用域中声明具有相同名称但不同类型的变量。

``` rust
// variables6.rs
const NUMBER: i32 = 3;
fn main() {
    println!("Number {}", NUMBER);
}
```

* 声明常量要加上类型