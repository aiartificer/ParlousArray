// parlous_array.cpp
// Extension lib defines
#define LIB_NAME "ParlousArray"

// include the Defold SDK
#include <dmsdk/sdk.h>
#include "parlous_array.h"


// ========================
// = Defold Wrapper Calls =
// ========================
static int __get_int(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    return get_int(L);
}

static int __put_int(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    return put_int(L);
}

static int __newIntArray(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    return newIntArray(L);
}


// ========================
// ====== Lua Stuff =======
// ========================
// static const luaL_reg Module_methods[] =
// {
//     {"new_int_array", __newIntArray},
//     {"get", __get_int},
//     {"put", __put_int},
//     {0, 0}
// };

// static void LuaInit(lua_State* L)
// {
//     int top = lua_gettop(L);

//     // Register lua names
//     luaL_register(L, MODULE_NAME, Module_methods);

//     lua_pop(L, 1);
//     assert(top == lua_gettop(L));
// }

static dmExtension::Result AppInitializeParlousArray(dmExtension::AppParams* params)
{
    dmLogInfo("AppInitializeParlousArray");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result InitializeParlousArray(dmExtension::Params* params)
{
    // Init Lua
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizeParlousArray(dmExtension::AppParams* params)
{
    dmLogInfo("AppFinalizeParlousArray");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeParlousArray(dmExtension::Params* params)
{
    dmLogInfo("FinalizeParlousArray");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result OnUpdateParlousArray(dmExtension::Params* params)
{
    dmLogInfo("OnUpdateParlousArray");
    return dmExtension::RESULT_OK;
}

static void OnEventParlousArray(dmExtension::Params* params, const dmExtension::Event* event)
{
    switch(event->m_Event)
    {
        case dmExtension::EVENT_ID_ACTIVATEAPP:
            dmLogInfo("OnEventParlousArray - EVENT_ID_ACTIVATEAPP");
            break;
        case dmExtension::EVENT_ID_DEACTIVATEAPP:
            dmLogInfo("OnEventParlousArray - EVENT_ID_DEACTIVATEAPP");
            break;
        case dmExtension::EVENT_ID_ICONIFYAPP:
            dmLogInfo("OnEventParlousArray - EVENT_ID_ICONIFYAPP");
            break;
        case dmExtension::EVENT_ID_DEICONIFYAPP:
            dmLogInfo("OnEventParlousArray - EVENT_ID_DEICONIFYAPP");
            break;
        default:
            dmLogWarning("OnEventParlousArray - Unknown event id");
            break;
    }
}

// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update, on_event, final)

// ParlousArray is the C++ symbol that holds all relevant extension data.
// It must match the name field in the `ext.manifest`
DM_DECLARE_EXTENSION(ParlousArray, LIB_NAME, AppInitializeParlousArray, AppFinalizeParlousArray, InitializeParlousArray, OnUpdateParlousArray, OnEventParlousArray, FinalizeParlousArray)
