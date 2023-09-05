#include<stdio.h>

int main(int argc, char *argv[]) {
  printf("Program = %s\n", argv[0]);
  if(argc < 2) printf("No arguments passed\n");
  else {
    printf("Input : %s", argv[1]);
  }
}
