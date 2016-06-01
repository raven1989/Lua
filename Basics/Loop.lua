#!/usr/local/bin/lua

a=10
while( a<20 ) do
  print("a:"..a)
  a = a+1
end

function doubleIt(x)
  return x*2
end

print('-----------------------------------')
for i=1, doubleIt(3) do
  print(i)
end

print('-----------------------------------')
for i=10, 1, -1 do
  print(i)
end

print('-----------------------------------')
days = {"Suanday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}
for i,v in ipairs(days) do  print(v) end

print('-----------------------------------')
a = 10
repeat
  print("a:", a)
  a = a+1
until( a>15 )
