#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct mbuffer {
    long mtype;
    char mtext[100];
} message;

void main(void) {
    key_t key;
    int msgid;
    key = ftok("file", 97);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, IPC_NOWAIT);
    printf("Data Received : %s \n", message.mtext);
}