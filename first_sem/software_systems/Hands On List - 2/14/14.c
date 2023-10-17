/*
============================================================================
Name : 14.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a simple program to create a pipe, write to the pipe, 
            read from pipe and display on the monitor.
Date: 5th October, 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void main(void) {
    int fd[2];
    char msg[]="Hello!\0";
    char buf[50];
    if(pipe(fd) == -1) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    write(fd[1], msg, strlen(msg));
    read(fd[0], buf, strlen(msg));
    printf("%s", buf);
}