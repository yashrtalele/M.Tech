/*
==============================================================================
Name : 27e.c
Author : Yash Talele
Description : Write a program to execute ls -Rl by the following system calls
              e. execvp
Date: 05 September, 2023
==============================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main() {
  printf("execvp :: \n");
  static char *argv[] = {"/bin/ls", "-Rl", NULL};
  execvp(argv[0], argv);
}
