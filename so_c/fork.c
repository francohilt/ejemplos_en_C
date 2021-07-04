#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// int main(void)
// {
// 	pid_t pid;
// 	pid = fork();
// 	if (pid == 0) // Hijo
// 		printf("Soy el hijo %d mi padre es %d\n", getpid(), getppid());
// 	else
// 		if (pid > 0) // Padre
// 			printf("Soy el padre %d y mi hijo es %d y mi padre es %d\n", getpid(), pid, getppid());
// 		else
// 			printf("fork fallo\n");
// 	return 0;
// }

// Cuando tenemos un "1" donde un proceso informa cual es 
// su padre: El proceso(hijo) se convirtio en huerfano.
// Para evitarlo hay que lograr que el padre no termine
// antes que el hijo.

// SOLUCIÓN:
// Funcion wait:
// Suspende la ejecucion del proceso actual hasta que un proceso
// hijo ha terminado.

int main(void)
{
	pid_t pid, hijoter;
	int status = 0;
	pid = fork();
	if (pid == 0) // Hijo
	{
		printf("Soy el hijo %d mi padre es %d\n",getpid(), getppid());
		sleep(5);
		printf("Termino ya\n");
		exit(7); // Le envia una señal al proceso padre.
	}
	else
		if (pid > 0) // Padre
		{
			printf("Soy el padre %d y mi hijo es %d y mi padre es %d\n",getpid(), pid, getppid());
			printf("Padre esperando la terminacion del hijo\n");
			hijoter = wait(&status); // El padre guarda en status la señal que le envia el hijo.
			printf("Termino mi hijo %d\n",hijoter); 
			//printf("Mi hijo termino y me envio un %d\n",WEXITSTATUS(status));
			printf("Mi hijo termino y me envio un %d\n",(status/256));

		}
		else
			printf("fork fallo\n");
		exit(6); // Le envia una señal al proceso padre (osea al Shell)
}


