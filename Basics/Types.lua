#!/usr/local/bin/lua

print(type("Hello World"))
print(type(10.4*3))
print(type(print))
print(type(type))
print(type(true))
print(type(nil))
print(type(X))
print(type(type(X)))

tab1 = {key1="val1", key2="val2", "val3"}
print(type(tab1))

for k,v in pairs(tab1) do
  print(k.." - "..v)
end

--string
print("---------------string-----------------")
string1 = "this is string1"
print(string1)
html = [[
<html>
<head></head>
<body>
    <a href="http://www.w3cschool.cc/">w3cschool菜鸟教程</a>
</body>
</html>
]]
print(html)

print("2"+6)
print("-2e2"*"6")
--print("error"+1)

print('a'..'b')
print(157 .. 428)
print(type(157 .. 428))

print("html length : "..#html)

print("---------------table-----------------")
a = {}
a["key"] = "value"
key = 10
a[key] = 22
a[key] = a[key] + 11
for k,v in pairs(a) do
  print(k .. ":" .. v)
end

local tb2 = {"apple", 'pear', 'orange', 'grape'}
for k,v in pairs(tb2) do
  print("key", key, " : ", "value", v)
end

print("---------------function-----------------")
function factorial(n)
  if n==0 then
    return 1
  else
    return factorial(n-1)*n
  end
end
print(factorial(5))
f = factorial
print(f(5))
--匿名函数
function handler(tab, func)
  for k,v in pairs(tab) do
    print(func(k,v))
  end
end
tab3 = {key1="val1", key2="val2"}
handler(tab3, function(key,val) return key .. "=" .. val end)
