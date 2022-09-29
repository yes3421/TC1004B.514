#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid == 0) {
        printf("Soy el proceso hijo.\n");

        execl("/workspace/TC1004B.514/hello", "hello", NULL);

        sleep(5);
    }
    else {
        printf("Soy el proceso padre.\n");

        wait(NULL);
    }

    return EXIT_SUCCESS;
}
