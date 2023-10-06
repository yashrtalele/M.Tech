#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main() {
    key_t key = ftok("file", 97);
    int shmid = shmget(key, 1024, 0);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Data : %s\n", str);
    shmdt(str);
    printf("Shared memory detached...\n");
}