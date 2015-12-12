/**
 * Implementation of the synacor VM
 * 
 * @author Brent Chesny
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "synacor_vm.h"
#include "synacor_ops.h"
#include "synacor_memory.h"

/* Private functions */

int synacor_vm_at_breakpoint(synacor_vm* vm)
{
	for (int i = 0; i < vm->n_breakpoints; ++i)
	{
		if (vm->pc == vm->breakpoints[i])
			return 1;
	}

	return 0;
}

int synacor_vm_break(synacor_vm* vm)
{
	// printf("\e[1;1H\e[2J");
	printf("Encountered breakpoint at address: %u\n", vm->pc);

	return getchar();
}

/* Public functions */

synacor_vm* synacor_vm_init()
{
	synacor_vm* vm = (synacor_vm*) malloc(sizeof(synacor_vm));

	vm->stack = (synacor_stack*) malloc(sizeof(synacor_stack));

	return vm;
}

int synacor_vm_run(synacor_vm* vm)
{
	int status;

	if (vm->dump) 
		synacor_memory_dump(vm);

	while(!vm->halted) {
		status = synacor_vm_step(vm);
	}

	return status;
}

int synacor_vm_step(synacor_vm* vm)
{
	if (synacor_vm_at_breakpoint(vm))
		synacor_vm_break(vm);

	uint8_t argc;
	uint16_t argv[3];
	uint16_t opcode = synacor_vm_read_op(vm, &argc, argv);

	if (opcode < 0) {
		printf("Error: Unrecognized opcode!\n");
		synacor_vm_kill(vm);
		return 1;
	}

	int status = (*synacor_ops[opcode])(vm, argc, argv);

	return status;
}


void synacor_vm_kill(synacor_vm* vm)
{
	printf("Killing virtual machine...\n");
	vm->halted = 1;
}

void synacor_vm_destroy(synacor_vm* vm)
{
	if (vm != NULL) {
		if (vm->stack != NULL)
		{
			free(vm->stack);
			vm->stack = NULL;
		}

		free(vm);
		vm = NULL;
	}
}

uint16_t synacor_vm_read_op(synacor_vm* vm, uint8_t* argc, uint16_t* argv)
{
	uint16_t opcode = vm->memory[vm->pc++];

	if (opcode > MAX_OP)
		return -1;

	*argc = synacor_op_args[opcode];

	for (int i = 0; i < *argc; ++i)
	{
		argv[i] = vm->memory[vm->pc++];
	}

	return opcode;
}

void synacor_vm_print_state(synacor_vm* vm)
{
	fprintf(stderr, "[PC: %5u]", vm->pc);
	for (int i = 0; i < SYNACOR_N_REGISTERS; ++i)
	{
		fprintf(stderr, "[$%d: %5u]  ", i, vm->registers[i]);
	}
	fprintf(stderr, "\n");
}


