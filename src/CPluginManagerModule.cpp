/* CE3 Plugin Manager - for licensing and copyright see license.txt */

#include <StdAfx.h>
#include "CPluginManager.h"
#include <platform_impl.h>
#include <Nodes/G2FlowBaseNode.h>

extern "C"
{
    GAME_API PluginManager::IPluginBase* GetPluginInterface( const char* sInterfaceVersion )
    {
		// This function should not create a new interface class each call.
        static PluginManager::CPluginManager modulePlugin;
        gPluginManager = &modulePlugin;
		gsBaseInterfaceVersion = sInterfaceVersion;
        return modulePlugin.GetBase();
    }
}


// Needed for module specific flow node
CG2AutoRegFlowNodeBase* CG2AutoRegFlowNodeBase::m_pFirst = 0; //!< pointer to first flownode inside this plugin
CG2AutoRegFlowNodeBase* CG2AutoRegFlowNodeBase::m_pLast = 0; //!< pointer to last flownode inside this plugin

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
    // Placeholder not used by this plugin...
    switch ( ul_reason_for_call )
    {
        case DLL_PROCESS_ATTACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;

        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}