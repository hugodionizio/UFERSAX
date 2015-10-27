#include "syslib.h"

int sys_setQuantum(proc, nr, quantum)
void * proc;
int nr;
int quantum;
{
    message m;

    m.I_ENDPT = SELF;
    m.I_VAL_PTR = proc;
    m.I_VAL_LEN2_E = nr;
    m.I_VAL_LEN = quantum;

    return(_kernel_call(SYS_SETQUANTUM, &m));
}
