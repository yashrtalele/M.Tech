// Write two programs so that both can communicate by FIFO -Use two way communications.
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main(void) {
    int fd1 = open("fifo1", O_RDWR | O_CREAT, 0666);
    int fd2 = open("fifo2", O_RDWR | O_CREAT, 0666);
    char buffer_write[1024] ;
    char buffer_read[1024] ;
    printf("Enter message : ");
    scanf("%s", buffer_write);
    write(fd1, buffer_write, 1024);
    read(fd2, buffer_read, 1024);
    printf("%s\n", buffer_read);
}