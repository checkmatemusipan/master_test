#ifndef client_sock
#define client_sock
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <inttypes.h>
#include <iostream>
#include "payload.h"
#include <string.h>

class Client_sock{
 private:
   payload pay;
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
   //connect
   bool Connect();
   //send
   bool Send(payload* payl);
   //recv
   int32_t Recv(payload* payl,uint32_t len);
   bool RecvUntil(payload* payl,const char* word);
};


#endif
