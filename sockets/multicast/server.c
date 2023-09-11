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
int multicast_socket;
struct sockaddr_in multicast_addr;
int bytes_send;
int n=8888;

multicast_socket=socket(AF_INET,SOCK_DGRAM,0);
multicast_addr.sin_family=AF_INET;
multicast_addr.sin_addr.s_addr=htonl(inet_addr("224.0.0.1"));
multicast_addr.sin_port=htons(4747);
bytes_send=sendto(multicast_socket, &n,sizeof(int),0,(struct sockaddr*)(&multicast_addr),sizeof(struct sockaddr));


return 0;
}
