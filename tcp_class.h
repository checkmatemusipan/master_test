#ifndef client_sock
#define client_sock
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <inttypes.h>
#include <iostream>


class Client_sock{
 public:
   int32_t sockfd;
   struct sockaddr_in addr;
   
   //constructer
   Client_sock();
   //destra
   ~Client_sock();
   //try make socket
   int32_t MakeSocket();
   //set addr and port
   void SetOpt(const char* host, int32_t port);
};


#endif
