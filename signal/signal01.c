#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char ** argv)
{
	signal(SIGINT, SIG_IGN);
	printf("main(): Ingreso en loop infinito CTRL+C IGNORADO!\n");
	while(1);
	printf("main(): fin loop infinito\n");
	return 0;
}

/*
	Para detener el proceso por consola:
		kill -SIGKILL pid

	Para podes visualizar los pids de los procesos que estan corriendo,
	desde otra consola:
		ps -lax
*/

