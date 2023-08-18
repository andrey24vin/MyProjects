#include "protocol.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>


int main()
{
  int fd=shm_open(NAME, O_CREAT|O_EXCL|O_RDWR, 0600);
  if(fd<0)
  {
    perror("shm_open()");
    exit(1);
  }
  ftruncate(fd,SIZE);
  int *data=(int *)mmap(0,SIZE,PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
  printf("sender address %p\n",data);


  for(int i=0;i<NUM;++i)
  {
    data[i]=i;
  }
  munmap(data,SIZE);
  close(fd);


return 0;
}

