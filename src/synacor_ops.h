#ifndef SYNACOR_OPS_H__
#define SYNACOR_OPS_H__

#include <stdint.h>

#include "synacor_vm.h"

#define MAX_OP 21

/**
 * Definition of different opcodes
 */
#define OP_HALT 0
#define OP_SET 1
#define OP_PUSH 2
#define OP_POP 3
#define OP_EQ 4
#define OP_GT 5
#define OP_JMP 6
#define OP_JT 7
#define OP_JF 8
#define OP_ADD 9
#define OP_MULT 10
#define OP_MOD 11
#define OP_AND 12
#define OP_OR 13
#define OP_NOT 14
#define OP_RMEM 15
#define OP_WMEM 16
#define OP_CALL 17
#define OP_RET 18
#define OP_OUT 19
#define OP_IN 20
#define OP_NOOP 21

/**
 * Lookup table for the number of arguments for each opcode
 */
extern uint8_t synacor_op_args[];

/**
 * Table with function pointers to the op implementations
 */
extern int (*synacor_ops[]) (synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the halt op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_halt(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the set op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_set(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the push op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_push(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the pop op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_pop(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the eq op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_eq(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the gt op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_gt(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the jmp op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_jmp(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the jt op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_jt(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the jf op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_jf(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the add op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_add(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the mult op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_mult(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the mod op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_mod(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the and op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_and(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the or op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_or(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the not op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_not(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the rmem op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_rmem(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the wmem op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_wmem(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the call op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_call(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the ret op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_ret(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the out op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_out(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the in op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_in(synacor_vm* vm, uint8_t argc, uint16_t* argv);

/**
 * Implementation of the noop op
 * @param  vm   The VM to operate on
 * @param  argc The number of arguments for this op
 * @param  argv The values of the arguments for this op
 * @return      Status code 0 if succesfully executed, non-zero otherwise
 */
int synacor_op_noop(synacor_vm* vm, uint8_t argc, uint16_t* argv);



#endif /* end of include guard: SYNACOR_OPS_H__ */
