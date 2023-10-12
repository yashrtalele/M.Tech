#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_PATH "fifo"

void main(void) {
    int fd;
    const char* path="/tmp/fifo";
    char message[128];
    fd = open(path, O_RDONLY);
    read(fd, message, sizeof(message));
    printf("Received: %s", message);
    close(fd);
}