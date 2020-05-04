#include "payload.h"
#include <string>
#include <string.h>

payload::payload(){
   this->memlength =0;
   this->paylength =0;
   this->pay = nullptr;
}

payload::~payload(){
   if( this->pay == nullptr || this->memlength != 0)
	   return;
}

bool payload::ctrlbuff(){
   
}

bool payload::make_buffer(){
  this->pay = new uint8_t[0x10];
  this->paylength = 0xdeadbeef; 
  this->memlength = 0x10;
}

uint32_t payload::p32(uint32_t input){
  if(this->paylength == 0xdeadbeef){
     memcpy(this->pay, (void*)input,sizeof(uint32_t));
     this->paylength = 4;
  }
  else{
     if( (this->paylength +4) >=  this->memlength){
	 uint8_t* temp_mov;
	 temp_mov = new uint8_t[this->memlength+4];
	 memcpy(temp_mov, this->pay, this->paylength);
	 delete[] this->pay;
	 this->pay = temp_mov;
	 //need add input<-arg
	 this->paylength +=4;
	 this->memlength +=0x10;
	 return sizeof(uint32_t);
     }
  }
}
