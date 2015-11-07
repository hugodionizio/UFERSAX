#include <lib.h>

#include <unistd.h>

int setprio(pid_t process, int priority) {

	message m;

	m.m1_i1 = process;
	m.m1_i2 = priority;

	return ( _syscall(PM_PROC_NR, SETPRIO, &m));
}
