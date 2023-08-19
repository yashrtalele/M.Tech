#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

/*
* create files of various types using following:
* sudo mknod blk_file b 1 2
* sudo mknod c_file c 1 2
* mknod fifo_file p
* vim r_file => :wq
* mkdir dir
* ln -s file_type.c symlink
*/

void main() {
  struct stat stats;
  char input[100];
  scanf("%[^\n]", &input);
  lstat(input, &stats);
  printf("file type = ");
  switch(stats.st_mode & S_IFMT) {
    case S_IFBLK:
      printf("block special\n");
      break;
    case S_IFCHR:
      printf("character special\n");
      break;
    case S_IFIFO:
      printf("FIFO special\n");
      break;
    case S_IFDIR:
      printf("directory\n");
      break;
    case S_IFREG:
      printf("regular\n");
      break;
    case S_IFLNK:
      printf("symbolic link\n");
      break;
    default:
      printf("not known!\n");
  }
}
