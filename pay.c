#include "payload.h"
#include <iostream>

int32_t main(void){
   payload p;
   
   p.p32(0xdeadbeef,true);
   
   p.print_all();
   return 0xdead;
}
