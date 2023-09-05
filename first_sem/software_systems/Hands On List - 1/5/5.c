/*
============================================================================
Name : 5.c
Author : Yash Talele
Description : Write a program to create five new files with infinite loop. 
              Execute the program in the background and check the file 
              descriptor table at /proc/pid/fd.
Date: 19 August, 2023
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>

void main() {
  int k = 0;
  FILE* file;
  while (true) {
    if(k<5) {
      char buffer[32];
      snprintf(buffer, sizeof(char) * 32, "file%i.txt", k);
      file = fopen(buffer, "wb");
      fclose(file);
      k++;
    }
  }
}
