/*
============================================================================
Name : 21.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program, call fork and print the parent and 
              child process id.
Date: 05 September, 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

void main() {
  pid_t pid;
  if((pid=fork())==0) {
    perror("fork");
    exit(1);
  }
  printf("Parent's pid = %d\nChild's pid = %d\n", (int) getppid(), (int) getpid());
}
