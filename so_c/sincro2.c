#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *funhilo1();

void *funhilo2();

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

int main(int argc,char *argv[])
{
	 pthread_t hilo1;
	 pthread_t hilo2;

	 pthread_mutex_lock(&m2);

	 pthread_create(&hilo1,NULL,funhilo1,NULL);
	 printf(" hilo 1 creado \n");

	 pthread_create(&hilo2,NULL,funhilo2,NULL);
	 printf(" hilo 2 creado \n");

	 pthread_create(&hilo3,NULL,funhilo3,NULL);
	 printf(" hilo 3 creado \n");

	 pthread_join(hilo1,NULL);
	 printf(" hilo 1 terminado \n");

	 pthread_join(hilo2,NULL);
	 printf(" hilo 2 terminado \n");

	 pthread_join(hilo3,NULL);
	 printf(" hilo 3 terminado \n");

	 printf(" Creador pid=%d termina \n",getpid());
	 exit(0);
}

void * funhilo1()
{
	 char letra = 'a';
	 while(letra <= 'y')
	 {
		 pthread_mutex_lock(&m1);
		 printf(" hilo 1 %d escibe %c \n",pthread_self(),letra);
		 letra = letra + 2;
		 pthread_mutex_unlock(&m2);
	 }
	 pthread_exit(0);
}

void * funhilo2()
{
	 char letra = 'B';
	 while(letra <= 'Z')
	 {
		 pthread_mutex_lock(&m2);
		 printf(" hilo 2 %d escibe %c \n",pthread_self(),letra);
		 letra = letra + 2;
		 pthread_mutex_unlock(&m1);
	 }
	 pthread_exit(0);
}