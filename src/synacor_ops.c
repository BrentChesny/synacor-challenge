#include "synacor_ops.h"

uint8_t synacor_op_args[] =	{
								0, 2, 1, 1, 3, 3, 	// halt, set, push, pop, eq, gt
								1, 2, 2, 3, 3, 3, 	// jmp, jt, jf, add, mult, mod
								3, 3, 2, 2, 2, 1, 	// and, or, not, rmem, wmem, call
								0, 1, 1, 0 			// ret, out, in, noop
							};
