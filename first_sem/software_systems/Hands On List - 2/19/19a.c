/*
============================================================================
Name : 19a.c
Author : Yash Talele
Roll No. : MT2023186
Description :  Create a FIFO file by    a. mknod command    b. mkfifo command    c. use strace command to find out, which command (mknod or mkfifo) is better.    c. mknod system call    d. mkfifo library function
Date: 5th Oct, 2023.
============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>

void main(void) {
    const char *name = "pipe";
    mkfifo(name, 0);
}