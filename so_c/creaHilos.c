#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
	Ejemplo simple de procesos livianos (threads) hilos
	compilar como:
	cc creaHilos.c -lpthread
	ejecutar con argumento de entrada
	por ejemplo
	./a.out 5
*/

void *hilo();

int main(int argc,char **argv)
{
	 int canthilos = atoi(argv[1]) ;
	 int i ;
	 pthread_t hilos[300];

	 for ( i = 0 ; i < canthilos ; i++)
	 {
		 pthread_create(&hilos[i],NULL,hilo,NULL); // crea los hilos
		 printf("main(): lanzo hilo i=%d \n",i);
	 }

	 for ( i = 0 ; i < canthilos ; i++)
	 {
		 pthread_join(hilos[i],NULL); // espera que terminen todos los hilos (wait)
		 printf("Hilo i=%d fin\n", i);
	 }

		printf("main(): fin\n");
		exit(0);
}

void *hilo()
{
	char letra = 'a';
	while(letra <= 'z')
	 {
		 printf(" %c escrita por el hilo %d\n",letra,pthread_self());
		 letra=letra+1;
		 sleep(1);
	 }
	pthread_exit(0);
}