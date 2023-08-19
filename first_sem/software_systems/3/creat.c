#include<stdio.h>
#include<fcntl.h>

int create(char* file_name, mode_t mode) {
  return creat(file_name, mode);
}

void main() {
  char* file_name="creat.file";
  mode_t mode=S_IRUSR;
  int fd;
  if((fd=create(file_name, mode))<0)
    perror("Error while creation of file!");
  else
    printf("Created File Successfully! %d", fd);
}
