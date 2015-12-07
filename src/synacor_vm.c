#include <stdlib.h>

#include "synacor_vm.h"

synacor_vm* init_vm()
{
	synacor_vm* vm = (synacor_vm*) malloc(sizeof(synacor_vm));

	return vm;
}
