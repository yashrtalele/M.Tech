/*
============================================================================
Name : 26a.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to execute an executable program.
              a. use some executable program
Date: 05 September, 2023
============================================================================
*/


#include<stdio.h>
#include<unistd.h>

void main() {
  static char *argv[]={"input",NULL};
  execv("./input", argv);
}
