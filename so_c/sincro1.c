#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *funhilo1();
void *funhilo2();

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER ;

char letra = 'A';

int main(int argc,char **argv)
{
	 pthread_t hilo1;
	 pthread_t hilo2;
	 pthread_mutex_lock(&m2);

	 pthread_create(&hilo1,NULL,funhilo1,NULL);
	 printf("main(): lanzo hilo1 \n");

	 pthread_create(&hilo2,NULL,funhilo2,NULL);
	 printf("main(): lanzo hilo2 \n");

	 pthread_join(hilo1,NULL);
	 printf("Hilo 1 : fin\n");

	 pthread_join(hilo2,NULL);
	 printf("Hilo 2 : fin\n");
	 return 0;
}

void *funhilo1()
{
	 while(letra <= 'y')
		 {
		 pthread_mutex_lock(&m1);
		 letra = letra + 32;
		 printf("Hilo 1 : %c\n",letra);
		 letra = letra + 1;
		 sleep(1);
		 pthread_mutex_unlock(&m2);
		 }
	pthread_exit(0);
}

void *funhilo2()
{
	do
	 {
		 pthread_mutex_lock(&m2);
		 letra = letra - 32;
		 printf(" Hilo 2 : %c\n",letra);
		 letra = letra + 1;
		 sleep(1);
		 pthread_mutex_unlock(&m1);
	 } while(letra != 'Z'+1);
	pthread_exit(0);
}