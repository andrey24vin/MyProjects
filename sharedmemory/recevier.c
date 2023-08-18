#include "protocol.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>


int main()
{
  int fd=shm_open(NAME,O_RDONLY,0666);
  if(fd<0)
  {
    perror("shm_open()");
    exit(1);
  }

  int *data=(int *)mmap(0,SIZE, PROT_READ,MAP_SHARED,fd,0);
  printf("receiver address %p\n",data);
  for(int i=0;i<NUM;++i)
  {
    printf("%d\n",data[i]);
  }
  munmap(data,SIZE);
  close(fd);
  shm_unlink(NAME);


return 0;
}
