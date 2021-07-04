/*
	Pseudo-Código para la comprensión de "Condition Variables" 
	en un entorno multithreading
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
	variable compartida v1
	declaro mutex m1
	declaro condvar cv1
*/

void *hilo1();
void *hilo2();
void *hilo3();

int miglob = 0;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c1 = PTHREAD_COND_INITIALIZER;

pthread_t h1, h2, h3;

/*
	main()
		inicializo m1  -- Ambos en la practica se inicializan
		inicializo cv1 -- fuera del main, como en este ejemplo.

		lanzo thr1
		lanzo thr2

		join thr1
		join thr2
	fin main()
*/

int main(void)
{
	printf("main(): lanzo hilo 1! \n");
	pthread_create(&h1, NULL, hilo1, NULL);

	printf("main(): lanzo hilo 2! \n");
	pthread_create(&h2, NULL, hilo2, NULL);
    
    printf("main(): lanzo hilo 3! \n");
	pthread_create(&h3, NULL, hilo3, NULL);

	printf("main(): espera por fin de hilo 1 , hilo 2 e hilo 3\n");

	pthread_join(h1, NULL);
	pthread_join(h2, NULL);
    pthread_join(h3, NULL);

	printf("main(): fin! \n");
	return 0;
}

/*
	thr1()
		mientras proceso
			lock m1
				seccion critica(modifico v1)
				si condicion entonces
					señalo cv1
				fin si
			unlock m1
		fin mientras
	fin thr1()
*/

void *hilo1()
{
	int n = 15;
	while(n)
	{
		pthread_mutex_lock(&m1);
		miglob++;
		printf("hilo(): n = %d miglob = %d\n",n, miglob);
		if ((miglob % 5) == 0)
		{
			pthread_cond_signal(&c1); // libero cond c1
			printf("hilo(): signal \n");
		}
		n--;
		pthread_mutex_unlock(&m1);
		sleep(1);
	}
	pthread_cancel(h2);
	printf("hilo 1(): fin! \n");
	pthread_exit(0);
}

/*
	thr2()
		mientras proceso
			lock m1
				si no condicion entonces
					espero cv1
				fin si
				seccion critica
			unlock m1
		fin mientras
	fin thr2()
*/
/*
void *hilo2()
{
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	while(1)
	{
		pthread_mutex_lock(&m1);
		if ((miglob % 5) != 0 || miglob == 0)
			pthread_cond_wait(&c1, &m1); // espera signal bloqueado
		printf("................hilo 2(): miglob = %d\n",miglob);
		pthread_mutex_unlock(&m1);
		sleep(1);
	}
	printf("hilo 2(): fin! \n");
	pthread_exit(0);
}
*/

void *hilo2()
{
	int n = 15;
	while(n)
	{
		pthread_mutex_lock(&m1);
		miglob++;
		printf("hilo2(): n = %d miglob = %d\n",n, miglob);
		if ((miglob % 5) == 0)
		{
			pthread_cond_signal(&c1); // libero cond c1
			printf("................hilo2(): signal \n");
		}
		n--;
		pthread_mutex_unlock(&m1);
		sleep(1);
	}
	pthread_cancel(h3);
	printf("hilo 2(): fin! \n");
	pthread_exit(0);
}



void *hilo3()
{
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	while(1)
	{
		pthread_mutex_lock(&m1);
		if ((miglob % 5) != 0 || miglob == 0)
			pthread_cond_wait(&c1, &m1); // espera signal bloqueado
		printf("...............................................hilo 3(): miglob = %d\n",miglob);
		pthread_mutex_unlock(&m1);
		sleep(1);
	}
	printf("hilo 3(): fin! \n");
	pthread_exit(0);
}
