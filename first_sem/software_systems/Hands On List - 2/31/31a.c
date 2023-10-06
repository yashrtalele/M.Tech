/* 
Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;
int shared_var=0;

void *thread(void *arg) {
    int *shared_var_ptr=(int *)arg;
    sem_wait(&sem);
    printf("Inside thread...\n");
    printf("Making changes...\n");
    *shared_var_ptr+=1;
    sem_post(&sem);
    return NULL;
}

void main(void) {
    pthread_t t1, t2;
    sem_init(&sem, 0, 1);
    if (pthread_create(&t1, NULL, thread, (void *)&shared_var)) {
        perror("pthread_create");
        exit(EXIT_SUCCESS);
    }
    if (pthread_create(&t2, NULL, thread, (void *)&shared_var)) {
        perror("pthread_create");
        exit(EXIT_SUCCESS);
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&sem);
    printf("shared_var = %d\n", shared_var);
}
