/**
 * Implementation of the synacor memory operations
 * 
 * @author Brent Chesny
 */
#include <stdio.h>
#include <stdlib.h>

#include "synacor_memory.h"

int synacor_memory_load_binary(synacor_vm* vm, char* binary_name)
{
	size_t read;
	int offset;
	FILE* binary;

	binary = fopen(binary_name, "rb");
	if (!binary)
	{
		printf("Error: Unable to open binary!\n");
		return -1;
	}

	offset = 0;
	do {
		read = fread(vm->memory + offset, sizeof(uint16_t), SYNACOR_CHUNK_SIZE, binary);
		offset += read;
	} while(read == SYNACOR_CHUNK_SIZE);

	fclose(binary);	

	return 0;
}

uint16_t synacor_memory_map_value(synacor_vm* vm, uint16_t value)
{
	if (value <= SYNACOR_MAX_LITERAL_VALUE)
	{
		return value;
	} 
	else if (value <= SYNACOR_MAX_LITERAL_VALUE + SYNACOR_N_REGISTERS) 
	{
		uint8_t r = value - SYNACOR_MAX_LITERAL_VALUE - 1;
		return vm->registers[r];
	} 
	else 
	{
		printf("Warning: Invalid memory value!\n");
		return 0;
	}
}

uint16_t synacor_memory_map_register(uint16_t value)
{
	if (value > SYNACOR_MAX_LITERAL_VALUE && value <= SYNACOR_MAX_LITERAL_VALUE + SYNACOR_N_REGISTERS) 
	{
		return value - SYNACOR_MAX_LITERAL_VALUE - 1;
	} 
	else 
	{
		printf("Warning: Invalid register index!\n");
		return 0;
	}
}
