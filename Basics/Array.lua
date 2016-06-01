#!/usr/local/bin/lua

array = {"Lua", "Tutorial"}
for i=0, #array do
  print(array[i])
end

print('--------------------------------------')
array = {}
for i=-2, 2 do
  array[i] = i*2
end
for i=-2, 2 do
  print(array[i])
end

print('--------------------------------------')
for k,v in pairs(array) do
  print(k,v)
end

print('--------------------------------------')
array = {}
for row=1, 3 do
  array[row] = {}
  for col=1, 3 do
    array[row][col] = row*col
  end
end
for row=1, 3 do
  for col=1, 3 do
    print(array[row][col])
  end
end
