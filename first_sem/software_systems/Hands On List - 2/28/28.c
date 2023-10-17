/*
============================================================================
Name : 28.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 6th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

void main() {
    key_t key;
    int msqid;
    key = ftok(".", 97);
    msqid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds ms_info;
    msgctl(msqid, IPC_STAT, &ms_info);
    struct ipc_perm *permissions = &ms_info.msg_perm;
    printf("Current permission : %d\n", permissions->mode);
    permissions->mode = 777;
    ms_info.msg_perm = *permissions;
    msgctl(msqid, IPC_SET, &ms_info);
    printf("Changed permissions\n");
    msgctl(msqid, IPC_STAT, &ms_info);
    printf("New permission : %d \n", permissions->mode);
}
