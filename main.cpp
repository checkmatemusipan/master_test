#include "tcp_class.h"
#include "payload.h"
#include <iostream>

int main(void){
  Client_sock sock;
  payload payl;
  sock.MakeSocket();
  sock.SetOpt("127.0.0.1",10001);
  sock.Connect();
  payl.p64(0xdeadbeef,true);
  payl.print_all();
  sock.Send(payl); 
  return 0;
}
