#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) == 0) {
        printf("Soy el proceso hijo con este id %u.\n", pid);

        execl("/workspace/TC1004B.514/hello", "hello", NULL);

        sleep(5);
    }
    else {
        printf("Soy el proceso padre con este id %u.\n", getpid());

        wait(NULL);
    }

    return EXIT_SUCCESS;
}
