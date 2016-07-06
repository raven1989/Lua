package.cpath=package.cpath .. ";../lib64/libMandarin.so"

local dy = require "libMandarin"
local res1 = dy.getFreqInSogouDic("服装店")
print(res1)
local res2 = dy.getFreqInSogouDic("服装店")
print(res2)
local res3 = dy.getFreqInSogouDic("服装")
print(res3)

print(dy.getSogouDicSize())

function toBytes(unicode)
  for i=1, string.len(unicode) do
    local unibyte = string.byte(unicode,i)
    print(string.format("%02x",unibyte))
  end
end


print(dy.getFreqInSogouDic("板阀"))

toBytes("板阀")

print(dy.getBagAt(34))
print(dy.getIdfAt(34))

print(dy.getBagIdfSize())
print(dy.getTagVectorSize())
print(dy.getOneVectorSize())

print(dy.getAbsVectorAt(0))
print(dy.getTagAt(8))

local vec = 0
for i=0, dy.getTagVectorSize()-1 do
  for j=0, dy.getOneVectorSize()-1 do
    vec = vec + dy.getVectorAt(i,j)
  end
end
print(vec)

