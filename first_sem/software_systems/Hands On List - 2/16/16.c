/*
============================================================================
Name : 16.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to send and receive data from parent to child 
              vice versa. Use two way communication
Date: 19 August, 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>

void main(void) {
    pid_t pid;
    char *msg;
    char buf[1024];
    int fd1[2];
    int fd2[2];
    if(pipe(fd1) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if(pipe(fd2) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if(!pid) {
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], buf, sizeof(buf));
        printf("Message = %s", buf);
        close(fd1[0]);
        msg="TRUE\n";
        write(fd2[1], msg, strlen(msg)+1);
        close(fd2[1]);
    }
    else {
        close(fd1[0]);
        close(fd2[1]);
        msg="Parent sent this message";
        write(fd1[1],msg, strlen(msg)+1);
        close(fd1[1]);
        read(fd2[0],buf,sizeof(buf));
        printf("\nAck received %s",buf);
        close(fd2[0]);
    }
}