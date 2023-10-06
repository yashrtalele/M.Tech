
#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

union sem {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

void main(void) {
    union sem arg;
    int key, semid;
    key = ftok("file", 97);
    semid = semget(key, 1, IPC_CREAT | 0744);
    printf("%d\n", semid);
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);
}
