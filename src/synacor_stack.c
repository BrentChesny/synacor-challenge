/**
 * Implementation of the stack datatype for the synacor VM
 * 
 * @author Brent Chesny
 */
#include <stdio.h>

#include "synacor_stack.h"

void synacor_stack_push(synacor_stack* stack, uint16_t value)
{
	if (stack->sp == SYNACOR_STACK_SIZE)
		printf("Error: stackoverflow while pushing!\n");
	else
		stack->values[stack->sp++] = value;
}


int synacor_stack_pop(synacor_stack* stack)
{
	if (stack->sp == 0) 
	{
		printf("Error: popping empty stack!\n");
		return -1;
	}
	else
	{
		return stack->values[--stack->sp];
	}
}
