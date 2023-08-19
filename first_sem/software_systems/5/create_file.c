#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>

void main() {
  int k = 0;
  FILE* file;
  while (true) {
    if(k<5) {
      char buffer[32];
      snprintf(buffer, sizeof(char) * 32, "file%i.txt", k);
      file = fopen(buffer, "wb");
      fclose(file);
    }
    if(k==2147483647) k=5;
    k++;
  }
}
