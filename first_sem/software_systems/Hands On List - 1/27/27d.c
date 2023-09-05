/*
==============================================================================
Name : 27d.c
Author : Yash Talele
Description : Write a program to execute ls -Rl by the following system calls
              d. execv
Date: 05 September, 2023
==============================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main() {
  printf("execv :: \n");
  static char *argv[] = {"/bin/ls", "-Rl", NULL};
  execv(argv[0], argv);
}
