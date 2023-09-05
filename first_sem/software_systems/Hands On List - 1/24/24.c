/*
============================================================================
Name : 24.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to create an orphan process.
Date: 05 September, 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

void main() {
  pid_t pid;
  if((pid=fork()) < 0) {
    perror("fork");
    exit(-1);
  } else if(pid > 0) {
    printf("Parent process running\n");
  } else if(pid == 0) {
    sleep(10);
    printf("Child is orphan\n");
  }
}
