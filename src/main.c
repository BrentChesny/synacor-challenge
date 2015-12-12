/**
 * Main entry point for the synacor VM.
 * 
 * @author Brent Chesny
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "synacor_vm.h"
#include "synacor_memory.h"
#include "synacor_debugger.h"


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: synacor <binary> [--debug]\n");
		return 1;
	}

	synacor_vm* vm = synacor_vm_init();

	if (synacor_memory_load_binary(vm, argv[1]) < 0)
	{
		printf("Error: Unable to load binary into VM!\n");
		return 1;
	}

	int exit_status;

	if (argc >= 3 && strcmp(argv[2], "--debug") == 0) 
	{
		printf("Running in debug...\n\n");
		synacor_debugger* debugger = synacor_debugger_init(vm);
		synacor_debugger_set_breakpoints(debugger, &argv[3], argc - 3);
		exit_status = synacor_debugger_run(debugger);
		synacor_debugger_destroy(debugger);
	}
	else 
	{
		printf("Running in release...\n\n");
		exit_status = synacor_vm_run(vm);
	}

	synacor_vm_destroy(vm);

	return exit_status;
}
