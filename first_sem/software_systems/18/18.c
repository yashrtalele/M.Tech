#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

struct students{
  int roll_no;
  char name[20];
  int marks;
};

void main() {
  struct flock lock;
  int fd=open("records.txt", O_CREAT | O_RDWR, 0744);
  struct students std1, std2, std3;
  std1.roll_no=1;
  std2.roll_no=2;
  std3.roll_no=3;
  strcpy(std1.name, "ABC");
  strcpy(std2.name, "DEF");
  strcpy(std3.name, "GHI");
  std1.marks=18;
  std1.marks=16;
  std3.marks=9;
  write(fd, &std1, sizeof(struct students));
  lock.l_type=F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 8;
  lock.l_len = 8;
  lock.l_pid = getpid();
  fcntl(fd,F_SETLKW , &lock);
  printf("Entered critical section...\n");
  printf("Press return to unlock...\n");
  getchar();
  printf("Write lock unset...\n");
  lock.l_type=F_RDLCK;
  lock.l_start=0;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Read lock set...\n");
  lock.l_type=F_UNLCK;
  lock.l_start=8;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Press return to exit...\n");
  getchar();
  printf("Read lock unset...\n");
  close(fd);
}
