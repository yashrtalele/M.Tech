/*
============================================================================
Name : 17.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to execute ls -l | wc.
            b. use dup2
Date: 5th October, 2023
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void main(void) {
    int fd[2];
    pid_t pid;
    if(pipe(fd) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if(pid) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        char *args[] = {"wc", NULL};
        execv("/bin/wc", args);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
}