#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void listener(int sig)
{
  printf("Stopper\n");
}


int main()
{
  while(1)
  {
    sleep(2);
    signal(SIGINT,listener);
    raise(SIGINT);
    int i;
    i++;
    if(i==10)
    {
      signal(SIGKILL,listener);
      raise(SIGKILL);
    }
  }
return 0;
}

