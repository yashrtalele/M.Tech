/*
============================================================================
Name : 6.c
Author : Yash Talele
Description : Write a program to take input from STDIN and display on STDOUT. 
              Use only read/write system calls
Date: 19 August, 2023
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

void main() {
  char buffer[32];
  int size_read=read(0, buffer, 20);
  write(1, buffer, size_read);
}
