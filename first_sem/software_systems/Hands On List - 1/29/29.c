/*
==============================================================================
Name : 29.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to get scheduling policy and modify the 
              scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 05 September, 2023
==============================================================================
*/


#include<stdio.h>
#include<sched.h>
#include<stdlib.h>
#include<unistd.h>

void main() {
  int sched_p=sched_getscheduler(getpid());
  printf("Scheduling Policy = %d\n\n", sched_p);
  struct sched_param sp = {.sched_priority=20};
  int ret;
  printf("Changing the scheduling policy to FIFO...\n");
  ret = sched_setscheduler(0, SCHED_FIFO, &sp);
  if (ret < 0) {
    perror("sched_setscheduler");
    exit(-1);
  }
  printf("Changed...\n");
  sched_p=sched_getscheduler(getpid());
  printf("Scheduling Policy = %d\n\n", sched_p);
  printf("Changing the scheduling policy to RR...\n");
  ret = sched_setscheduler(0, SCHED_RR, &sp);
  if (ret == -1) {
    perror("sched_setscheduler");
    exit(-1);
  }
  printf("Changed...\n");
  sched_p=sched_getscheduler(getpid());
  printf("Scheduling Policy = %d\n", sched_p);
}
