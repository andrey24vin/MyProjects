//#include <memory.h>
#include <arpa/inet.h>
#include <netinet/in.h>
//#include <netinet/ip.h>
//#include <netinet/udp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
//#include <time.h>
#include <unistd.h>


int main()
{
int exchanging_socket;
struct sockaddr_in server_addr,client_addr;
socklen_t lenght;
int bytes_send,bytes_recv;
char buf[256];
exchanging_socket=socket(AF_INET,SOCK_DGRAM,0);
if(exchanging_socket==-1)
{
perror("server socket");
}


memset(&server_addr,0,sizeof(struct sockaddr_in));
server_addr.sin_family=AF_INET;
server_addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
server_addr.sin_port=0;
if(bind(exchanging_socket,(struct sockaddr*)(&server_addr),sizeof(struct sockaddr_in))==-1)
{
perror("server bind");
exit(1);
}
lenght=sizeof(struct sockaddr_in);
printf("server port umber - %d, ip  - %s\n",htons(server_addr.sin_port),inet_ntoa(server_addr.sin_addr));


while(1)
{
lenght=sizeof(struct sockaddr_in);
bytes_recv=recvfrom(exchanging_socket,&buf,sizeof(buf),0,(struct sockaddr*)(&client_addr),&lenght);
printf("server client addr :  %s:%d\n",inet_ntoa(client_addr.sin_addr),htons(client_addr.sin_port));
strcat(buf,", Too");
bytes_send=sendto(exchanging_socket,buf,sizeof(buf),0,(struct sockaddr*)(&client_addr),sizeof(struct sockaddr_in));
if(bytes_send<=0)
  {
perror("server sendto");
exit(1);
  }
}


return 0;
}
