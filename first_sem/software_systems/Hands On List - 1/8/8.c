/*
=============================================================================
Name : 8.c
Author : Yash Talele
Description : Write a program to open a file in read only mode, read line by 
              line and display each line as it is read. Close the file when 
              end of file is reached.
Date: 20 August, 2023
=============================================================================
*/

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
const char EOL = '\n';

void main() {
  FILE* fd=fopen("file", "r");
  if(fd == NULL) {
    printf("Error %d", errno);
    perror("Program");
    exit(0);
  }
  int c=fgetc(fd);
  char buffer[1024];
  int k=0;
  while(c!=EOF) {
    while(c!=EOL) {
      printf("%c", c);
      buffer[k]=c;
      //write(1, c, 10);
      k++;
      c=fgetc(fd);
    }
    buffer[k++]='\n';
    write(1, buffer, k);
    buffer[0]='\0';
    c=fgetc(fd);
    k=0;
  }
  fclose(fd);
}

#pragma GCC diagnostic pop
