#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int my_fifo(const char* path, mode_t mode) {
  return mkfifo(path, mode);
}

void operations(const char* path) {
  char arr1[80], arr2[80];
  int fd;
  while(1) {
    fd=open(path, O_WRONLY);
    fgets(arr2, 80, stdin);
    write(fd, arr2, strlen(arr2)+1);
    close(fd);
    fd=open(path, O_RDONLY);
    read(fd, arr1, sizeof(arr1));
    printf("User2 : %s\n", arr1);
    close(fd);
  }
}

void main() {
  const char* path="/tmp/fifo";
  mode_t mode=0666;
  printf("%d\n", my_fifo(path, mode));
  operations(path);
}
