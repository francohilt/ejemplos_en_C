#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_alarma(int);

int main(int argc, char ** argv)
{
	signal(SIGALRM, handle_alarma);
	printf("Pongo alarma para dentro de 5 seg\n");
	printf("y capturo la senial de alarma\n");
	alarm(5); // alarm se encarga de enviar una señal SIGALRM al proceso en sec segundos.
	printf("main(): envio SIGALRM dentro de 5 seg!\n");
	while(1);
	printf("main(): fin loop infinito\n");
	return 0;
}

void handle_alarma(int signal)
{
	printf("Ejecute handle_alarma(): signal = %d\n", signal);
}