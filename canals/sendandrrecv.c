#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


#define COUNT_PIPES 2
#define BUF_SIZE 256


int main()
{
char buf_send[BUF_SIZE];
char buf_recv[BUF_SIZE];
int i;
int fd[COUNT_PIPES][2];
int status;
pid_t pid;
for(i=0;i<COUNT_PIPES;i++)
{
pipe(fd[i]);
}
pid=fork();
if(pid==0)
{
strcpy(buf_send,"Hiii");
printf("Pid=%d send mess== \"%s\"\n",getpid(),buf_send);
write(fd[0][1],buf_send,strlen(buf_send));
read(fd[1][0],buf_recv, BUF_SIZE);
printf("pid= %d recv message = \"%s\"\n",getpid(),buf_recv);
exit(EXIT_SUCCESS);
}
  else if(pid>0)
  {
printf("father pid= %d\n",getpid());
pid=fork();
  if(pid==0)
    {
read(fd[0][0],buf_recv,BUF_SIZE);
printf("pid= %d recv message = \"%s\"\n",getpid(),buf_recv);
strcpy(buf_send,buf_recv);
strcat(buf_send," too");
printf("pid= %d send message = \"%s\"\n",getpid(),buf_send);
write(fd[1][1],buf_send,strlen(buf_send));
exit(EXIT_SUCCESS);
    }
    else if(pid>0)
    {
    printf("fathre pid = %d\n",getpid());
    wait(&status);
    }
    else
    {
    perror("fork");
    exit(EXIT_FAILURE);
    }
  wait(&status);
  }
  else
  {
  perror("fork");
  exit(EXIT_FAILURE);
  }
return 0;
}
