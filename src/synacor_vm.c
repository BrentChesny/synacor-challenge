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
	uint8_t argc = synacor_op_args[opcode];

	switch(opcode) {
		case OP_HALT:
			break;
		case OP_HALT:
			break;
		case OP_SET:
			break;
		case OP_PUSH:
			break;
		case OP_POP:
			break;
		case OP_EQ:
			break;
		case OP_GT:
			break;
		case OP_JMP:
			break;
		case OP_JT:
			break;
		case OP_JF:
			break;
		case OP_ADD:
			break;
		case OP_MULT:
			break;
		case OP_MOD:
			break;
		case OP_AND:
			break;
		case OP_OR:
			break;
		case OP_NOT:
			break;
		case OP_RMEM:
			break;
		case OP_WMEM:
			break;
		case OP_CALL:
			break;
		case OP_RET:
			break;
		case OP_OUT:
			break;
		case OP_IN:
			break;
		case OP_NOOP:
		default:
			printf("Error: Unrecognized opcode!\n");
			synacor_vm_kill(vm);
			return 1;
	}

	vm->pc++;

	return 0;
}


void synacor_vm_kill(synacor_vm* vm)
{
	printf("Killing virtual machine...\n");
	vm->halted = 1;
}
