/*#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{

  char server_message[255]= "Hello its server wwwwww\n";

  int server_socket;
  server_socket=socket(AF_LOCAL,SOCK_DGRAM,0);


  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr= INADDR_ANY;












return 0;
}
*/
