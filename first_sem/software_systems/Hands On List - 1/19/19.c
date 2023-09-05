/*
============================================================================
Name : 19.c
Author : Yash Talele
Description : Write a program to find out time taken to execute getpid 
              system call. Use time stamp counter.
Date: 05 September, 2023
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

void main() {
  clock_t start_time, end_time;
  start_time = clock();
  getpid();
  end_time = clock();
  float t = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Time taken = %f sec\n", t);
}
