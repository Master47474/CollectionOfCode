// compile gcc main.c -o main -lws2_32
#include <stdio.h>
#include <io.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") //winsock Library

int main(){
  WSADATA wsa;
  SOCKET s, new_socket;
  struct sockaddr_in server, client;
  int c;
  char *message;

  printf("\nInitialising Winsock ...");
  if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
    printf("Failed. Error Cose : %d", WSAGetLastError);
    return 1;
  }

  printf("Initialised\n");

  //             Adress Family -- IPv4,  Type -- TCP protocol
  // SOCK_DGRAM = UDP
  if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
    printf("Could not create socket : %d ", WSAGetLastError());
    return 1;
  }
  printf("Socket Created\n");

  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_family = AF_INET;
  server.sin_port = htons(8888);

  // bind
  if(bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR){
    printf("Bind Failed with error code %d", WSAGetLastError());
    return 1;
  }

  printf("Bind Done\n");

  //listen for incoming connections
  listen(s,3);

  //accept incoming connections
  printf("Waiting for incoming connections ...\n");

  c = sizeof(struct sockaddr_in);


  while( (new_socket = accept(s, (struct sockaddr *)&client, &c)) != INVALID_SOCKET){
    printf("Accepted Connection\n");
    char *client_ip = inet_ntoa(client.sin_addr);
    //reply to client
    message = "welcome\n";
    send(new_socket, message, strlen(message), 0);
  }

  if(new_socket == INVALID_SOCKET){
    printf("accept failed with error code  %d", WSAGetLastError());
    return 1;
  }

  // gets client ip and client port
  int client_port = ntohs(client.sin_port);



  getchar();

  closesocket(s);
  WSACleanup();

  return 0;
}
