#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void hello(int signal)
{
    printf("Received signal %d\n", signal);
}

int condition = 0;

void terminate(int signal)
{
    printf("Terminating while\n");

    condition = 0;
}

int main(int argc, char *argv[])
{
    signal(2, hello);
    signal(12, terminate);

    condition = 1;

    while (condition) {
        printf("Executing\n");

        sleep(1);
    }

    printf("This is never executed\n");

    return EXIT_SUCCESS;
}
