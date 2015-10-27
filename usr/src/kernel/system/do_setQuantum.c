#include <string.h>

#include "kernel/system.h"

#include "kernel/kernel.h"
#include "vm.h"
#include "arch_proto.h"

/*===========================================================================*
  *                                do_setQuantum                                  *
  *===========================================================================*/
int do_setQuantum(struct proc * caller, message * m_ptr)
{
	int nr_e,nr,r = 1;

	int wipe_rnd_bin = -1;

	int quantum = m_ptr->I_VAL_LEN;

	nr_e = (m_ptr->I_VAL_LEN2_E == SELF) ?
	caller->p_endpoint : m_ptr->I_VAL_LEN2_E;

	if(!isokendpt(nr_e, &nr)) return EINVAL; /* validate request */
	size_t length = sizeof(struct proc);
	vir_bytes src_vir = (vir_bytes) proc_addr(nr);

	struct proc * pr = proc_addr(nr);

	printf("%d",nr);

	if( nr < 0 )
	{
		printf("*");
		pr->p_quantum_size_ms = quantum;

		r = data_copy_vmcheck(pr, KERNEL, src_vir, pr->p_endpoint,
			(vir_bytes) m_ptr->I_VAL_PTR, length);
	}


	if(r != OK) return r;

	if(wipe_rnd_bin >= 0 && wipe_rnd_bin < RANDOM_SOURCES) {
		krandom.bin[wipe_rnd_bin].r_size = 0;
		krandom.bin[wipe_rnd_bin].r_next = 0;
	}

	  return(OK);
}
