/**
 * Main entry point for the synacor VM.
 * 
 * @author Brent Chesny
 */

#include <stdio.h>
#include <stdlib.h>

#include "synacor_vm.h"
#include "synacor_memory.h"


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: synacor <binary>\n");
		return 1;
	}

	synacor_vm* vm = synacor_vm_init();

	if (synacor_memory_load_binary(vm, argv[1]) < 0)
	{
		printf("Error: Unable to load binary into VM!\n");
		return 1;
	}

	int exit_status = synacor_vm_run(vm);

	synacor_vm_destroy(vm);

	return exit_status;
}
