/**
 * Definition of a stack datatype for the synacor VM
 * 
 * @author Brent Chesny
 */

#ifndef SYNACOR_STACK_H__
#define SYNACOR_STACK_H__

#include <stdint.h>

#define SYNACOR_STACK_SIZE 10000000

typedef struct synacor_stack
{
	uint16_t values[SYNACOR_STACK_SIZE]; // TODO make stack size dynamic
	uint32_t sp;
} synacor_stack;

/**
 * Pushes a value onto the given stack
 * @param stack The stack to push to value onto
 * @param value The value to push onto the stack
 */
void synacor_stack_push(synacor_stack* stack, uint16_t value);


/**
 * Pops a value of the given stack
 * @param  stack The stack to pop
 * @return       A negative value when popping an empty stack, the popped value otherwise
 */
int synacor_stack_pop(synacor_stack* stack);


#endif /* end of include guard: SYNACOR_STACK_H__ */
