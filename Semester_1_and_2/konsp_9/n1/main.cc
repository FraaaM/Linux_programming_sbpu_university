#include <iostream>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>

int main() {
	
	pid_t v = getpid(); //идентификатор процесса (PID) текущего процесса
	pid_t sys_v = syscall(SYS_gettid); //идентификатор потока (TID) текущего процесса 
	std::cout << v << std::endl << sys_v  << std::endl;

	return 0;
}
//PID - это уникальный идентификатор процесса, а TID - это уникальный идентификатор потока внутри процесса.
