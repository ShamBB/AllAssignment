
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
  int clientSocket;
  char buffer[1024], message[1000],reverse[1000];
  int i , j ,len;
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
 
  serverAddr.sin_family = AF_INET;
  
  serverAddr.sin_port = htons(7891);
 
  serverAddr.sin_addr.s_addr = inet_addr("192.168.1.140");
  
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

 
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

 
 printf("Enter message : ");
        scanf("%s" , message);

len = strlen(message);
    j = 0;
 
    for(i=len-1; i>=0; i--)
    {
        reverse[j] = message[i];
        j++;
    }
reverse[j] = '\0';


send(clientSocket , reverse , strlen(reverse),0); 

  return 0;
}
