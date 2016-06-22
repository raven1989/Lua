#include"Madarin.h"
#include"Util.h"
#include"CharsetCnvtr.h"

SogouLabDic * SogouLabDic::instance_ = NULL;

SogouLabDic::SogouLabDic(){
  std::vector<std::string> pairs;
  CharsetCnvtr trans("utf-8", "unicode");
  for(int i=0; i< SOGOULABDIC_SIZE; i++){
    pairs.clear();
    std::string it(sogouLabDic[i]);
    split(pairs, it, ":");
    if(pairs.size()<2){ continue; }
    long freq = atol(pairs[1].c_str());
    if(freq<=0L){ continue; }
    dict_[trans.cnvt(pairs[0])] = freq+1;
  }
}

long SogouLabDic::operator[](const std::string& word){
  std::map<std::string, long>::iterator it = dict_.find(word);
  if(it==dict_.end()){
    return 1L;
  }
  return it->second;
}

int getFreqInSogouDicByUnicodeWord(lua_State* L){
  std::string word = lua_tostring(L, -1);
  lua_pop(L, 1);
  long res = SogouLabDic::instance()[word];
  lua_pushnumber(L, res);
  return 1;
}
int getFreqInSogouDicByUtf8Word(lua_State* L){
  CharsetCnvtr trans("utf-8", "unicode");
  std::string word = trans.cnvt(lua_tostring(L, -1));
  lua_pop(L, 1);
  long res = SogouLabDic::instance()[word];
  lua_pushnumber(L, res);
  return 1;
}

int luaopen_libMadarin(lua_State* L){
  luaL_Reg reg[] = {
    {"getFreqInSogouDicByUtf8Word", getFreqInSogouDicByUtf8Word},
    {"getFreqInSogouDicByUnicodeWord", getFreqInSogouDicByUnicodeWord},
    {NULL, NULL},
  };
  luaL_checkversion(L);
  luaL_newlib(L, reg);
  return 1;
}
