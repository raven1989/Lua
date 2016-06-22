#ifndef __MADARIN_H__
#define __MADARIN_H__

#include"SogouLabDic.h"
#include<iostream>
#include<map>

extern "C"
{
#include"lua.h"
#include"lauxlib.h"
#include"lualib.h"
}

int getFreqInSogouDicByUnicodeWord(lua_State* L);
int getFreqInSogouDicByUtf8Word(lua_State* L);

extern "C"
int luaopen_libMadarin(lua_State* L);

class SogouLabDic{
public:
  static SogouLabDic& instance(){
    if(instance_==NULL){
      instance_ = new SogouLabDic;
    }
    return *instance_;
  }
  long operator[](const std::string& word);
private:
  SogouLabDic();
  ~SogouLabDic();
  SogouLabDic(const SogouLabDic&);
  SogouLabDic& operator=(const SogouLabDic&);
private:
  static SogouLabDic * instance_;
  std::map<std::string, long> dict_;
};

#endif
