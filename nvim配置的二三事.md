# `nvchad`/`neovim`配置的二三事

## 配置安装`nvchad`

``` shell
# 删除之前的nvim配置, 如果是新安装`neovim`请忽略这一步
rm -rf ~/.config/nvim \ rm -rf ~/.local/share/nvim

# 安装`nvchad` 参照[nvchad官方](https://nvchad.com/docs/quickstart/install)
git clone https://github.com/NvChad/NvChad ~/.config/nvim --depth 1 && nvim
```



## 设置自动保存、取消自动注释、保存光标位置



https://zhuanlan.zhihu.com/p/557199534

https://github.com/askfiy/nvim/blob/master/lua/core/after/autocmd.lua

## vim plug install fatal

vim ~/.githubconfig 

> [http "https://github.com"]
>   proxy = socks5://127.0.0.1:7890
> [https "https://github.com"]
>   proxy = socks5://127.0.0.1:7890