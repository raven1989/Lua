#include<map>
#include<iostream>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int findWord(lua_State* L);

extern "C"
int luaopen_libdynamic(lua_State * L){
  luaL_Reg reg[] = {
    {"find_word", findWord},
    {NULL, NULL},
  };
  luaL_checkversion(L);
  luaL_newlib(L, reg);
  return 1;
}

class Singleton{
public: 
  static Singleton& instance(){
    if(instance_ == NULL){
      instance_ = new Singleton;
    }
    return *instance_;
  }
  long findFreqByWord(std::string& word){
    std::map<std::string, long>::iterator it = freq_.find(word);
    if(it!=freq_.end()){
      return it->second;
    }
    return -1L;
  }
private:
  Singleton(){
    freq_["ok"] = 1;
  };
  ~Singleton();
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);
private:
  static Singleton * instance_;
  std::map<std::string, long> freq_;
};
Singleton* Singleton::instance_ = NULL;

int findWord(lua_State* L){
  std::string word = lua_tostring(L,-1);
  lua_pop(L, 1);
  long res = Singleton::instance().findFreqByWord(word);
  lua_pushnumber(L, res);
  return 1;
}


