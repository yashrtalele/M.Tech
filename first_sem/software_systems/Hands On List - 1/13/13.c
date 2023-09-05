/*
===============================================================================
Name : 13.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to wait for a STDIN for 10 seconds using select. 
              Write a proper print statement to verify whether the data is 
              available within 10 seconds or not (check in $man 2 select).
Date: 20 August, 2023
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/select.h>

void main() {
  fd_set readfds;
  struct timeval timeout;
  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  timeout.tv_sec=10;
  timeout.tv_usec=0;
  int rselect=select(1, &readfds, NULL, NULL, &timeout);
  if(rselect < 0) {
    perror("select");
    exit(1);
  } else if(rselect == 0) {
    printf("Data not available\n");
    exit(1);
  } else if(rselect > 0) {
    printf("Data available\n");
    exit(1);
  }
}
