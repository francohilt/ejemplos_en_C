/*
	Ejemplo simple de procesos livianos (threads) hilos
	Secuencia de hilos ABAB... sin datos compartidos
	Este ejemplo escribe el abecedario en pantalla
	Utiliza sincronizacion con semforos POSIX
	Hilo A escribe la letra 'a'
	Hilo B escribe la letra 'B'
	Hilo A escribe la letra 'c'
	Hilo B escribe la letra 'D'
	Hasta la 'Z'
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void hiloA(void);
void hiloB(void);

sem_t sema, semb;

int main(int argc,char **argv)
{
	// Inicialización de los semaforos
	sem_init(&sema,0,1); // sema --> 1
	sem_init(&semb,0,0); // semb --> 0

	pthread_t hA,hB;
	printf("main(): lanzo hiloA!\n");
	pthread_create(&hA,NULL,(void*)&hiloA,NULL);

	printf("main(): lanzo hiloB!\n");
	pthread_create(&hB,NULL,(void*)&hiloB,NULL);

	printf("main(): espera por fin de hiloA!\n");
	pthread_join(hA,NULL);

	printf("main(): espera por fin de hiloB!\n");
	pthread_join(hB,NULL);

	printf("main(): fin!\n");
	return 0;
}

void hiloA(void)
{
	 char letra = 'a';
	 while(letra <= 'y')
	 {
		 sem_wait(&sema); // Inicialmente vale 1, lo deja en 0
		 printf("hiloA escribe %c \n",letra);
		 letra = letra + 2;
		 sem_post(&semb); // Le suma 1 al sefamoro posix semb y lo "habilita"
	 }
}

void hiloB(void)
{
	 char letra = 'B';
	 while(letra <= 'Z')
	 {
		 sem_wait(&semb); 
		 printf("-----hiloB escribe %c \n",letra);
		 letra = letra + 2;
		 sem_post(&sema); // Le suma 1 al sefamoro posix sema y lo "habilita"
	 }
}
