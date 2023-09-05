/*
==============================================================================
Name : 27a.c
Author : Yash Talele
Description : Write a program to execute ls -Rl by the following system calls
              a. execl
Date: 05 September, 2023
==============================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main() {
  printf("execl :: \n");
  execl("/bin/ls", "ls", "-Rl", (char *)0);
}
