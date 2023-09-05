/*
============================================================================
Name : 15.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to display the environmental variable of the 
              user (use environ).
Date: 20 August, 2023
============================================================================
*/

#include<stdio.h>
extern char **environ;

void main() {
  for(size_t i=0; environ[i]!=NULL; i++)
    printf("%s\n", environ[i]);
}
