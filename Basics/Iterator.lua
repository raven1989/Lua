#!/usr/local/bin/lua

--[[
--首先，初始化，计算in后面表达式的值，表达式应该返回范性for需要的三个值：迭代函数、状态常量、控制变量；与多值赋值一样，如果表达式返回的结果个数不足三个会自动用nil补足，多出部分会被忽略。
--第二，将状态常量和控制变量作为参数调用迭代函数（注意：对于for结构来说，状态常量没有用处，仅仅在初始化时获取他的值并传递给迭代函数）。
--第三，将迭代函数返回的值赋给变量列表。
--第四，如果返回的第一个值为nil循环结束，否则执行循环体。
--第五，回到第二步再次调用迭代函数
]]--
array = {"Lua", "Tutorial", [4] = "Manual"}
print('---------------------------------------------------')
--[[
--ipairs遍历从1开始严格递增到第一个整数key值为nil的元素
]]--
for k,v in ipairs(array) do
  print(k, v)
end
print('---------------------------------------------------')
--[[
--pairs遍历所有元素
]]--
for k,v in pairs(array) do
  print(k, v)
end

print('-------------------------无状态迭代器--------------------------')
--[[
--ipairs和pairs都返回3个值，迭代函数、状态常量、控制变量
--ipairs(t)返回 迭代函数，t, 0(当前索引)
--pairs(t)返回 迭代函数, t, nil
]]--

function square(len, cur)
  if cur<len then
    cur = cur + 1
    return cur, cur*cur
  end
end

for i,n in square, 3, 0 do
  print(i, n)
end

print('-------------------------多状态迭代器--------------------------')
function valueIterator(array)
  local index = 0
  local len = #array
  return function()
    index = index + 1
    if index <= len then
      return array[index]
    end
  end
end

for v in valueIterator(array) do
  print(v)
end
