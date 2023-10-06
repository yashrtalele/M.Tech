/*
 Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
*/

#include<sys/types.h>
#include<sys/stat.h>

void main(void) {
    const char *name = "pipe";
    mkfifo(name, 0);
}