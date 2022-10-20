#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NAME_SIZE 20
#define NUM_THREADS 10

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
    Thread_data thread_data[NUM_THREADS];

    for (int i = 0; i != NUM_THREADS; ++i) {

        pthread_t thread_id;

        thread_data[i].thread_id = i;

        pthread_create(&thread_id, NULL, hello_world, (void *)&thread_data[i]);
    }

    pthread_exit(NULL);

    printf("Never executes\n");

    return EXIT_SUCCESS;
}
