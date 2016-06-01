#!/usr/local/bin/lua

my = {}
my[1] = "Lua"
mine = my
my = nil
print(mine[1])

print('---------------------------------------------------')
fruits = {"banana","orange","apple"}
print("连接后的字符串 ",table.concat(fruits))
print("连接后的字符串 ",table.concat(fruits,", "))
print("连接后的字符串 ",table.concat(fruits,", ", 2,3))

table.insert(fruits, "mango")
table.insert(fruits,2,"grapes")
for k,v in ipairs(fruits) do
    print(k,v)
end
table.remove(fruits)
for k,v in ipairs(fruits) do
    print(k,v)
end

table.sort(fruits)
print("排序后")
for k,v in ipairs(fruits) do
    print(k,v)
end
