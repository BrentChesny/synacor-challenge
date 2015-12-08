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
