/*
============================================================================
Name : 29.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to remove the message queue
Date: 6th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

void main(void) {
    int queue_id;
    queue_id = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    printf("Message id = %d\n", queue_id);
    if (queue_id == -1) {
        perror("msgget");
        exit(1);
    }
    if(msgctl(queue_id, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    char *args[] = {"ipcs", "-q", NULL};
    execv("/bin/ipcs", args);
}