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
     //operator
     payload  operator +(payload input);// non write yet
     void     operator =(payload input);
     uint32_t operator <<(const char* str);
     //getter
     uint32_t len() const;
     void*    buf();
     //off buffering
     bool ctrlbuff(void);
     bool clear(void);
     //make struct
     bool make_buffer(void);
     //add char*
     uint32_t add(const char* str,uint32_t len);
     //add pack32
     uint32_t p32(uint32_t input,bool little);
     //add pack64
     uint64_t p64(uint64_t input,bool little);
     //unpack
     //u32,u64
     //check in word from payload
     bool check_word(const char* word);
     //debug
     void print_all(void);
<<<<<<< HEAD
     void print_buf(void);
=======
          
>>>>>>> d20a9194f2cd5f8f969f8eb803f239d901a5ac25
};

#endif
