#include "callback.h"

#include <loader/loader.h>

LOADER_MOD_ENTRY initialize(loader_info* info)
{
	loader_mod& mod_instance = loader_mod::get();

	mod_instance.name = "roa-mod-template";
	mod_instance.description = "a template mod for roa-mod-loader";
	mod_instance.repository = "https://github.com/raicool/roa-mod-template";
	mod_instance.commit_hash = 0x00000000;

	loader_log_info("welcome to roa-mod-template version {}", VERSION_STR);

	// add a callback to be called whenever a frame is rendered
	loader_add_present_callback(present);

	// add a callback to be called whenever rival's window attempts to process an event
	loader_add_wndproc_callback(wndproc);

	return mod_instance;
}