#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
//#include <conio.h>

void listener(int sig)
{
  printf("ddddsssssdd\n");
}


int main()
{
  signal(SIGKILL,listener);
  //printf(stdout,"begin\n");
  raise(SIGKILL);
  //printf(stdout,"End\n");

return 0;
}
