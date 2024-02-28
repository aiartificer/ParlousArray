// parlous_array.cpp
// Extension lib defines
#define LIB_NAME "ParlousArray"
#define MODULE_NAME "parlous_array"

#include <cassert>
#include <math.h>
#include <string.h>
#include "parlous_array.h"
using namespace std;


template <typename T>
static int newArray(lua_State* L);


static int len(lua_State* L)                      //// [-0, +1, m]
{
    // Collect len and put on stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_pushinteger(L, length);                     // [-0, +1, -]
    
    // Return 1 item
    return 1;
}

template <typename T>
static int get(lua_State* L)                      //// [-0, +1, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    T *arr = (T *)lua_touserdata(L, -2);
    lua_Integer i = luaL_checkinteger(L, -1);
    if(length <= i)
    {
        lua_pushstring(L, "Index out of bounds");
        lua_error(L);
    }

    // Get array at index
    lua_pushnumber(L, (T)arr[i]);                   // [-0, +1, -]
    
    // Return 1 item
    return 1;
}

template <typename T>
static int put(lua_State* L)                      //// [-0, +0, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    T *arr = (T *)lua_touserdata(L, -3);
    lua_Integer i = luaL_checkinteger(L, -2);
    T v = (T)luaL_checknumber(L, -1);
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

template <typename T>
static int add(lua_State* L)                      //// [-0, +1, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer type_size = lua_tointeger(L, lua_upvalueindex(2));
    T *arrA = (T *)lua_touserdata(L, -2);
    T *arrB = (T *)lua_touserdata(L, -1);

    // Allocate array to hold results
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushinteger(L, type_size);                  // [-0, +1, -]
    newArray<T>(L);                                 // [-0, +1, m]
    T *arrC = (T *)lua_touserdata(L, -1);
    lua_insert(L, lua_gettop(L) - 2);
    lua_pop(L, 2);                                  // [-2, +0, -]

    // Add value to all elements
    for (lua_Integer i = 0; i < length; i++)
        arrC[i] = arrA[i] + arrB[i];

    // Return 0 items
    return 1;
}

template <typename T>
static int sub(lua_State* L)                      //// [-0, +1, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer type_size = lua_tointeger(L, lua_upvalueindex(2));
    T *arrA = (T *)lua_touserdata(L, -2);
    T *arrB = (T *)lua_touserdata(L, -1);

    // Allocate array to hold results
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushinteger(L, type_size);                  // [-0, +1, -]
    newArray<T>(L);                                 // [-0, +1, m]
    T *arrC = (T *)lua_touserdata(L, -1);
    lua_insert(L, lua_gettop(L) - 2);
    lua_pop(L, 2);                                  // [-2, +0, -]

    // Add value to all elements
    for (lua_Integer i = 0; i < length; i++)
        arrC[i] = arrA[i] - arrB[i];

    // Return 0 items
    return 1;
}

template <typename T>
static int mul(lua_State* L)                      //// [-0, +1, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer type_size = lua_tointeger(L, lua_upvalueindex(2));
    T *arrA = (T *)lua_touserdata(L, -2);
    T *arrB = (T *)lua_touserdata(L, -1);

    // Allocate array to hold results
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushinteger(L, type_size);                  // [-0, +1, -]
    newArray<T>(L);                                 // [-0, +1, m]
    T *arrC = (T *)lua_touserdata(L, -1);
    lua_insert(L, lua_gettop(L) - 2);
    lua_pop(L, 2);                                  // [-2, +0, -]

    // Add value to all elements
    for (lua_Integer i = 0; i < length; i++)
        arrC[i] = arrA[i]*arrB[i];

    // Return 0 items
    return 1;
}

template <typename T>
static int div(lua_State* L)                      //// [-0, +1, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer type_size = lua_tointeger(L, lua_upvalueindex(2));
    T *arrA = (T *)lua_touserdata(L, -2);
    T *arrB = (T *)lua_touserdata(L, -1);

    // Allocate array to hold results
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushinteger(L, type_size);                  // [-0, +1, -]
    newArray<T>(L);                                 // [-0, +1, m]
    T *arrC = (T *)lua_touserdata(L, -1);
    lua_insert(L, lua_gettop(L) - 2);
    lua_pop(L, 2);                                  // [-2, +0, -]

    // Add value to all elements
    for (lua_Integer i = 0; i < length; i++)
        arrC[i] = arrA[i]/arrB[i];

    // Return 0 items
    return 1;
}

template <typename T>
static int mod(lua_State* L)                      //// [-0, +1, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer type_size = lua_tointeger(L, lua_upvalueindex(2));
    T *arrA = (T *)lua_touserdata(L, -2);
    T *arrB = (T *)lua_touserdata(L, -1);

    // Allocate array to hold results
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushinteger(L, type_size);                  // [-0, +1, -]
    newArray<T>(L);                                 // [-0, +1, m]
    T *arrC = (T *)lua_touserdata(L, -1);
    lua_insert(L, lua_gettop(L) - 2);
    lua_pop(L, 2);                                  // [-2, +0, -]

    // Add value to all elements
    for (lua_Integer i = 0; i < length; i++)
        arrC[i] = fmod(arrA[i], arrB[i]);

    // Return 0 items
    return 1;
}

template <typename T>
static int pow(lua_State* L)                      //// [-0, +1, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    lua_Integer type_size = lua_tointeger(L, lua_upvalueindex(2));
    T *arrA = (T *)lua_touserdata(L, -2);
    T *arrB = (T *)lua_touserdata(L, -1);

    // Allocate array to hold results
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushinteger(L, type_size);                  // [-0, +1, -]
    newArray<T>(L);                                 // [-0, +1, m]
    T *arrC = (T *)lua_touserdata(L, -1);
    lua_insert(L, lua_gettop(L) - 2);
    lua_pop(L, 2);                                  // [-2, +0, -]

    // Add value to all elements
    for (lua_Integer i = 0; i < length; i++)
        arrC[i] = pow(arrA[i], arrB[i]);

    // Return 0 items
    return 1;
}

template <typename T>
static int map(lua_State* L)                      //// [-0, +0, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    T *arr = (T *)lua_touserdata(L, -2);
    luaL_checktype(L, -1, LUA_TFUNCTION);
    lua_pushvalue(L, -1);                           // [-0, +1, -]

    // Setup loop
    for (lua_Integer i = 0; i < length; i++)
    {
        lua_pushnumber(L, (T)arr[i]);               // [-0, +1, -]
        lua_call(L, 1, 1);                          // [-2, +1, e]
        T result = (T)luaL_checknumber(L, -1);
        arr[i] = result;
        lua_pop(L, 1);                              // [-1, +0, -]
        lua_pushvalue(L, -1);                       // [-0, +1, -]
    }

    // Return 0 items
    return 0;
}

template <typename T>
static int foreach(lua_State* L)                  //// [-0, +0, m]
{
    // Check and collect parameters from stack
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));
    T *arr = (T *)lua_touserdata(L, -2);
    luaL_checktype(L, -1, LUA_TFUNCTION);
    lua_pushvalue(L, -1);                           // [-0, +1, -]

    // Setup loop
    for (lua_Integer i = 0; i < length; i++)
    {
        lua_pushnumber(L, (T)arr[i]);               // [-0, +1, -]
        lua_call(L, 1, 0);                          // [-2, +0, e]
        lua_pushvalue(L, -1);                       // [-0, +1, -]
    }

    // Return 0 items
    return 0;
}

static int len_factory(lua_State* L,              //// [-0, +1, m]
                       lua_Integer length,
                       lua_Integer type_size,
                       lua_CFunction fn)
{

    // Collect len and put on stack
    lua_pushinteger(L, length);                     // [-0, +1, -]
    lua_pushinteger(L, type_size);                  // [-0, +1, -]
    lua_pushcclosure(L, fn, 2);                     // [-2, +1, -]
    
    // Return 1 item
    return 1;
}

template <typename T>
static int index_call(lua_State* L)               //// [-0, +1, m]
{
    lua_Integer length = lua_tointeger(L, lua_upvalueindex(1));

    // Check if a function call or array index
    if(LUA_TSTRING == lua_type(L, -1))
    {
        const char *f = luaL_checkstring(L, -1);
        if(strcmp("map", f) == 0)
        {
            lua_pushinteger(L, length);             // [-0, +1, -]
            lua_pushcclosure(L, map<T>, 1);         // [-1, +1, -]
            return 1;
        }
        else if(strcmp("foreach", f) == 0)
        {
            lua_pushinteger(L, length);             // [-0, +1, -]
            lua_pushcclosure(L, foreach<T>, 1);     // [-1, +1, -]
            return 1;
        }
        else
            return luaL_error(L, "Invalid key");
    }
    else if(LUA_TNUMBER == lua_type(L, -1))
        return get<T>(L);                           // [-0, +1, m]
    
    // Return 1 item
    return 1;
}

template <typename T>
static void defineMetatable_int(lua_State* L,     //// [-0, +0, m]
                                lua_Integer length,
                                lua_Integer type_size)
{
    // Create a metatable for the user data
    lua_createtable(L, 0, 1);                       // [-0, +1, m]

    // Define __len
    lua_pushstring(L, "__len");                     // [-0, +1, m]
    len_factory(L, length, type_size, len);         // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__index");                   // [-0, +1, m]
    len_factory(L, length, type_size, index_call<T>);   // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__newindex");                // [-0, +1, m]
    len_factory(L, length, type_size, put<T>);      // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__add");                     // [-0, +1, m]
    len_factory(L, length, type_size, add<T>);      // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__sub");                     // [-0, +1, m]
    len_factory(L, length, type_size, sub<T>);      // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__mul");                     // [-0, +1, m]
    len_factory(L, length, type_size, mul<T>);      // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__div");                     // [-0, +1, m]
    len_factory(L, length, type_size, div<T>);      // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__mod");                     // [-0, +1, m]
    len_factory(L, length, type_size, mod<T>);      // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Define the __index method
    lua_pushstring(L, "__pow");                     // [-0, +1, m]
    len_factory(L, length, type_size, pow<T>);      // [-0, +1, m]
    lua_settable(L, -3);                            // [-2, +0, -]

    // Set the metatable
    lua_setmetatable(L, -2);                        // [-1, +0, -]
}

template <typename T>
int newArray(lua_State* L)                        //// [-0, +1, m]
{
    // Check and get parameter string from stack
    lua_Integer length = luaL_checkinteger(L, -2);
    lua_Integer type_size = luaL_checkinteger(L, -1);

    // Allocate array
    lua_newuserdata(L, length*type_size);           // [-0, +1, m]

    // Define metatable
    defineMetatable_int<T>(L, length, type_size);   // [-0, +0, m]
    
    // Return 1 item
    return 1;
}


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

