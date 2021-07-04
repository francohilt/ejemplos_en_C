#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char ** argv)
{
	signal(SIGDFL, SIG_DFL);
	printf("main(): Ingreso en loop infinito CTRL+C x defecto!\n");
	while(1);
	printf("main(): fin loop infinito\n");
	return 0;
}