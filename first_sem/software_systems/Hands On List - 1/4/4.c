/*
============================================================================
Name : 4.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to open an existing file with read write mode. 
              Try O_EXCL flag also.
Date: 19 August, 2023
============================================================================
*/

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

void main() {
  char* file_name="open.file";
  int fd=open(file_name, O_RDWR | O_EXCL | O_CREAT, 0666);
  printf("fd=%d \n", fd);
  if(fd == -1) {
    printf("Error %d\n", errno);
    perror("Program");
  }
  char* str="This is a test line.";
  int wr=write(fd, str, strlen(str)+1);
  printf("Status of writing in the file : %d\n", wr);
  close(fd);
  fd=open(file_name, O_RDWR);
  char str2[80];
  read(fd, str2, 80);
  printf("Read = %s\n", str2);
  close(fd);
}

#pragma GCC diagnostic pop
