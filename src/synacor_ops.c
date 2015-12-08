#include <stdio.h>

#include "synacor_ops.h"
#include "synacor_vm.h"
#include "synacor_macros.h"
#include "synacor_memory.h"

uint8_t synacor_op_args[] =	{
	0, 2, 1, 1, 3, 3, 	// halt, set, push, pop, eq, gt
	1, 2, 2, 3, 3, 3, 	// jmp, jt, jf, add, mult, mod
	3, 3, 2, 2, 2, 1, 	// and, or, not, rmem, wmem, call
	0, 1, 1, 0 			// ret, out, in, noop
};

int (*synacor_ops[]) (synacor_vm* vm, uint8_t argc, uint16_t* argv) = {
	synacor_op_halt,
	synacor_op_set,
	synacor_op_push,
	synacor_op_pop,
	synacor_op_eq,
	synacor_op_gt,
	synacor_op_jmp,
	synacor_op_jt,
	synacor_op_jf,
	synacor_op_add,
	synacor_op_mult,
	synacor_op_mod,
	synacor_op_and,
	synacor_op_or,
	synacor_op_not,
	synacor_op_rmem,
	synacor_op_wmem,
	synacor_op_call,
	synacor_op_ret,
	synacor_op_out,
	synacor_op_in,
	synacor_op_noop
};

int synacor_op_halt(synacor_vm* vm, uint8_t argc, uint16_t* argv)
{
	UNUSED(argc); UNUSED(argv);

	printf("End of program reached, halting.\n");
	vm->halted = 1;

	return 0;
}

int synacor_op_set(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_push(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_pop(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_eq(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_gt(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_jmp(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_jt(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_jf(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_add(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_mult(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_mod(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_and(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_or(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_not(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_rmem(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_wmem(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_call(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_ret(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_out(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	char out = (char) synacor_memory_map_value(vm, argv[0]);
	putchar(out);

	return 0;
}

int synacor_op_in(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}

int synacor_op_noop(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}
