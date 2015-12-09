/**
 * Definition of the synacor memory operations
 * 
 * @author Brent Chesny
 */
#ifndef SYNACOR_MEMORY_H__
#define SYNACOR_MEMORY_H__

#include "synacor_vm.h"

#define SYNACOR_MAX_LITERAL_VALUE 32767

/**
 * Load a binary into a synacor VM instance
 * @param  vm          The VM to load the binary into
 * @param  binary_name The name of the binary file
 * @return             Status code 0 if succesfull, non-zero otherwise
 */
int synacor_memory_load_binary(synacor_vm* vm, char* binary_name);

/**
 * Maps a 16-bit value to either its literal value or the value of the register it refers to
 * @param  vm    The VM we're working in
 * @param  value The value to map
 * @return       The mapped value
 */
uint16_t synacor_memory_map_value(synacor_vm* vm, uint16_t value);

/**
 * Maps a 16-bit value to either its register index
 * @param  value The value to map
 * @return       The index of the register the given value maps to
 */
uint16_t synacor_memory_map_register(uint16_t value);

/**
 * Dumps the disassembled memory of given VM to file
 * @param vm A synacor VM instance
 */
void synacor_memory_dump(synacor_vm* vm);

#endif /* end of include guard: SYNACOR_MEMORY_H__ */
