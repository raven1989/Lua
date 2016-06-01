#!/usr/local/bin/lua

a = "hello" .. "world"
print(a)

a, b = 10, 2*8
print(a,b)

a, b = b, a
print(a,b)

a, b, c = 0, 1
print(a, b, c)

a, b = a+1, b+1, b+2
print(a,b)

site = {}
site["key"] = "www.renren.com"
print(site["key"])
--索引位字符串时一种语法糖
print(site.key)
