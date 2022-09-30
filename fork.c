#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "Error: main: fork: %s\n", strerror(errno));
        return EXIT_FAILURE;
        
    } else if (pid == 0) {
        printf("Soy el proceso hijo con pid %u.\n", getpid());
        execl("/workspace/TC1004B.514/hello", "hello", NULL);
        sleep(5);
        
    } else {
        printf("Soy el proceso padre con pid %u.\n", getpid());
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
