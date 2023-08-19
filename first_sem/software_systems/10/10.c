#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

void main() {
  int fd=open("file", O_RDWR | O_CREAT, 0666);
  char buf[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  write(fd, buf, 10);
  int rlseek=lseek(fd, 10, SEEK_CUR);
  printf("return value of lseek: %d\n", rlseek);
  write(fd, buf, 10);
  close(fd);
  system("od -c file");
}
