#include "tcp_class.h"
#include <iostream>

int main(void){
  Client_sock a;
  a.MakeSocket();
  a.SetOpt("127.0.0.1",10001);
  return 0;
}
