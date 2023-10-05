/*
========================================================================================
Name : 15.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a simple program to send some data from parent to the child process
Date: 19 August, 2023
========================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

void main(void) {
    int fd[2];
    if(pipe(fd) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    if((pid=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if(!pid) {
        char buf[100];
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("Parent says, %s\n", buf);
    }
    else {
        char buf[100]="\"I am writing!\"\0";
        close(fd[0]);
        write(fd[1], buf, strlen(buf));
    }
}