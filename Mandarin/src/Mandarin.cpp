#include"Mandarin.h"
#include"Util.h"
#include<math.h>
// #include"CharsetCnvtr.h"

SogouLabDic * SogouLabDic::instance_ = NULL;

SogouLabDic::SogouLabDic(){
  count_ = 0; std::vector<std::string> pairs;
  for(int i=0; i< SOGOULABDIC_SIZE; i++){
    pairs.clear();
    std::string it(sogouLabDic[i]);
    split(pairs, it, ":");
    if(pairs.size()<2){ continue; }
    long freq = atol(pairs[1].c_str());
    if(freq<=0L){ continue; }
    dict_[pairs[0]] = freq;
    count_ += freq;
  }
}

long SogouLabDic::operator[](const std::string& word){
  std::map<std::string, long>::iterator it = dict_.find(word);
  long res = 1L;
  if(it!=dict_.end()){ res = it->second;
  }
  // std::cout << "SogouLabDic::operator[] --> word:" << word << " freq:" << res << std::endl;
  return res;
}

int getSogouDicSize(lua_State* L){
  lua_pushnumber(L, SOGOULABDIC_SIZE);
  return 1;
}

/* int getUnicodeFromUtf8(lua_State* L){
 *   std::string utf8 = lua_tostring(L, -1);
 *   lua_pop(L, 1);
 *   CharsetCnvtr trans("utf-8", "ucs-2le");
 *   std::string unicode = trans.cnvt(utf8);
 *   lua_pushstring(L, unicode.c_str());
 *   return 1;
 * } */

/* int getUtf8FromUnicode(lua_State* L){
 *   std::string unicode = lua_tostring(L, -1);
 *   lua_pop(L, 1);
 *   CharsetCnvtr trans("ucs-2le", "utf-8");
 *   std::string utf8 = trans.cnvt(unicode);
 *   lua_pushstring(L, utf8.c_str());
 *   return 1;
 * } */

int getFreqInSogouDic(lua_State* L){
  std::string word = lua_tostring(L, -1);
  lua_pop(L, 1);
  long res = SogouLabDic::instance()[word];
  lua_pushnumber(L, res);
  return 1;
}

int getBagAt(lua_State* L){
  int index = lua_tonumber(L, -1);
  lua_pop(L, 1);
  lua_pushstring(L, BAGS[index]);
  return 1;
}

int getIdfAt(lua_State* L){
  int index = lua_tonumber(L, -1);
  lua_pop(L, 1);
  double res = IDFS[index];
  lua_pushnumber(L, res);
  return 1;
}

int getBagIdfSize(lua_State* L){
  lua_pushnumber(L, BAG_IDF_SIZE);
  return 1;
}

int getVectorAt(lua_State* L){
  int col = lua_tonumber(L, -1);
  int row = lua_tonumber(L, -2);
  lua_pop(L, 2);
  double res = VECTORS[row][col];
  lua_pushnumber(L, res);
  return 1;
}

int getTagAt(lua_State* L){
  int index = lua_tonumber(L, -1);
  lua_pop(L, 1);
  lua_pushstring(L, TAGS[index]);
  return 1;
}

int getTagVectorSize(lua_State* L){
  lua_pushnumber(L, TAG_VECTOR_SIZE);
  return 1;
}

int getOneVectorSize(lua_State* L){
  lua_pushnumber(L, VECTOR_SIZE);
  return 1;
}

int getAbsVectorAt(lua_State* L){
  int index = lua_tonumber(L, -1);
  lua_pop(L, 1);
  double sum = 0.0;
  const double * vector = VECTORS[index];
  for(int col=0; col<VECTOR_SIZE; col++){
    sum += pow(vector[col], 2);
  }
  // std::cout << "sum : " << sum << std::endl;
  lua_pushnumber(L, sqrt(sum));
  return 1;
}

int luaopen_libMandarin(lua_State* L){
  luaL_Reg reg[] = {
    {"getFreqInSogouDic", getFreqInSogouDic},
    {"getSogouDicSize", getSogouDicSize},
    {"getBagAt", getBagAt},
    {"getIdfAt", getIdfAt},
    {"getBagIdfSize", getBagIdfSize},
    {"getTagAt", getTagAt},
    {"getVectorAt", getVectorAt},
    {"getTagVectorSize", getTagVectorSize},
    {"getOneVectorSize", getOneVectorSize},
    {"getAbsVectorAt", getAbsVectorAt},
    // {"getUnicodeFromUtf8", getUnicodeFromUtf8},
    // {"getUtf8FromUnicode", getUtf8FromUnicode},
    {NULL, NULL},
  };
  luaL_checkversion(L);
  luaL_newlib(L, reg);
  return 1;
}
