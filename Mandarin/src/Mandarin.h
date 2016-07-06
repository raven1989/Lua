#ifndef __MANDARIN_H__
#define __MANDARIN_H__

#include"SogouLabDic.h"
#include"TrainDataVector.h"
#include<iostream>
#include<map>

extern "C"
{
#include"lua.h"
#include"lauxlib.h"
#include"lualib.h"
}

int getFreqInSogouDic(lua_State* L);
// int getFreqInSogouDicByUtf8Word(lua_State* L);
int getSogouDicSize(lua_State* L);
// int getUnicodeFromUtf8(lua_State* L);
// int getUtf8FromUnicode(lua_State* L);
int getBagAt(lua_State* L);
int getIdfAt(lua_State* L);
int getBagIdfSize(lua_State* L);

int getVectorAt(lua_State* L);
int getTagAt(lua_State* L);
int getTagVectorSize(lua_State* L);
int getOneVectorSize(lua_State* L);

int getAbsVectorAt(lua_State* L);

extern "C"
int luaopen_libMandarin(lua_State* L);

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
  long count_;
};

#endif
