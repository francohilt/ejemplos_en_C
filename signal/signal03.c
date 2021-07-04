#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_ctrl_c(int);

int main(int argc, char ** argv)
{
	signal(SIGDFL, handle_ctrl_c);
	printf("main(): Ingreso en loop infinito CTRL+C interceptado!\n");
	while(1);
	printf("main(): fin loop infinito\n");
	return 0;
}

// handle o manipulador para la senial CTRL+C
void handle_ctrl_c(int signal)
{
	printf("Ejecute handle_ctrl_c(): signal = %d\n", signal);
}