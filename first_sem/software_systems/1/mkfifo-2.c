#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

void operations(const char* path) {
  int fd;
  char str1[80], str2[80];
  while(1) {
    fd=open(path, O_RDONLY);
    read(fd, str1, 80);
    printf("User 1 : %s\n", str1);
    close(fd);
    fd=open(path, O_WRONLY);
    fgets(str2, 80, stdin);
    write(fd, str2, strlen(str2)+1);
    close(fd);
  }
}

void main() {
  const char* path="/tmp/fifo";
  operations(path);
}
