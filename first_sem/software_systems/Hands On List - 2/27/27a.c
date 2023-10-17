/*
============================================================================
Name : 27a.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to receive messages from the message queue.    a. with 0 as a flag    b. with IPC_NOWAIT as a flag
Date: 6th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mbuffer {
    long mtype;
    char mtext[100];
} message;

void main(void) {
    key_t key;
    int msgid;
    key = ftok("file", 97);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Data Received : %s\n", message.mtext);
}