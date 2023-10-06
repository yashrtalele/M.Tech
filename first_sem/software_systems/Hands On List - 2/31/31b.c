#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;
int counter=0;

void *thread(void *arg) {
    sem_wait(&sem);
    counter+=1;
    sem_post(&sem);
    return NULL;
}

void main(void) {
    pthread_t t1, t2;
    sem_init(&sem, 0, 2);
    if (pthread_create(&t1, NULL, thread, NULL)) {
        perror("pthread_create");
        exit(EXIT_SUCCESS);
    }
    if (pthread_create(&t2, NULL, thread, NULL)) {
        perror("pthread_create");
        exit(EXIT_SUCCESS);
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&sem);
    printf("counter = %d", counter);
}
