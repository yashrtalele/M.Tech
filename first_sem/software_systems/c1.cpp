#include<bits.stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

main() {
  int v=symlink("dest", "destSL");
  if(v<0) {
    perror("Failed");
    return 1;
  }
  int f=link("dest", "destHL");
  if(f<0) {
    perror("Failed");
    return 1;
  }
  itn e=mkmod("destFIFO", S_FIFO,0);
  if(e<0)
    perror("Failed");
  return 0;
}
