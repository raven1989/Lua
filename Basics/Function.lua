#!/usr/local/bin/lua

function average(...)
  local result = 0
  local arg = {...}
  for i,v in ipairs(arg) do
    result = result + v
  end
  return result/#arg
end

print(average(1,2,3,4,5,6))
