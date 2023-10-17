/*
============================================================================
Name : 23.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to print the maximum number of files can be opened within a process and  
size of a pipe (circular buffer). 
Date: 6th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

void main(void) {
    long PIPE_BUF, OPEN_MAX;
    PIPE_BUF = pathconf(".",_PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    printf("The maximum number of files can be opened within a process is %d.\n", OPEN_MAX);
    printf("The size of a pipe (circular buffer) is %d bytes.\n", PIPE_BUF);
}