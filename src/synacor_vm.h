#ifndef SYNACOR_VM_H__
#define SYNACOR_VM_H__

#include <stdint.h>

#define ADDRESS_SPACE_SIZE 32767
#define N_REGISTERS 8
#define CHUNK_SIZE 1024

/**
 * Type definition of the synacor VM struct
 */
typedef struct synacor_vm
{
	uint16_t memory[ADDRESS_SPACE_SIZE];
	uint16_t registers[N_REGISTERS];
	uint16_t pc;
	// TODO add stack to vm
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

#endif /* end of include guard: SYNACOR_VM_H__ */
