/**
 * Definition of the synacor VM debuger.
 * 
 * @author Brent Chesny
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "synacor_debugger.h"
#include "synacor_memory.h"



/* Private functions */

int synacor_debugger_handle_cmd(synacor_debugger* debugger, char* cmd)
{
	if (strcmp(cmd, "\n") == 0) 
	{
		printf("Continuing!\n\n");
	}
	else if (strstr(cmd, "getreg") != NULL)
	{
		int regid;
		sscanf(cmd, "getreg $%d", &regid);
		printf("Value of register %d is: %u\n", regid, debugger->vm->registers[regid]);
	}
	else if (strstr(cmd, "setreg") != NULL)
	{
		int regid;
		int value;
		sscanf(cmd, "setreg $%d=%d", &regid, &value);
		printf("Setting register %d to value %d\n", regid, value);
		debugger->vm->registers[regid] = value;
	}
	else if (strstr(cmd, "jump") != NULL)
	{
		int addr;
		sscanf(cmd, "jump %d", &addr);
		printf("Jumping to address %d\n", addr);
		debugger->vm->pc = addr;
	}
	else if (strstr(cmd, "setflag print") != NULL)
	{
		debugger->flag_print = 1;
	}
	else
	{
		printf("Unknown debugger command!\n");
	}

	return (strstr(cmd, "&&") == NULL);
}

int synacor_debugger_at_breakpoint(synacor_debugger* debugger)
{
	for (int i = 0; i < debugger->n_breakpoints; ++i)
	{
		if (debugger->vm->pc == debugger->breakpoints[i])
			return 1;
	}

	return 0;
}

int synacor_debugger_break(synacor_debugger* debugger)
{
	// printf("\e[1;1H\e[2J");
	printf("Encountered breakpoint at address: %u\n", debugger->vm->pc);

	int done = 0;

	do {
		char *cmd = calloc(1, SYNACOR_DEBUG_CMD_SIZE);
		if (cmd == NULL) {
	    	printf("Debug error: failed to allocate memory for command!\n");
	    	return 1;
		}   

	    fgets(cmd, SYNACOR_DEBUG_CMD_SIZE, stdin);

	    done = synacor_debugger_handle_cmd(debugger, cmd);

	    free(cmd);
	} while(!done);

	return 0;
}


/* Public functions */

synacor_debugger* synacor_debugger_init(synacor_vm* vm)
{
	synacor_debugger* debugger = (synacor_debugger*) malloc(sizeof(synacor_debugger));

	debugger->vm = vm;
	debugger->flag_print = 0;

	return debugger;
}

void synacor_debugger_destroy(synacor_debugger* debugger)
{
	if (debugger != NULL) {
		free(debugger);
		debugger = NULL;
	}
}

int synacor_debugger_run(synacor_debugger* debugger)
{
	int status;

	synacor_memory_dump(debugger->vm);

	while(!debugger->vm->halted) {
		status = synacor_debugger_step(debugger);
	}

	return status;
}

int synacor_debugger_step(synacor_debugger* debugger)
{
	if (synacor_debugger_at_breakpoint(debugger))
		synacor_debugger_break(debugger);

	if (debugger->flag_print)
		synacor_vm_print_state(debugger->vm);

	int status = synacor_vm_step(debugger->vm);

	return status;
}

void synacor_debugger_set_breakpoints(synacor_debugger* debugger, char* breakpoints[], int n)
{
	if (n > SYNACOR_N_BREAKPOINTS)
	{
		printf("Number of breakpoints passed is higher than maximum breakpoints allowed. Skipping.\n");
		return;
	}

	debugger->n_breakpoints = n;

	for (int i = 0; i < n; ++i)
	{
		debugger->breakpoints[i] = atoi(breakpoints[i]);
	}
}
