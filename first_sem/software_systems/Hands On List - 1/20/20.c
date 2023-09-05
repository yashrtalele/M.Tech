/*
============================================================================
Name : 20.c
Author : Yash Talele
Description : Find out the priority of your running program. 
              Modify the priority with nice command.
Date: 05 September, 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include <sys/resource.h>

void main() {
  int a = getpriority(PRIO_PROCESS, getpid());
  printf("Priority before = %d\n", a);
  nice(-20);
  a = getpriority(PRIO_PROCESS, getpid());
  printf("Priority after = %d\n", a);
  while(1);
}
