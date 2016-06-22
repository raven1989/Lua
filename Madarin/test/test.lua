package.cpath="../lib64/libMadarin.so"
local dy = require "libMadarin"
local res1 = dy.getFreqInSogouDicByUnicodeWord("服装店")
print(res1)
local res2 = dy.getFreqInSogouDicByUtf8Word("服装店")
print(res2)
local res3 = dy.getFreqInSogouDicByUtf8Word("服装")
print(res3)
