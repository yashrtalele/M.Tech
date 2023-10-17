/*
============================================================================
Name : 32a.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to implement semaphore to protect any critical section.    a. rewrite the ticket number creation program using semaphore    b. protect shared memory from concurrent write access    c. protect multiple pseudo resources ( may be two) using counting semaphore    d. remove the created semaphore  
Date: 12th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_TICKETS 50

int ticket_counter = 1;
sem_t mutex;

void* sellTicket(void* arg) {

    while (1) {
        sem_wait(&mutex); 
        if (ticket_counter <= NUM_TICKETS) {
            ticket_counter++;
            printf("Ticket %d sold.\n", ticket_counter);
        }
        sem_post(&mutex);

        if (ticket_counter > NUM_TICKETS) break;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t seller1, seller2;

    sem_init(&mutex, 0, 1);

    pthread_create(&seller1, NULL, sellTicket, NULL);
    pthread_create(&seller2, NULL, sellTicket, NULL);

    pthread_join(seller1, NULL);
    pthread_join(seller2, NULL);

    sem_destroy(&mutex);

    return 0;
}
