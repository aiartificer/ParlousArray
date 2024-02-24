#include <cstring>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <time.h>
#include "parlous_array.h"
extern "C"{
    #include <lua.h>    
    #include <luaconf.h>
    #include <lauxlib.h>
    #include <lualib.h>
}


void test_from_lua_script()
{
    printf("Testing Lua script that uses Parlous Array\n");

    // Setup Lua environment
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // Register the C functions
    // lua_pushcfunction(L, newIntArray);
    // lua_setglobal(L, "new_int_array");
    // lua_pushcfunction(L, get_int);
    // lua_setglobal(L, "get");
    // lua_pushcfunction(L, put_int);
    // lua_setglobal(L, "put");
    LuaInit(L);

    // Run the Lua script
    int ret = luaL_dofile(L, "test/test_parlous_array.lua");
    if (ret != 0) {
        printf("Error running test_parlous_array.lua\n");
        const char * errMsg = lua_tostring(L,-1);
        printf("Error: %s\n", errMsg);
        lua_close(L);
        return;
    }
    lua_close(L);
}

int test()
{
    printf("Running tests...\n");
    test_from_lua_script();
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc > 1) {
        if (strcmp("test", argv[1]) == 0)
            return test();
    }
    return 0;
}
