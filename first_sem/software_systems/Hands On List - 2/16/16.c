/*
============================================================================
Name : 16.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to send and receive data from parent to child 
              vice versa. Use two way communication
Date: 19 August, 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include <sys/wait.h>

int main() {
    int p[2], r[2];
    pipe(p);
    pipe(r);
    pid_t pid = fork();
    if (!pid) {
        //child
        close(p[1]);
        close(r[0]);
        char buffer[1024];
        int n = read(p[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Child received: %s\n", buffer);
        }
// ------------------------------------------------------------------------
        buffer[0]='\0';
        printf("Enter a message for the parent: ");
        fgets(buffer, sizeof(buffer), stdin);
        n=write(r[1], buffer, strlen(buffer));
        close(p[0]);
        close(r[1]);
        exit(EXIT_SUCCESS);
    } else {
        //parent
        close(p[0]);
        close(r[1]);
        char buffer[1024];
        printf("Enter a message for the child: ");
        fgets(buffer, sizeof(buffer), stdin);
        int n = write(p[1], buffer, strlen(buffer));
        // if (n > 0) {
        //     printf("Parent sent: %s\n", buffer);
        // }
// ------------------------------------------------------------------------
        buffer[0]='\0';
        n=read(r[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Parent received: %s\n", buffer);
        }

        close(p[1]);
        wait(NULL);
    }

    return 0;
}

// void main(void) {
//     pid_t pid;
//     char *msg;
//     char buf[1024];
//     int fd1[2];
//     int fd2[2];
//     if(pipe(fd1) < 0) {
//         perror("Pipe");
//         exit(EXIT_FAILURE);
//     }
//     if(pipe(fd2) < 0) {
//         perror("Pipe");
//         exit(EXIT_FAILURE);
//     }
//     if((pid=fork()) < 0) {
//         perror("Fork");
//         exit(EXIT_FAILURE);
//     }
//     if(!pid) {
//         close(fd1[1]);
//         close(fd2[0]);
//         read(fd1[0], buf, sizeof(buf));
//         printf("Message = %s", buf);
//         close(fd1[0]);
//         msg="TRUE\n";
//         write(fd2[1], msg, strlen(msg)+1);
//         close(fd2[1]);
//     }
//     else {
//         close(fd1[0]);
//         close(fd2[1]);
//         msg="Parent sent this message";
//         write(fd1[1],msg, strlen(msg)+1);
//         close(fd1[1]);
//         read(fd2[0],buf,sizeof(buf));
//         printf("\nAck received %s",buf);
//         close(fd2[0]);
//     }
// }