// compile gcc main.c -o main -lws2_32
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") //winsock Library

int main(){
  WSADATA wsa;
  SOCKET s;
  struct sockaddr_in server;
  char *message, server_reply[2000];
  int recv_size;

  printf("\nInitialising Winsock ...");
  if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
    printf("Failed. Error Cose : %d", WSAGetLastError);
    return 1;
  }

  printf("Initialised\n");

  //             Adress Family -- IPv4,  Type -- TCP protocol
  // SOCK_DGRAM = UDP
  if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    printf("Could not create socket : %d ", WSAGetLastError());
  printf("Socket Created\n");

  server.sin_addr.s_addr = inet_addr("172.217.25.131");
  server.sin_family = AF_INET;
  server.sin_port = htons(80);

  //connect to remote server
  if(connect(s, (struct sockaddr*)&server, sizeof(server)) < 0){
    puts("connect error");
    return 1;
  }

  puts("Connected \n");


  //Send some data
	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(s , message , strlen(message) , 0) < 0)	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");

  //receive a reply
  if((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR)
    puts("recv Failed");

  puts("reply Recived \n");

  //add a null terminating char
  server_reply[recv_size] = '\0';
  puts(server_reply);

  closesocket(s);
  WSACleanup();

  return 0;
}
