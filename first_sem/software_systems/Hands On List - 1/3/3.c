/*
============================================================================
Name : 3.c
Author : Yash Talele
Description : Write a program to create a file and print the file descriptor 
              value. Use creat() system call
Date: 19 August, 2023
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int create(char* file_name, mode_t mode) {
  return creat(file_name, mode);
}

void main() {
  char* file_name="creat.file";
  mode_t mode=S_IRUSR;
  int fd;
  if((fd=create(file_name, mode))<0)
    perror("Error while creation of file!");
  else
    printf("Created File Successfully! %d", fd);
}
