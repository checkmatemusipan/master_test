#include "payload.h"
#include <iostream>

int32_t main(void){
   payload p;
   
   p.p64(0xdeadbeef,false);
   p.p64(0xcafebabe,false);
   p.print_all();
   p.print_buf();
   std::cout << p.check_word("\xde\xad\xbe\xef") << std::endl;
   return 0xdead;
}
