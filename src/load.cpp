#include "callback.h"

#include <loader/loader.h>

DWORD WINAPI entry(LPVOID hModule)
{
	loader_log_info("welcome to roa-mod-template version {}", VERSION_STR);

	// add a callback to be called whenever a frame is rendered
	loader_add_present_callback(present);

	// add a callback to be called whenever rival's window attempts to process an event
	loader_add_wndproc_callback(wndproc);

	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		HANDLE hHandle = CreateThread(NULL, 0, entry, hModule, 0, NULL);
		if (hHandle != NULL)
		{
			CloseHandle(hHandle);
		}
	}
	else if (fdwReason == DLL_PROCESS_DETACH && !lpReserved)
	{
		FreeLibraryAndExitThread(hModule, 0);
	}

	return TRUE;
}