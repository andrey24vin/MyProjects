#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>


int main()
{
int sock_raw=socket(AF_INET,SOCK_RAW,IPPROTO_TCP);
int i=0;


int saddr_size,data_size;
struct sockaddr saddr;
//struct in_addr in;
struct sockaddr_in source,dest;
unsigned char *buffer =(unsigned char *)malloc(2048);
if(sock_raw<0)
{
perror("sock_raw fail\n");
return 1;
}

while(1)
{
saddr_size = sizeof saddr;
data_size=recvfrom(sock_raw,buffer,2048,0,&saddr,&saddr_size);
if(data_size<0)
  {
  printf("recvfrom error\n");
  return 1;
  }
/*if()
  {
  i++;
  printf("packet number %d\n",i);
  }*/
}

//close(sock_raw);
printf("finnish");
return 0;
}
