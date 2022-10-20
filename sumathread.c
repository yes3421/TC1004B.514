#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 10

int salary;

sem_t protection_salary;

void *sum(void *arg)
{
    sem_wait(&protection_salary);

    printf("The initial salary is %d\n", salary);

    salary += 100;

    printf("The salary after is %d\n", salary);

    sem_post(&protection_salary);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    salary = 0;

    pthread_t threads_info[NUM_THREADS];

    sem_init(&protection_salary, 0, 1);

    for (int i = 0; i != NUM_THREADS; ++i) {
        pthread_create(&threads_info[i], NULL, sum, NULL);
    }

    for (int i = 0; i != NUM_THREADS; ++i) {
        pthread_join(threads_info[i], NULL);
    }

    printf("El final es %d\n", salary);

    pthread_exit(NULL);

    printf("Never executes\n");

    return EXIT_SUCCESS;
}
