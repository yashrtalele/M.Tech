/*
============================================================================
Name : 7.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 19 August, 2023
============================================================================
*/

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#include<stdio.h>
#include<errno.h>
#include <fcntl.h>
#include<stdlib.h>

void main(int argc, char* argv[]) {
  int file1=open(argv[1], O_RDONLY);
  if(file1 < 0) {
    printf("Error %d", errno);
    perror("Program");
    exit(0);
  }
  int file2=open(argv[2], O_WRONLY | O_EXCL | O_CREAT, 0777);
  if(file2 < 0) {
    printf("Error %d", errno);
    perror("Program");
    exit(0);
  }

  char buffer[1024];
  int size_read;
  while((size_read = read(file1, buffer, sizeof(buffer))) > 0) {
    write(file2, buffer, size_read);
  }
  close(file1);
  close(file2);
}

#pragma GCC diagnostic pop
/*
void main() {
  FILE* file1, *file2;
  file1=fopen("file1", "r");
  if(file1 < 0) {
    printf("Error %d", errno);
    perror("Program");
    exit(0);
  }
  file2=fopen("file2", "wb");
  char s=fgetc(file1);
  while(s!=EOF) {
    fputc(s, file2);
    s=fgetc(file1);
  }
  fclose(file1);
  fclose(file2);
}
*/
