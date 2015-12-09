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
		printf("Usage: synacor [-d] <binary>\n");
		return 1;
	}

	synacor_vm* vm = synacor_vm_init();

	char* binary;

	if (argc == 2) 
	{
 		binary = argv[1];
	}
	else
	{
		synacor_vm_set_flags(vm, argv[1]);
		binary = argv[2];
	}

	if (synacor_memory_load_binary(vm, binary) < 0)
	{
		printf("Error: Unable to load binary into VM!\n");
		return 1;
	}

	int exit_status = synacor_vm_run(vm);

	synacor_vm_destroy(vm);

	return exit_status;
}
