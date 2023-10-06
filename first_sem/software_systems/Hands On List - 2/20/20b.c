#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main(void) {
    int fd = open("fifo", O_WRONLY | O_CREAT, 0666);
    char buffer[100];
    printf("Enter a message for the parent: ");
    fgets(buffer, sizeof(buffer), stdin);
    write(fd, buffer, sizeof(buffer));
}