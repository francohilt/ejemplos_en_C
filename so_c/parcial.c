#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid ==0)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("A\n", );
		}
		else
		{
			wait(0);
			printf("B\n");
		}
	}
	else
	{
		wait(0);
		printf("C\n");
	}
	return 0;
}