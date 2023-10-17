/*
============================================================================
Name : 19d.c
Author : Yash Talele
Roll No. : MT2023186
Description :  Create a FIFO file by    a. mknod command    b. mkfifo command    c. use strace command to find out, which command (mknod or mkfifo) is better.    c. mknod system call    d. mkfifo library function
Date: 5th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    if (mknod("my_fifo_syscall", __S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }

    printf("FIFO created using mknod system call.\n");
    return 0;
}