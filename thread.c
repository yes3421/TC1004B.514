#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NAME_SIZE 20

typedef struct thread_data {
    int thread_id;

    char name[NAME_SIZE];

} Thread_data;

void *hello_world(void *arg)
{
    Thread_data *data = (Thread_data*)arg;

    printf("Hello from thread %d\n", data->thread_id);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    for (int i = 0; i != 100; ++i) {
        Thread_data data;

        pthread_t thread_id;

        data.thread_id = i;

        pthread_create(&thread_id, NULL, hello_world, (void *)&data);
    }

    pthread_exit(NULL);

    printf("Never executes\n");

    return EXIT_SUCCESS;
}
