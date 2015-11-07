#include <lib.h>
//#define setprio do_setprio
#include <unistd.h>

// função com modificador PUBLIC
int setprio(int this_pid, int this_priority) {

	message m;

//	sys_nice(this_pid, this_priority);

	m.m1_i1 = this_pid;
	m.m1_i2 = this_priority;

	return ( _syscall(PM_PROC_NR, SETPRIO, &m));
}
