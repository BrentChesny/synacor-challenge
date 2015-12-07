#include <stdio.h>
#include <stdlib.h>

#include "synacor_vm.h"

int load_binary(synacor_vm* vm, char* binary_name)
{
	size_t read;
	int offset;
	FILE* binary;

	binary = fopen(binary_name, "rb");
	if (!binary)
	{
		printf("Unable to open binary!\n");
		return -1;
	}

	offset = 0;
	do {
		read = fread(vm->memory + offset, sizeof(uint16_t), CHUNK_SIZE, binary);
		offset += read;
	} while(read == CHUNK_SIZE);

	fclose(binary);	

	return 0;
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: synacor <binary>\n");
		return 1;
	}

	synacor_vm* vm = synacor_vm_init();

	if (load_binary(vm, argv[1]) < 0)
	{
		printf("Unable to load binary into VM!\n");
		return 1;
	}

	int exit_status = synacor_vm_run(vm);

	return exit_status;
}
