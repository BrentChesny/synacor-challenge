/**
 * Definition of the synacor VM.
 * 
 * @author Brent Chesny
 */
#ifndef SYNACOR_VM_H__
#define SYNACOR_VM_H__

#include <stdint.h>

#include "synacor_stack.h"

#define SYNACOR_ADDRESS_SPACE_SIZE 32767
#define SYNACOR_N_REGISTERS 8
#define SYNACOR_CHUNK_SIZE 1024

/**
 * Type definition of the synacor VM struct
 */
typedef struct synacor_vm
{
	uint16_t memory[SYNACOR_ADDRESS_SPACE_SIZE];
	uint16_t registers[SYNACOR_N_REGISTERS];
	uint16_t pc;
	synacor_stack* stack;
	int halted;
} synacor_vm;

/**
 * Initializes and returns an instance of the synacor VM
 * @return synacor VM instance
 */
synacor_vm* synacor_vm_init();

/**
 * Runs the binary loaded in the given VM.
 * @param vm A synacor VM instance
 * @return Status code 0 if halted succesfully, non-zero otherwise
 */
int synacor_vm_run(synacor_vm* vm);

/**
 * Executes one operation of the loaded binary in the given VM
 * @param vm A synacor VM instance
 * @return Status code 0 if step executed succesfully, non-zero otherwise
 */
int synacor_vm_step(synacor_vm* vm);

/**
 * Kills the given VM
 * @param vm A synacor VM instance
 */
void synacor_vm_kill(synacor_vm* vm);

/**
 * Destroys the given VM and frees the memory
 * @param vm A synacor VM instance
 */
void synacor_vm_destroy(synacor_vm* vm);

/**
 * Read the next instruction and it's arguments from memory 
 * @param  vm 	A synacor VM instance
 * @param  argc Out parameter for the argument count
 * @param  argv Out parameter for the argument values
 * @return      Returns the opcode of the next instruction, -1 if invalid instruction
 */
uint16_t synacor_vm_read_op(synacor_vm* vm, uint8_t* argc, uint16_t* argv);

#endif /* end of include guard: SYNACOR_VM_H__ */
