#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()  
{
  pid_t pid;
  int rw;
  switch (pid=fork()) {
  case -1:
    perror("fork");
    exit(1);
  case 0: 
    printf("its CHILD PROCESS\n");
    printf("My PID --%d\n", getpid());
    printf("MY PARENTHS PID --%d\n", getppid());
    exit(rw);
  default:
    printf("ITS PARENT PROCESS\n");
    printf("My PID --%d\n", getpid());
    printf("My douth PID--%d\n",pid);

  }
return 0;
}




