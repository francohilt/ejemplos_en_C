#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	printf("Soy %d y mi padre es %d\n", getpid(), getppid());
	printf("\nH\n");
	pid = fork();

	if (pid == 0)
	{
		printf("Soy %d y mi padre es %d\n", getpid(), getppid());		
		printf("Z\n");
		pid_t pid2 = fork();
		if (pid2 == 0)
		{
			printf("Soy %d y mi padre es %d\n", getpid(), getppid());
			printf("M\n");
		}
		else
		{
			wait(NULL);
			pid_t pid3 = fork();
			if (pid3 == 0)
			{
				printf("Soy %d y mi padre es %d\n", getpid(), getppid());
				printf("X\n");
			}
			else
			{
				wait(NULL);
			}
		}
	}
	else
	{
		wait(NULL);
		pid_t pid4 = fork();
		if (pid4 == 0)
		{
			printf("Soy %d y mi padre es %d\n", getpid(), getppid());
			printf("Y\n");
		}
		else
		{
			wait(NULL);
			printf("\n");
		}
	}
	exit(0);
}