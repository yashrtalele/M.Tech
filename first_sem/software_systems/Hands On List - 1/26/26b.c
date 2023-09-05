/*
============================================================================
Name : 26b.c
Author : Yash Talele
Description : Write a program to execute an executable program.
              b. pass some input to an executable program. 
              (for example execute an executable of $./a.out name)
Date: 05 September, 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main() {
  static char *argv[]={"input", "This is the given input", NULL};
  execv(argv[0], argv);
}
