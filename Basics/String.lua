#!/usr/local/bin/lua

print(string.gsub("aaaa", "a", "z", 3))
print(string.find("Hello Lua user", "Lua", 1))
print(string.reverse("Lua"))
print(string.format("Lua format: %.2f",10.3))
print(string.char(97,98,99,100))
print(string.byte("ABCD"))
print(string.byte("ABCD", 4))
print(string.len("abc"))
print(string.rep("abcd", 2))
print(string.upper("lua"))
print(string.lower("LUA"))
date = 2; month = 1; year = 2014
print(string.format("日期格式化 %02d/%02d/%03d", date, month, year))
