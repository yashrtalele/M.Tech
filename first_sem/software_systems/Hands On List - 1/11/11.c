/*
============================================================================
Name : 11.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to open a file, duplicate the file descriptor 
              and append the file with both the descriptors and check 
              whether the file is updated properly or not.
              a. use dup
              b. use dup2
              c. use fcntl
Date: 20 August, 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

void main() {
  int o_fd=open("file_a", O_RDWR | O_CREAT, 0666);
  int d_fd=dup(o_fd);
  char buf[]="file_a: This is written by o_fd\n";
  write(o_fd, buf, sizeof(buf));
  (void)strncpy(buf, "This is written by d_fd\n", sizeof(buf));
  write(d_fd, buf, sizeof(buf));
  close(o_fd);
  o_fd=open("file_c", O_RDWR | O_CREAT, 0666);
  d_fd=fcntl(o_fd, F_DUPFD);
  (void)strncpy(buf, "file_c: This is written by o_fd\n", sizeof(buf));
  write(o_fd, buf, sizeof(buf));
  (void)strncpy(buf, "This is written by d_fd-f\n", sizeof(buf));
  write(d_fd, buf, sizeof(buf));
  close(o_fd);
  o_fd=open("file_b", O_RDWR | O_CREAT, 0666);
  dup2(o_fd, 1);
  printf("file_b: This is written by dup2\n");
  close(o_fd);
  // system("cat file_a");
  // system("cat file_b");
  // system("cat file_c");
}
