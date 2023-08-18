#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


void *clientThread(void *arg)
{
printf("in thread\n");
char message[1000];
char buffer[1024];
int clientSocket;
struct sockaddr_in serverAddr;
socklen_t addr_size;


clientSocket= socket(PF_INET,SOCK_STREAM,0);
serverAddr.sin_family=AF_INET;
serverAddr.sin_port=htons(7799);
serverAddr.sin_addr.s_addr=inet_addr("localhost");
memset(serverAddr.sin_zero,'\0',sizeof serverAddr.sin_zero);
addr_size=sizeof serverAddr;
connect(clientSocket,(struct sockaddr *) &serverAddr,addr_size);
strcpy(message,"hello");
if(send(clientSocket,message,strlen(message),0)<0)
{
printf("send failed\n");
}
if(recv(clientSocket,buffer,1024,0)<0)
{
printf("recv failed\n");
}
printf("data recv: %s\n",buffer);
close(clientSocket);
pthread_exit(NULL);
}


int main()
{
int i=0;
pthread_t tid[51];
while(i<50)
{
if(pthread_create(&tid[i],NULL,clientThread,NULL)!=0)
  {
  printf("fail to create thread");
  }
i++;
}
sleep(20);
i=0;
while(i<50)
{
pthread_join(tid[i++],NULL);
printf("%d\n",i);
}
return 0;
}
