/*
============================================================================
Name : 20a.c
Author : Yash Talele
Roll No. : MT2023186
Description :  Write two programs so that both can communicate by FIFO -Use one way communications. 
Date: 6th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

void main(void) {
    char message[128];
    const char* path="/tmp/fifo";
    mode_t mode=0666;
    mkfifo(path, mode);
    int fd = open(path, O_WRONLY);
    if(fd < 0) {
        perror("open");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    write(fd, message, strlen(message) + 1);
    close(fd);
}