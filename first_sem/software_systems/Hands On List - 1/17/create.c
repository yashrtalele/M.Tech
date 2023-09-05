/*
============================================================================
Name : 17a.c
Author : Yash Talele
Description : Write a program to simulate online ticket reservation. 
              Implement write lock Write a program to open a file, 
              store a ticket number and exit. Write a separate program, to
              open the file, implement write lock, read the ticket number, 
              increment the number and print the new ticket number then 
              close the file.
Date: 20 August, 2023
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main() {
  int fd;
  int i = 12345;
  fd = open("file.txt", O_WRONLY);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  write(fd, &i, sizeof(int));
  close(fd);
}
