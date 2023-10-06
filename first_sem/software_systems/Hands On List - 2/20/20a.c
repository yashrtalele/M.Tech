// Write two programs so that both can communicate by FIFO -Use one way communication.

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main(void) {
    int fd = open("fifo", O_RDONLY | O_CREAT, 0666);
    char buffer[100];
    int size = read(fd, buffer, 100);
    printf("%s\n", buffer);
}