#include <iostream>
#ifndef __class_payload
#define

class payload{
  private:
     uint32_t memlength;
     uint32_t paylength;
     uint8_t* pay;
  public:
     //constructer
     payload();
     //destructor
     ~payload();
     //off buffering
     bool ctrlbuff();
     //make struct
     bool make_buffer();
     //add p32
     uint32_t p32(uint32_t input);
     //
};

#endif
