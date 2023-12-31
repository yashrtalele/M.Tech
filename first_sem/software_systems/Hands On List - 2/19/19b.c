/*
============================================================================
Name : 19b.c
Author : Yash Talele
Roll No. : MT2023186
Description :  Create a FIFO file by    a. mknod command    b. mkfifo command    c. use strace command to find out, which command (mknod or mkfifo) is better.    c. mknod system call    d. mkfifo library function
Date: 5th Oct, 2023.
============================================================================
*/

#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main() {
    const char *buf = "pipe";
    mknod(buf, S_IFIFO | 0, 0);
}