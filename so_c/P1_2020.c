#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	int i = 0;
	pid_t pid;

	while (i <= 5) {
		pid = fork();
		if (pid == 0) break;
	//wait(0);
        i++;
	}
	printf("pid de mi padre:[%d] - mi pid:[%d] - mi valor de i:[%d]\n", getppid(), getpid(), i);
	exit(0);
}
