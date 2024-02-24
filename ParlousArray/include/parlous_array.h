#ifndef PARLOUS_ARRAY_H_INCLUDED
#define PARLOUS_ARRAY_H_INCLUDED

#define MODULE_NAME "parlous_array"

#include "indefold.h"
// Replace below lua includes with "#include <dmsdk/sdk.h>" when using in Defold
#ifndef IN_DEFOLD
extern "C"{
    #include <lua.h>
    #include <luaconf.h>
    #include <lauxlib.h>
    #include <lualib.h>
}
#else
    #include <dmsdk/sdk.h>
#endif // IN_DEFOLD


// int get_int(lua_State* L);
// int put_int(lua_State* L);
// void defineMetatable(lua_State* L);
// int newIntArray(lua_State* L);

void LuaInit(lua_State* L);

#endif  // PARLOUS_ARRAY_H_INCLUDED