// parlous_array.cpp
// Extension lib defines
#define LIB_NAME "ParlousArray"

// include the Defold SDK
#include <dmsdk/sdk.h>
#include "parlous_array.h"


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
