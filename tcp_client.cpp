#include "tcp_class.h"
#include <iostream>

Client_sock::Client_sock(){
   
}

Client_sock::~Client_sock(){
}

int32_t Client_sock::MakeSocket(){
   this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if( this->sockfd < 0)
	   perror("cannot make socket function= MakeSocket");
   return this->sockfd;
}

void Client_sock::SetOpt(const char* host, int32_t port){
   this->addr.sin_family = AF_INET;
   this->addr.sin_port = htons( port );
   this->addr.sin_addr.s_addr = inet_addr(host);
   return;
}

bool Client_sock::Connect(){
   connect(this->sockfd, (struct sockaddr*)&this->addr, sizeof(addr) );
   return true;
}

bool Client_sock::Send(payload payl){
   write(this->sockfd, payl.buf(), payl.len());
   return true;
}

int32_t Client_sock::Recv(payload payl,uint32_t len){
   int32_t ret = read(this->sockfd, payl.buf(), len);
   if(ret == -1){
	   perror("cannot recv packet from socket function= Recv");
	   return -1;
   }
   return ret;
}

/*payload Client_sock::RecvUntil(payload payl,uint8_t* word){
   
}*/
