#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_alarma(int);

int main(int argc, char ** argv)
{
	signal(SIGINT, SIG_IGN); // ignoro CTRL+C
	signal(SIGALRM, handle_alarma);
	alarm(10); 
	printf("Durante los primeros 10 seg ignoro a SIGINT !!\n");
	printf("despues de los 10 seg usted puede hacer CTRL+C !!\n");
	printf("main(): envio SIGALRM dentro de 5 seg!\n");
	while(1);
	printf("main(): fin loop infinito\n");
	return 0;
}

void handle_alarma(int signo)
{
	printf("Ejecute handle_alarma(): signal = %d\n", signo);
	printf("Ahora puede hacer CTRL+C para finalizar !!\n");
	signal(SIGINT, SIG_DFL); // que haga la acción x defecto para CTRL+C
}