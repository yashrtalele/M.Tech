/*
==============================================================================
Name : 28.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to get maximum and minimum real time priority.
Date: 05 September, 2023
==============================================================================
*/


#include<stdio.h>
#include<sched.h>

void main() {
  printf("Maximum Priority = %d\n", sched_get_priority_max(SCHED_FIFO));
  printf("Minimum Priority = %d\n", sched_get_priority_min(SCHED_FIFO));
}
