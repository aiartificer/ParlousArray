// parlous_array.cpp
// Extension lib defines
#define LIB_NAME "ParlousArray"
#define MODULE_NAME "parlous_array"

#include <cassert>
#include <math.h>
#include <string.h>
#include "parlous_array.h"
using namespace std;


// ========================
// ====== Lua Stuff =======
// ========================
static const luaL_reg Module_methods[] =
{
    {"new_int_array", newArray<lua_Integer>},
    {"new_num_array", newArray<lua_Number>},
    {0, 0}
};

void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

