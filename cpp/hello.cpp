#include<iostream>

using namespace std;

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int main() {

  lua_State * L = luaL_newstate();
  if(L==NULL) return 1;

  int bRet = luaL_loadfile(L, "hello.lua");
  if(bRet) return 1;

  bRet = lua_pcall(L, 0, 0, 0);
  if(bRet) return 1;

  // lua_getfield(L, LUA_GLOBALSINDEX, "str"); 
  lua_getglobal(L, "str");
  string str = lua_tostring(L, -1);
  cout << "str : " << str << endl;
  lua_pop(L, 1);

  lua_getglobal(L, "add");
  lua_pushnumber(L, 10);
  lua_pushnumber(L, 20);
  bRet = lua_pcall(L, 2, 1, 0);
  if(bRet) return 1;
  if(lua_isnumber(L, -1)) {
    double fv = lua_tonumber(L, -1);
    cout << "add result : " << fv << endl;
  }
  lua_pop(L, 1);

  lua_getglobal(L, "tbl");
  lua_getfield(L, -1, "name");
  lua_remove(L, -2);
  string name = lua_tostring(L, -1);
  cout << "tbl.name : " << name << endl;
  lua_pop(L, 1);

  lua_getglobal(L, "helloLua");
  bRet = lua_pcall(L, 0, 1, 0);
  if(bRet) return 1;
  if(lua_isstring(L, -1)){
    string msg = lua_tostring(L, -1); 
    cout<<"helloLua: " << msg << endl;
  }
  lua_pop(L, 1);

  lua_close(L);

  return 0;
}
