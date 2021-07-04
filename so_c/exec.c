#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// Familias de funciones EXEC:
// Permite cambiar la imagen binaria ejecutable de un proceso.

int main(void) //int main(int argc, char * argv[]) --> Para pasar un string por la terminal
{
	pid_t pid, hijoter;
	pid = fork();
	if (pid == 0) // Hijo
	{
		printf("Soy el hijo %d mi padre es %d\n",getpid(), getppid());
		printf("Me convierto en otra cosa\n");
		execl("./otracosa","./otracosa"); // Ejecuta el codigo binario llamado "otracosa".
		// execl(argv[1],argv[1],0) --> Para pasarle al execl lo que escribimos en la terminal.
		exit(7); // Le envia una señal al proceso padre.
	}
	else
		if (pid > 0) // Padre
		{
			printf("Soy el padre %d y mi hijo es %d y mi padre es %d\n",getpid(), pid, getppid());
			printf("Padre dice: estoy esperando la terminacion de mi hijo\n");
			hijoter = wait(&status); // El padre guarda en status la señal que le envia el hijo.
			printf("Termino mi hijo %d\n",hijoter); 
			printf("Mi hijo termino y me envio un %d\n",WEXITSTATUS(status));

		}
		else
			printf("fork fallo\n");
		exit(6); // Le envia una señal al proceso padre (osea al Shell)
}