#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
    int key, shmid;
    char *data;
    key=ftok("file", 97);
    shmid=shmget(key, 1024, 0);
    data=(char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Shared memory input : %s\n", data);
}