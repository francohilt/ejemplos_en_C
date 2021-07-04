#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	pid = fork();
	pid = fork();
	printf("Soy el hijo %d y mi padre es %d\n", getpid(), getppid());
	wait(0);
	wait(0);
	wait(0);
	return 0;
}