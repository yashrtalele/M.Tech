/*
==============================================================================
Name : 27c.c
Author : Yash Talele
Description : Write a program to execute ls -Rl by the following system calls
              c. execle
Date: 05 September, 2023
==============================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main() {
  printf("execle :: \n");
  execle("/bin/ls", "-R", "-l", NULL, NULL);
}
