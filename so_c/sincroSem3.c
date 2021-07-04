/*
	 Este ejemplo crea dos hilos cada uno tiene asociado el codigo de una funcion
	 se sincronizan para mostrar en pantalla el abecedario ordenado,
	 un hilo escribe en minusculas y el otro hilo escribe en mayusculas
	 Para la creacion de las letras mayusculas y minusculas se utilizan los codigos ascii
	 CON SINCRONIZACION Y UNA VARIABLE GLOBAL para la comunicacion
	entre los hilos (dato compartido)
	 linea de compilacion
	 cc hilos02.c -lpthread
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void hilo1(void);
void hilo2(void);

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER ;

char letra = 'A';

int main(void)
{
	 pthread_t h1, h2;
	 pthread_mutex_lock(&m2);
	 pthread_create(&h1,NULL,(void *)hilo1,NULL);
	 printf("hilo h1 creado \n");
	 pthread_create(&h2,NULL,(void *)hilo2,NULL);
	 printf("hilo h2 creado \n");
	 pthread_join(h1,NULL); // bloque al proceso padre de los hilos por la finalizacion del
	 hilo h1
	 printf("hilo h1 termino \n");
	 pthread_join(h2,NULL); // bloque al proceso padre de los hilos por la finalizacion del
	 hilo h2
	 printf("hilo h2 termino \n");
	 exit(0);
}

void hilo1(void)
{
while(letra <= 'y')
	{
		pthread_mutex_lock(&m1);
		letra = letra + 32 ;
		printf("hilo %d escribe la letra %c \n",pthread_self() , letra);
		letra = letra + 1 ;
		pthread_mutex_unlock(&m2);
		// sleep(1);
	}
}

void hilo2(void)
{
	do
	{
		pthread_mutex_lock(&m2);
		letra = letra - 32;
		printf("-------hilo %d escribe la letra %c \n",pthread_self() , letra);
		letra = letra + 1 ;
		pthread_mutex_unlock(&m1);
		// sleep(1);
	 } while(letra != 'Z'+1 );
}