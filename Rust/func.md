``` rust
// functions3.rs
fn main() {
    call_me(10);
}

fn call_me(num: u32) {
    for i in 0..num {
        println!("Ring! Call number {}", i + 1);
    }
}
```

* 函数的变量需要表明类型

``` rust
// functions4.rs
fn main() {
    let original_price = 51;
    println!("Your sale price is {}", sale_price(original_price));
}

fn sale_price(price: i32) -> i32{
    if is_even(price) {
        price - 10
    } 
    else {
        price - 3
    }
}

fn is_even(num: i32) -> bool {
    num % 2 == 0
}
```

* 函数如果有返回值，其类型需要在声明函数时就表明清楚。如下例：

``` rust
fn sale_price(price: i32) -> i32{/**/}
```

* `bool`代表函数的返回值为`True`/`False`

``` rust
// functions5.rs
fn main() {
    let answer = square(3);
    println!("The square of 3 is {}", answer);
}

fn square(num: i32) -> i32 {
    return num * num;
}
```

* `return`，函数返回值需要赋值给其他变量的时候用到~~平时都用上好像也不会报错，但是区分出需不需要这个应该对安全有利~~