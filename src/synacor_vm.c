#include <stdio.h>
#include <stdlib.h>

#include "synacor_vm.h"
#include "synacor_ops.h"

synacor_vm* synacor_vm_init()
{
	synacor_vm* vm = (synacor_vm*) malloc(sizeof(synacor_vm));

	return vm;
}

int synacor_vm_run(synacor_vm* vm)
{
	int status;

	while(!vm->halted) {
		status = synacor_vm_step(vm);
	}

	return status;
}

int synacor_vm_step(synacor_vm* vm)
{
	uint16_t opcode = vm->memory[vm->pc];

	if (opcode > MAX_OP)
	{
		printf("Error: Unrecognized opcode!\n");
		synacor_vm_kill(vm);
		return 1;
	}

	uint8_t argc = synacor_op_args[opcode];

	// TODO execute op

	vm->pc++;

	return 0;
}


void synacor_vm_kill(synacor_vm* vm)
{
	printf("Killing virtual machine...\n");
	vm->halted = 1;
}
