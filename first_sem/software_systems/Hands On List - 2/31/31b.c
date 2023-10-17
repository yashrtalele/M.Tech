/*
============================================================================
Name : 31b.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to create a semaphore and initialize value to the semaphore.    
a. create a binary semaphore    b. create a counting semaphore
Date: 6th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>

union sem {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

void main(void) {
    union sem arg;
    int key, semid;
    key = ftok("file", 97);
    semid = semget(key, 1, IPC_CREAT | 0744);
    printf("%d\n", semid);
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);
}
