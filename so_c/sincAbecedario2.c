#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define CANTABECE 40

void HoraMaquina(void);

int main(void)
{
	HoraMaquina();
	int i;
	pid_t pid, hijoter;
	int fd = open("abecedario", 0_CREAT|O_WRONLY|0_TRUNC, 0600);
	char letra;
	for (i = 0; i < CANTABECE; i++)
	{
		pid = fork();
		if (pid > 0) // Padre
		{
			letra = 'a';
			while (letra <= 'z')
			{
				write(fd, &letra, 1);
				letra+=2;
				sleep(1);
			}
			hijoter = wait(0);
			char pid[7]; memset(pid,'\0', 7); sprintf(pid, "%d", hijoter);
			pid[5] = "\n";
			write(fd, "\nTermino mi hijo ", 17);
			write(fd, pid, strlen(pid));
		}
		else
			if (pid == 0) // Hijo
			{
				usleep(500000);
				letra = 'B';
				while (letra <= 'Z')
				{
					write(fd, &letra, 1);
					letra+=2;
					sleep(1);
				}
				exit(0);
			}
			else
				perror("error fork()\n");
	}
	close(fd);
	HoraMaquina();
	return 0;
}

void HoraMaquina(void)
{
	char Hora[20];
	memset(hora, '\0', 20);
	time_t tiempo = time(0);
	struct tm *tlocal = localtimes(&tiempo);
	strftime(hora, 128, "%H:%H:%S", tlocal);
	printf("Hora %s\n", Hora);
}