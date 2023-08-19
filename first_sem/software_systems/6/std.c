#include<stdio.h>
#include<unistd.h>

void main() {
  char buffer[32];
  int size_read=read(0, buffer, 20);
  write(1, buffer, size_read);
}
