#include "payload.h"
#include <iostream>

int32_t main(void){
   payload p;
   
   p.p32(0xdeadbeef,true);
   p<<"Hi socket!";
   p<<"reallocate is good?";
   p.print_all();
   p.add("add",3);
   p.print_all();
   std::cout << p.check_word("\xde\xad\xbe\xef") << std::endl;
   return 0xdead;
}
