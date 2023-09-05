/*
=====================================================================================
Name : 9.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to print the following information about a given file.
              a. inode
              b. number of hard links
              c. uid
              d. gid
              e. size
              f. block size
              g. number of blocks
              h. time of last access
              i. time of last modification
              j. time of last change
Date: 20 August, 2023
=====================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>

void main(int argc, char *argv[]) {
  struct stat file_stats;
  time_t last_access, last_mod, last_changed;
  if(stat(argv[1], &file_stats) < 0) {
    perror("stat");
    exit(0);
  }
  last_access=file_stats.st_atime;
  last_mod=file_stats.st_mtime;
  last_changed=file_stats.st_ctime;
  printf("inode: %d\n", file_stats.st_ino);
  printf("number of hard links: %d\n", file_stats.st_nlink);
  printf("uid: %d\n", file_stats.st_uid);
  printf("gid: %d\n", file_stats.st_gid);
  printf("size: %d\n", file_stats.st_size);
  printf("block size: %d\n", file_stats.st_blksize);
  printf("number of blocks: %d\n", file_stats.st_blocks);
  printf("last accessed: %s\n", ctime(&last_access));
  printf("last modified: %s\n", ctime(&last_mod));
  printf("last changed: %s\n", ctime(&last_changed));
}
