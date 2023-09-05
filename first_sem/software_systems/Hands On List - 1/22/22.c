/*
============================================================================
Name : 22.c
Author : Yash Talele
Description : Write a program, open a file, call fork, and then write to the
              file by both the child as well as the parent processes. 
              Check output of the file.
Date: 05 September, 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

void main() {
  int fd=open("22", O_RDWR | O_CREAT, 0744);
  pid_t pid;
  char bufP[18]="Written by Parent\n";
  char bufC[16]="Written by Child";
  if((pid=fork())<0) {
    perror("fork");
    exit(1);
  }
  else if(pid > 0) {
    write(fd, bufP, 18);
  }
  else if(pid==0) {
    lseek(fd, 0, SEEK_END);
    write(fd, bufC, 16);
  }
}
