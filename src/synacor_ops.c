/**
 * Implementation of the operations of the synacor VM.
 * 
 * @author Brent Chesny
 */
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

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	
	vm->registers[a] = b;

	return 0;
}

int synacor_op_push(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_value(vm, argv[0]);
	synacor_stack_push(vm->stack, a);

	return 0;
}

int synacor_op_pop(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	int pop = synacor_stack_pop(vm->stack);

	if (pop >= 0)
		vm->registers[a] = (uint16_t) pop;

	return 0;
}

int synacor_op_eq(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	uint16_t c = synacor_memory_map_value(vm, argv[2]);

	if (b == c)
		vm->registers[a] = 1;
	else
		vm->registers[a] = 0;

	return 0;
}

int synacor_op_gt(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	uint16_t c = synacor_memory_map_value(vm, argv[2]);

	if (b > c)
		vm->registers[a] = 1;
	else
		vm->registers[a] = 0;

	return 0;
}

int synacor_op_jmp(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_value(vm, argv[0]);

	vm->pc = a;

	return 0;
}

int synacor_op_jt(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_value(vm, argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);

	if (a != 0)
		vm->pc = b;

	return 0;
}

int synacor_op_jf(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_value(vm, argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);

	if (a == 0)
		vm->pc = b;

	return 0;
}

int synacor_op_add(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	uint16_t c = synacor_memory_map_value(vm, argv[2]);

	vm->registers[a] = (b + c) % 32768;

	return 0;
}

int synacor_op_mult(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	uint16_t c = synacor_memory_map_value(vm, argv[2]);

	vm->registers[a] = (b * c) % 32768;

	return 0;
}

int synacor_op_mod(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	uint16_t c = synacor_memory_map_value(vm, argv[2]);

	vm->registers[a] = b % c;

	return 0;
}

int synacor_op_and(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	uint16_t c = synacor_memory_map_value(vm, argv[2]);

	vm->registers[a] = b & c;

	return 0;
}

int synacor_op_or(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);
	uint16_t c = synacor_memory_map_value(vm, argv[2]);

	vm->registers[a] = b | c;

	return 0;
}

int synacor_op_not(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);

	vm->registers[a] = 32767 - b; // CHECK not sure if correct

	return 0;
}

int synacor_op_rmem(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_register(argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);

	vm->registers[a] = vm->memory[b];

	return 0;
}

int synacor_op_wmem(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_value(vm, argv[0]);
	uint16_t b = synacor_memory_map_value(vm, argv[1]);

	vm->memory[a] = b;

	return 0;
}

int synacor_op_call(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc);

	uint16_t a = synacor_memory_map_value(vm, argv[0]);

	synacor_stack_push(vm->stack, vm->pc);

	vm->pc = a;


	return 0;
}

int synacor_op_ret(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(argc); UNUSED(argv);

	int pop = synacor_stack_pop(vm->stack);

	if (pop >= 0)
	{
		vm->pc = (uint16_t) pop;
	} else {
		printf("Calling return with empty stack, halting.\n");
		vm->halted = 1;
	}

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

	uint16_t in = (uint16_t) getchar();

	uint16_t a = synacor_memory_map_register(argv[0]);

	vm->registers[a] = in;

	return 0;
}

int synacor_op_noop(synacor_vm* vm, uint8_t argc, uint16_t* argv) {
	UNUSED(vm);	UNUSED(argc); UNUSED(argv);
	return 0;
}
