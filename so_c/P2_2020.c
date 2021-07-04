#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, hijoter;
    int status = 0;
    int i = 0;
    while (i <= 5)
    {
        pid = fork();
        if (pid > 0) // Padre
        {
            hijoter = wait(&status); 
            printf("Termino mi hijo %d\n",hijoter);
            break;
        }
    i++;
    }
    printf("Mi padre es %d y yo soy %d | i = %d\n", getppid(), getpid(), i);
    exit(0);
}