/*
     Proceso que imprime el abecedario, imprime una letra
     por cada vez que recibe la senial SIGUSR1
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_user1(int);
char letra='a';
int hice_abcedario = 0; // false

int main(int argc, char **argv)
{
	signal(SIGUSR1,handle_user1);
	printf("Imprimo una letra del abcedario por cada vez que recibo SIGUSR1!!\n");
	while(!hice_abcedario) pause;
	printf("main(): fin loop infinito!\n");
	return 0;
}

// handle o manipulador para SIGUSR1
void handle_user1(int signo) {
	if ( letra <= 'z' ) {
		printf("%c\n",letra);
		letra++;
	} else {
		hice_abcedario=1; // true
	}
}