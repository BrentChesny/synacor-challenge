/**
 * Definition of the synacor VM debuger.
 * 
 * @author Brent Chesny
 */
#ifndef SYNACOR_DEBUGGER_H__
#define SYNACOR_DEBUGGER_H__

#include <stdint.h>

#include "synacor_vm.h"

#define SYNACOR_N_BREAKPOINTS 10
#define SYNACOR_DEBUG_CMD_SIZE 1024

/**
 * Type definition of the synacor VM debugger
 */
typedef struct synacor_debugger
{
	synacor_vm* vm;

	/* Breakpoints */
	uint16_t breakpoints[SYNACOR_N_REGISTERS];
	uint8_t n_breakpoints;

	/* Flags */
	int flag_print;
} synacor_debugger;

/**
 * Initializes and returns an instance of the synacor debugger
 * @return synacor VM debugger
 */
synacor_debugger* synacor_debugger_init(synacor_vm* vm);

/**
 * Destroys the given debugger and frees the memory
 * @param debugger A synacor debugger instance
 */
void synacor_debugger_destroy(synacor_debugger* debugger);

/**
 * Runs the binary loaded in the VM of this debugger.
 * @param vm A synacor debugger instance
 * @return Status code 0 if halted succesfully, non-zero otherwise
 */
int synacor_debugger_run(synacor_debugger* debugger);

/**
 * Executes one operation of the loaded binary in the given VM of this debugger
 * @param vm A synacor debugger instance
 * @return Status code 0 if step executed succesfully, non-zero otherwise
 */
int synacor_debugger_step(synacor_debugger* debugger);

/**
 * Set breakpoints on the debugger that have been passed in via commandline arguments
 * @param debugger    A synacor debugger instance
 * @param breakpoints 	An array of memory addresses of where to put breakpoints
 * @param n 			The number of breakpoints
 */
void synacor_debugger_set_breakpoints(synacor_debugger* debugger, char* breakpoints[], int n);

#endif /* end of include guard: SYNACOR_DEBUGGER_H__ */
