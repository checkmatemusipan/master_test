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

//heap over flow (danger) read-> (buf<len)need fixed
int32_t Client_sock::Recv(payload payl,uint32_t len){
   int32_t ret = read(this->sockfd, payl.buf(), len);
   if(ret == -1){
	   perror("cannot recv packet from socket function= Recv");
	   return -1;
   }
   return ret;
}
//heap over flow ueto same
bool Client_sock::RecvUntil(payload* payl,const char* word){
   uint32_t bin =0;  
   int32_t ret = read(this->sockfd, (void*)&bin, 1);
   if(ret == -1){
     perror("cannot recv packet from socket function=recvuntil");
     return false;
   }
   *payl<<(const char*)&bin;
   if(strlen(word) ==1 && payl->check_word(word)){
     return true;
   } 
   for(uint32_t i=0;i<strlen(word);i++){
     this->Recv(*payl,1);
   }
   payl.check_word(word);

}
