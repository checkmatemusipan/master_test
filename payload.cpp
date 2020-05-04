#include "payload.h"
#include <string>
#include <string.h>
//need to make template function
uint32_t big2little(uint32_t big,uint32_t size){
   uint32_t little=0;
   for(int32_t i=0;i<size;i++){
	*(uint8_t*)((uint8_t*)&little+(size-1-i)) = *(uint8_t*)((uint8_t*)&big+i);
   }
   return little;
}

uint64_t big2little(uint64_t big,uint32_t size){
   uint64_t little=0;
   for(int32_t i=0;i<size;i++){
        *(uint8_t*)((uint8_t*)&little+(size-1-i)) = *(uint8_t*)((uint8_t*)&big+i);
   }
   return little;
}


payload::payload(){
   this->memlength =0;
   this->paylength =0;
   this->pay = nullptr;
   if(this->make_buffer()){
      return;
   }else{
      std::cout <<"error class payload make" << std::endl;
   }
}

payload::~payload(){
   if( this->pay == nullptr || this->memlength != 0)
	   return;
   if( this->pay != nullptr ){
	   delete [] this->pay;
	   this->memlength =0;
	   this->paylength =0;
	   this->pay       =nullptr;
   }
}

void payload::print_all(void){
   std::cout << "paylength = " << this->paylength << std::endl;
   std::cout << "memlength = " << this->memlength << std::endl;
   std::cout << "payload   = " << this->pay       << std::endl;
   std::cout << "payload ptr=" << (void*)this->pay<< std::endl;
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
     input_ = big2little(input,4);
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

uint64_t payload::p64(uint64_t input, bool little){
  uint64_t input_=0;
  if(little){
     input_ = big2little(input,8);
  }else{
          input_ = input;
  }
  if(this->paylength == 0xdeadbeef){
     memcpy(this->pay, (void*)&input_,sizeof(uint64_t));
     this->paylength = 8;
     return this->paylength;
  }
  else{
     if( (this->paylength +8) >=  this->memlength){
         uint8_t* temp_mov;
         temp_mov = new uint8_t[this->memlength+0x10];
         memcpy(temp_mov, this->pay, this->paylength);
         delete[] this->pay;
         this->pay = temp_mov;
         //need add input<-arg
         memcpy( (this->pay)+this->paylength, (uint8_t*)&input_, 8);
         this->paylength +=8;
         this->memlength +=0x10;
         return this->paylength;
     }
     else{//ueto onaji shoriyanke misstake sabunn wo kangaeyoune
         uint8_t* temp_mov;
         memcpy( (this->pay)+this->paylength, (uint8_t*)&input_, 8);
         this->paylength +=8;
         return this->paylength;
     }
  }
  return 0xdead6464;
}

