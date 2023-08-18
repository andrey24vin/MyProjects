#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>



int main()
{
struct sockaddr_in b_addr;
int socked=socket(AF_INET,SOCK_DGRAM,0);

const int optval=1;
setsockopt(socked,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval));
bzero(&b_addr,sizeof(b_addr));
b_addr.sin_family=AF_INET;
b_addr.sin_addr.s_addr=htonl(INADDR_ANY);
b_addr.sin_port=htons(8080);
if(socked<0)
{
perror("socked fail");
exit(1);
}
bind(socked,(sockaddr *)&b_addr,sizeof(b_addr));


struct ip_mreq mreq;
inet_aton(ip_addr,&(mreq.imr_multiaddr));
mreq.imr_interface.s_addr=htonl(INADDR_ANY);
setsockopt(socked,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));





return 0;
}
