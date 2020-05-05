#include "payload.h"
#include <iostream>

int32_t main(void){
   payload p;
   
   p.p32(0xdeadbeef,true);
   p<<"Hi socket!";
   p<<"reallocate is good?";
   p.print_all();
   return 0xdead;
}
