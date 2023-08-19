#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

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
