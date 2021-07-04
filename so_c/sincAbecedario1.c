// Sincronizamos un proceso padre y su proceso hijo 
// para que cooperen en la escritura del abecedario en un archivo,
// escribiendo una letra cada uno.

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int fd = open("abecedario", O_CREAT|O_WRONLY|O_TRUNC, 0600);
	char letra = 'a';
	pid = fork();
	if (pid > 0) // Padre
	{
		while (letra <= 'z')
		{
			write(fd, &letra, 1);
			letra+=2;
			sleep(1); // No se debe usar para sincronizar.
		}
	}
	else
		if (pid == 0) // Hijo
		{
			letra = 'B';
			while (letra <= 'Z')
			{
				write(fd, &letra, 1);
				letra+=2;
				sleep(1); // No se debe usar para sincronizar.
			}
		}
		else
			perror("error fork()\n")
		close(fd);
		return 0;
}
