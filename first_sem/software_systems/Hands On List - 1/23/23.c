/*
===============================================================================
Name : 23.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to create a Zombie state of the running program.
Date: 05 September, 2023
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

void main() {
  pid_t pid;
  if((pid=fork())<0) {
    perror("fork");
    exit(-1);
  } else if(pid > 0) {
    printf("Parent process enters and sleeps for 5s\n");
    sleep(5);
    printf("Parent process is awake\nZombie process is created\n");
  } else if(pid == 0) {
    printf("Child process running\n");
    exit(0);
  }
}
