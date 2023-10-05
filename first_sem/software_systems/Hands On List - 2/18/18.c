/*
=====================================================================================
Name : 18.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to find out total number of directories on the pwd.
              execute ls -l | grep ^d | wc ? Use only dup2
Date: 19 August, 2023
=====================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main(void)
{
    int fd1[2], fd2[2];
    pid_t pid1, pid2;
    if(pipe(fd1) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if(pipe(fd2) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid1=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if (!pid1) {
        dup2(fd1[1], 1);
        close(fd2[0]);
        close(fd2[1]);
        close(fd1[0]);
        char *args[]={"ls", "-l", NULL};
        execv("/bin/ls", args);
    } else {
        if((pid2=fork()) < 0) {
            perror("Fork");
            exit(EXIT_FAILURE);
        }
        if (!pid2) {
            dup2(fd1[0], 0);
            dup2(fd2[1], 1);
            close(fd1[1]);
            close(fd2[0]);
            char *args[]={"grep", "^d", NULL};
            execv("/bin/grep", args);
            // execlp("grep", "grep", "^-", NULL);
        } else {
            sleep(2);
            dup2(fd2[0], 0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            char *args[]={"wc", "-l", NULL};
            execv("/bin/wc", args);
            // execlp("wc", "wc", "-l", NULL);
        }
    }
}