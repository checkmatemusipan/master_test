#include "payload.h"
#include <iostream>

int32_t main(void){
   payload p;
   for(int32_t i=0;i< 5;i++){
     p.p64(0x6566676841424344,false);
   }
   p.print_all();
   return 0xdead;
}
