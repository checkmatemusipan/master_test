#include <iostream>
#include "payload.h"


int main(){
  payload pay;
  payload pay2;
  pay2.add("hogeeeee",8);
  pay.print_all();
  pay2.print_all();
  std::cout << "****edited****" << std::endl;
  pay = pay2;
  pay.print_all();
  pay2.print_all();
  std::cout << (char*)pay.buf() << std::endl;
  return 0;
}
