#include "payload.h"
#include <iostream>

int32_t main(void){
   payload p;
   for(int32_t i=0;i< 5;i++){
     p.p32(0x41424344,true);
   }
   p.print_all();
   return 0xdead;
}
