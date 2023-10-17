/*
============================================================================
Name : 21b.c
Author : Yash Talele
Roll No. : MT2023186
Description :  Write two programs so that both can communicate by FIFO -Use two way communications. 
Date: 6th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void main(void) {
    int fd1, fd2;
    fd1 = open("myfifo1", O_RDWR);
    fd2 = open("myfifo2", O_RDWR);
    while (1) {
        char message[1024];
        printf("Enter message for sender : ");
        fgets(message, sizeof(message), stdin);
        if(strcmp(message, "exit")) {
            write(fd2, message, sizeof(message));
            char buf[1024];
            read(fd1, buf, sizeof(buf));
            printf("Message from server : %s\n", buf);
        }
        else {
            close(fd1);
            close(fd2);
        }
    }
}