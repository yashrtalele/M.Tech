/*
============================================================================
Name : 17.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to execute ls -l | wc.
              b. use fcntl
Date: 19 August, 2023
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

void main(void) {
    int fd[2];
    pid_t pid;
    pipe(fd);
    if ((pid = fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if(!pid) {
        close(fd[1]);
        close(0);
        fcntl(fd[0], F_DUPFD, STDIN_FILENO);
        char *args[] = {"wc", NULL};
        execv("/bin/wc", args);
        close(fd[0]);
        exit(0);
    } else {
        close(fd[0]);
        close(1);
        fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        close(fd[1]);
    }
}