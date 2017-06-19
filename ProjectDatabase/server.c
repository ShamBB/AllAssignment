#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <bson.h>
#include <mongoc.h>


int main(int argc, char *argv[]){
  int welcomeSocket, newSocket;
  char buffer[1024];
int len;
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;
//mongoc declare start here
   mongoc_client_t *client;
   mongoc_collection_t *collection;
   mongoc_cursor_t *cursor;
   const bson_t *doc;
   bson_t *query;
   char *str;
//mongoc declare end here


  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  serverAddr.sin_family = AF_INET;
 
  serverAddr.sin_port = htons(7891);
  
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  


  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

   //mongoc function start here
    mongoc_init ();

   client =
      mongoc_client_new ("mongodb://localhost:27017/?appname=find-example");
   collection = mongoc_client_get_collection (client, "mycustomers", "customers");
   query = bson_new ();
   cursor = mongoc_collection_find_with_opts (collection, query, NULL, NULL);
   //mongoc stop here

  if(listen(welcomeSocket,5)==0)
    printf("Listening\n");
  else
    printf("Error\n");


  addr_size = sizeof serverStorage;
  newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);


 while (mongoc_cursor_next (cursor, &doc)) {
      str = bson_as_json (doc, NULL);
      //printf ("%s\n", str);
	len = strlen(str);
      send(newSocket,str,(len+1),0);
      bson_free (str);
   }

/*printf("Enter message : ");
scanf("%s", buffer);

len = strlen(buffer);*/

//send(newSocket,buffer,13,0);

/*strcpy(buffer,"Hello World\n");
send(newSocket,buffer,13,0);*/

  /*recv(newSocket, buffer, 1024, 0);


  printf("Data received: %s",buffer);
  printf("\n");*/
   bson_destroy (query);
   mongoc_cursor_destroy (cursor);
   mongoc_collection_destroy (collection);
   mongoc_client_destroy (client);
   mongoc_cleanup ();
   close(newSocket);

  return 0;
}
