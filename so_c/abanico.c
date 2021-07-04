#include <stdio.h>
#include <stdlib.h>
#include <unist.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int i;

	for (i = 0; i < atoi(argv[1]); i++)
	{
		pid = fork();
		if (pid == 0) break;
	}
	while (wait(0) != -1);
	printf("Soy %d hijo de %d el valor de variable pid %d el valor de mi variable i es %d\n", getpid(), getppid(), pid, i);
	exit(0);
}
