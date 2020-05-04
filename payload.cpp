#include "payload.h"
#include <string>
#include <string.h>

uint32_t big2little(uint32_t big){
   uint32_t little=0;
   for(int32_t i=0;i<4;i++){
	*(uint8_t*)((uint8_t*)&little+(3-i)) = *(uint8_t*)((uint8_t*)&big+i);
   }
   return little;
}

payload::payload(){
   this->memlength =0;
   this->paylength =0;
   this->pay = nullptr;
}

payload::~payload(){
   if( this->pay == nullptr || this->memlength != 0)
	   return;
}

void payload::print_all(void){
   std::cout << "paylength = " << this->paylength << std::endl;
   std::cout << "memlength = " << this->memlength << std::endl;
   std::cout << "payload   = " << this->pay      << std::endl;
   std::cout << "payload ptr=" << (void*)this->pay       << std::endl;
}

bool payload::ctrlbuff(){
   return false;
}

bool payload::make_buffer(){
  this->pay = new uint8_t[0x10];
  this->paylength = 0xdeadbeef; 
  this->memlength = 0x10;
  if(this->pay == nullptr)
	  return false;
  return true;
}

uint32_t payload::p32(uint32_t input, bool little){
  uint32_t input_=0;
  if(little){
     input_ = big2little(input);
  }else{
	  input_ = input;
  }
  if(this->paylength == 0xdeadbeef){
     memcpy(this->pay, (void*)&input_,sizeof(uint32_t));
     this->paylength = 4;
     return this->paylength;
  }
  else{
     if( (this->paylength +4) >=  this->memlength){
	 uint8_t* temp_mov;
	 temp_mov = new uint8_t[this->memlength+0x10];
	 memcpy(temp_mov, this->pay, this->paylength);
	 delete[] this->pay;
	 this->pay = temp_mov;
	 //need add input<-arg
	 memcpy( (this->pay)+this->paylength, (uint8_t*)&input_, 4);
	 this->paylength +=4;
	 this->memlength +=0x10;
	 return this->paylength;
     }
     else{//ueto onaji shoriyanke misstake sabunn wo kangaeyoune
	 uint8_t* temp_mov;
	 memcpy( (this->pay)+this->paylength, (uint8_t*)&input_, 4);
	 this->paylength +=4;
	 return this->paylength;
     }
  }
  return 0xdead3232;
}
