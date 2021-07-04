#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/* 
	padre (bash) --> hijo 1
		  		 --> hijo 2 --> hijo 3 (nieto del padre) --> hijo 4 (visnieto del padre)
*/

int main(void)
{
	pid_t pid; // Identificador de proceso
	pid = fork(); // padre

	if (pid == 0)
	{
		// hijo 1
		printf("Soy el hijo 1 %d y mi padre es %d\n", getpid(), getppid());
	}
	else
	{
		// padre
		pid = fork();
		if (pid == 0)
		{
			// hijo 2
			pid = fork();
			if (pid == 0)
			{
				// hijo 3
				printf("Soy el hijo 3 %d y mi padre es %d\n", getpid(), getppid());
				pid = fork();
				if (pid == 0)
				{
					//hijo 4
					printf("Soy el hijo 4 %d y mi padre es %d\n", getpid(), getppid());
				}
				else
				{	//hijo 4
					wait(0);
				}
			}
			else
			{
				// hijo 2
				wait(0); // hace un wait porque tiene un hijo.
				printf("Soy el hijo 2 %d y mi padre es %d\n", getpid(), getppid());
			}
		}
		else
		{
			// padre
			wait(0); // hace dos wait porque tiene dos hijos.
			wait(0);
			printf("Soy el padre %d y mi padre es %d\n", getpid(), getppid());
		}
	}
	exit(0);
}