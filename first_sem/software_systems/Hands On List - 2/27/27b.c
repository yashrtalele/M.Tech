#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} msg;

void main(void) {
    key_t key;
    int msgid;
    key = ftok("file", 97);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &msg, sizeof(msg), 1, IPC_NOWAIT);
    printf("Data Received : %s \n", msg.msg_text);
}