// parlous_array.cpp
// Extension lib defines
#define LIB_NAME "ParlousArray"
#define MODULE_NAME "parlous_array"

#include <cassert>
#include "parlous_array.h"


static int get_int(lua_State* L)
{
    printf("--> Called get_int\n");  // ### DEBUG

    // Check and get parameter string from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer *arr = (lua_Integer *)lua_touserdata(L, -2);
    lua_Integer i = luaL_checkinteger(L, -1);
    if(length <= i)
    {
        lua_pushstring(L, "Index out of bounds");
        lua_error(L);
    }

    // Get array at index
    lua_pushinteger(L, arr[i]);                     // [-0, +1, -]
    
    // Return 1 item
    return 1;
}

static int put_int(lua_State* L)
{
    printf("--> Called put_int\n");  // ### DEBUG

    // Check and get parameter string from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer *arr = (lua_Integer *)lua_touserdata(L, -3);
    lua_Integer i = luaL_checkinteger(L, -2);
    lua_Integer v = luaL_checkinteger(L, -1);
    if(length <= i)
    {
        lua_pushstring(L, "Index out of bounds");
        lua_error(L);
    }

    // Put value in array at index
    arr[i] = v;
    
    // Return 1 item
    return 1;
}

static int len(lua_State* L)
{
    printf("--> Called len\n");  // ### DEBUG

    // Collect len and put on stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_pushinteger(L, length);                     // [-0, +1, -]
    
    // Return 1 item
    return 1;
}
static int len_factory(lua_State* L,
                       lua_Integer length,
                       lua_CFunction fn)
{
    printf("--> Called len_factory\n");  // ### DEBUG

    // Collect len and put on stack
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushcclosure(L, fn, 1);                     // [-1, +1, -]
    
    // Return 1 item
    return 1;
}

static void defineMetatable(lua_State* L,
                            lua_Integer length)   //// [-0, +0, m]
{
    printf("--> Called defineMetatable\n");  // ### DEBUG

    // Create a metatable for the user data
    lua_createtable(L, 0, 1);                       // [-0, +1, m]

    // Define __len
    lua_pushstring(L, "__len");                     // [-0, +1, m]
    len_factory(L, length, len);                    // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__index");                   // [-0, +1, m]
    len_factory(L, length, get_int);                // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__newindex");                // [-0, +1, m]
    len_factory(L, length, put_int);                // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Set the metatable
    lua_setmetatable(L, -2);                        // [-1, +0, -]
}

static int newIntArray(lua_State* L)              //// [-0, +1, m]
{
    printf("--> Called newIntArray\n");  // ### DEBUG

    // Check and get parameter string from stack
    lua_Integer len = luaL_checkinteger(L, -2);
    lua_Integer type_size = luaL_checkinteger(L, -1);

    // Allocate array
    lua_newuserdata(L, len*type_size);              // [-0, +1, m]

    // Define metatable
    defineMetatable(L, len);
    
    // Return 1 item
    return 1;
}


// ========================
// ====== Lua Stuff =======
// ========================
static const luaL_reg Module_methods[] =
{
    {"new_int_array", newIntArray},
    {"get", get_int},
    {"put", put_int},
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

