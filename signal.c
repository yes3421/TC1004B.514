#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void hello(int signal)
{
    printf("Received signal %d\n", signal);
}

int main(int argc, char *argv[])
{
    signal(2, hello);
    signal(12, hello);

    while (1) {
        printf("Executing\n");

        sleep(1);
    }

    printf("This is never executed\n");

    return EXIT_SUCCESS;
}
