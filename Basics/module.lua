#!/usr/local/bin/lua

module = {}

module.constant = "C"

function module.func1()
  io.write("共有函数\n")
end

local function func2()
  print("私有函数")
end

function module.func3()
  func2()
end

return module
