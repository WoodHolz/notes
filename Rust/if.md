``` rust
// if2.rs
pub fn foo_if_fizz(fizzish: &str) -> &str {
    if fizzish == "fizz" {
        "foo"
    } 
    else if fizzish == "fuzz" {
        "bar"
    } 
    else{
        "baz"
    }
}
```

* 分支结构开始结束用`{}`
* `if `、`else if`、`else`搭配分出多个分支

