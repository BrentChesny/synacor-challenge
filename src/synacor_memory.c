/**
 * Implementation of the synacor memory operations
 * 
 * @author Brent Chesny
 */
#include <stdio.h>
#include <stdlib.h>

#include "synacor_memory.h"
#include "synacor_ops.h"

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

	vm->size = offset;

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

void synacor_memory_dump(synacor_vm* vm)
{
	FILE *f = fopen("dump.s", "w");
	if (f == NULL)
	{
	    printf("Error: cannot open dumpfile!\n");
	    return;
	}

	uint16_t counter = 0;
	while(counter < vm->size)
	{
		uint16_t address = counter;
		uint16_t opcode = vm->memory[counter++];

		if (opcode <= MAX_OP)
		{
			fprintf(f, "[%u] %5s:\t", address, synacor_op_names[opcode]);
			int argc = synacor_op_args[opcode];
			for (int i = 0; i < argc; ++i)
			{
				uint16_t arg = vm->memory[counter++];
				if (arg <= 127) {
					if (opcode == OP_OUT) 
						fprintf(f, "  '%c'", (char) arg);
					else
						fprintf(f, "  %u", arg);
				} else if (arg > SYNACOR_MAX_LITERAL_VALUE) {
					fprintf(f, "  $%u", arg - SYNACOR_MAX_LITERAL_VALUE - 1);
				} else {
					fprintf(f, "  %u", arg);					
				}
			}
			fprintf(f, "\n");
		}
		else
		{
			fprintf(f, "[%u] %5s:\t  %u\n", address, "DATA", opcode);		
		}
	}

	printf("%d bytes dumped.\n\n", vm->size * 2);

	fclose(f);
}
