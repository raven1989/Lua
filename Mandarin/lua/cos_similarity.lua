package.cpath=package.cpath .. ";../lib64/libMandarin.so"
mandarin = require "libMandarin"

function luaAlgoGetTag(title)
  return makeTag(makeVector(mandarinSolveInUtf8(title)))
end

function countUtf8(utf8)
  local res = {}
  local cnt = 1
  local cur = 1
  local len = string.len(utf8)
  while(cur<=len) do 
    local h = string.byte(utf8, cur)
    if(h<0x80) then
      res[cnt] = cur
      cnt = cnt + 1
      cur = cur + 1
    elseif(h<0xc0) then
      cur = cur + 1
    elseif(h<0xe0) then
      res[cnt] = cur cnt = cnt + 1
      cur = cur + 2
    elseif(h<0xf0) then
      res[cnt] = cur
      cnt = cnt + 1
      cur = cur + 3
    else
      res[cnt] = cur
      cnt = cnt + 1
      cur = cur + 4
    end
  end
  return res,cnt-1
end

function mandarinSolveInUtf8(mstr)
  local wl, len = countUtf8(mstr)
  wl[len+1] = string.len(mstr)+1
  -- print(len)
  -- for i,v in ipairs(wl) do
    -- if(i<=len) then
      -- print(i,v,string.sub(mstr, v, wl[i+1]-1))
    -- end
  -- end
  local p = {}
  local t = {}
  for i=1, len do
    p[i] = 0
    t[i] = 1
  end
  p[len+1] = 1
  -- p[len+2] = 1
  for i=len, 1, -1 do
    for j=1, len-i+1 do
      local sstr = string.sub(mstr, wl[i], wl[i+j]-1)
      local freq = mandarin.getFreqInSogouDic(sstr)
      -- print(sstr, i, j, freq)
      if(j>1 and freq==1) then
      else
        local left = freq * p[i+j]
        local right = p[i]*mandarin.getSogouDicSize()
        if(left > right) then
          p[i] = left
          t[i] = j
        end
      end
    end
  end
  local res = {}
  local ri = 1
  local i = 1
  while(i<=len) do
    -- print(ri,i,t[i],wl[i],wl[i+t[i]]-1)
    local head = wl[i]
    local tail = wl[i+t[i]]-1
    if((tail-head)>0) then
      res[ri] = string.sub(mstr, head, tail)
      ri = ri + 1
    end
    i = i+t[i]
  end
  return res
end

function makeVector(words)
  local wmap = {}
  local vector = {}
  for i,v in ipairs(words) do
    if(wmap[v]==nil) then
      wmap[v] = 1
    else
      wmap[v] = wmap[v]+1
    end
  end
  for i=0, mandarin.getBagIdfSize()-1 do
    local word = mandarin.getBagAt(i)
    if(wmap[word]~=nil) then
      vector[i+1] = wmap[word] * mandarin.getIdfAt(i)
    else
      vector[i+1] = 0
    end
  end
  return vector
end

function makeTag(vector)
  local max_cos = 0
  local max_index = 0
  for i=0, mandarin.getTagVectorSize()-1 do
    local xy = 0
    local xx = 0
    for j=0, mandarin.getOneVectorSize()-1 do
      xy = xy + vector[j+1] * mandarin.getVectorAt(i, j)
      xx = xx + math.pow(vector[j+1], 2)
    -- print(xy,xx)
    end
    -- print("hello")
    local denominator = math.sqrt(xx) * mandarin.getAbsVectorAt(i)
    -- print(denomonator)
    local cos = xy/denominator
    -- print(cos)
    if(cos > max_cos) then
      max_cos = cos
      max_index = i
    end
  end
  -- print(max_cos)
  return mandarin.getTagAt(max_index)
end

print("------------------------------------------------------")
local wd,cnt = countUtf8("00服装u店老板吃l葡萄不*吐葡萄皮")
-- print(cnt)
for i,v in ipairs(wd) do
  -- print(v)
end 
print("------------------------------------------------------")
local utf8 = "服装店老板*吃葡萄不&吐葡萄皮哦"
local words = mandarinSolveInUtf8(utf8) 
for i,v in ipairs(words) do
  print(i, v)
end 

print("------------------------------------------------------")
local vec = makeVector(words)
for i,v in ipairs(vec) do
  -- print(i)
end
local tag = makeTag(vec)
print(tag)
print("------------------------------------------------------")
titles = {"硬币", "书", "屠龙宝刀，点击就送", "陆金所", "起点中文网", "出国留学", "免费网站模板下载,网页模板下载,网站模板网 我爱模板网 | www.5imb.com", "姐夫，别 吸了，我姐回来了！", "大唐奇迹-大唐奇迹|奇迹|奇迹sf|奇迹mu|奇迹私服|最新奇迹私服|新开奇迹私服|变态奇迹私服|网通奇迹私服|MU私服", "写代码"}
for i,v in ipairs(titles) do
  print(v, luaAlgoGetTag(v))
end
