#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status = 0;
    int i = 0;

    while (i <= 5)
    {
        pid = fork();
        if (pid > 0) break;
    i++;
    }

    wait(&status);
    printf("Mi padre es %d y yo soy %d | i = %d\n", getppid(), getpid(), i);
    printf("Mi hijo termino y me envio un %d\n", (status/256));
    exit(i);
}
