#include <iostream>
#ifndef __class_payload
#define __class_payload

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
     //getter
     uint32_t len() const;
     void*    buf();
     //off buffering
     bool ctrlbuff(void);
     //make struct
     bool make_buffer(void);
     //add p32
     uint32_t p32(uint32_t input,bool little);
     //add p64
     uint64_t p64(uint64_t input,bool little);
     //debug
     void print_all(void);
     
};

#endif
