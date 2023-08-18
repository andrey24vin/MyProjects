#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>


typedef struct
{
int exchanging_socket;
struct sockaddr_in client_addr;
} PthreadData;
pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;


void *process(void *input_thread_data)
{
int bytes_send,bytes_recv;
time_t sys_time;
struct tm *date;
struct sockaddr_in client_addr;
int exchanging_socket;
int n;


PthreadData *thread_data=(PthreadData *)input_thread_data;
client_addr =thread_data->client_addr;
exchanging_socket = thread_data-> exchanging_socket;

if(pthread_mutex_unlock(&MUTEX)!=0)
{
perror("server: unlock");
exit(1);
}

printf("server client addres: %s:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

while(1)
{
bytes_recv=recv(exchanging_socket,&n,sizeof(int),0);
if(bytes_recv<=0)
  {
  break;
  }
sys_time=time(NULL);
date=localtime(&sys_time);
date->tm_year +=1900;
bytes_send =send(exchanging_socket,date,sizeof(struct tm),0);
if(bytes_send<=0)
  {
  break;
  }
}

close(exchanging_socket);
pthread_exit(NULL);

}

int main()
{
int listening_socket, exchanging_socket;
struct sockaddr_in server_addr,client_addr;
socklen_t lenght;
pthread_t thread;
PthreadData thread_data;

listening_socket=socket(AF_INET,SOCK_STREAM,0);
if(listening_socket==-1)
{
perror("server socket");
exit(1);
}


server_addr.sin_family=AF_INET;
server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
server_addr.sin_port=0;

if(bind(listening_socket,(struct sockaddr *)(&server_addr), sizeof(struct sockaddr_in))<0)
{
perror("server getsockname");
exit(1);
}
printf("server port nmber - %d\n",htons(server_addr.sin_port));
if(listen(listening_socket,5)<0)
{
perror("server listen");
exit(1);
}

while(1)
{
lenght=sizeof(struct sockaddr_in);
exchanging_socket=accept(listening_socket,(struct sockaddr *)(&client_addr),&lenght);
if(exchanging_socket==-1)
  {
  perror("server accept");
  exit(-1);
  }
if(pthread_mutex_lock(&MUTEX)!=0)
  {
  perror("SERVER mutex lock");
  exit(1);
  }

thread_data.client_addr=client_addr;
thread_data.exchanging_socket=exchanging_socket;

if(pthread_create(&thread,NULL,process,&thread_data)!=0)
  {
  perror("sever thread create");
  exit(1);
  }
if(pthread_detach(thread)!=0)
  {
  perror("server thread detach");
  exit(1);
  }
}

close(listening_socket);
return 0;
}
