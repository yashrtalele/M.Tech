/*
==============================================================================
Name : 27b.c
Author : Yash Talele
Description : Write a program to execute ls -Rl by the following system calls
              b. execlp
Date: 05 September, 2023
==============================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main() {
  printf("execlp :: \n");
  execlp("ls", "ls", "-Rl", (char *)0);
}
