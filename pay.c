#include "payload.h"
#include <iostream>

int32_t main(void){
   payload p;
   
   p.p64(0xdeadbeef,false);
   p.p64(0xcafebabe,false);
   p.print_all();
<<<<<<< HEAD
   p.print_buf();
=======
   p.add("add",3);
   p.print_all();
>>>>>>> d20a9194f2cd5f8f969f8eb803f239d901a5ac25
   std::cout << p.check_word("\xde\xad\xbe\xef") << std::endl;
   return 0xdead;
}
