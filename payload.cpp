#include "payload.h"
#include <string>

payload::payload(){
   this->paylength =0;
   this->pay = nullptr;
}

payload::~payload(){
   if( this->pay == nullptr)
	   return;
}

bool payload::ctrlbuff(){
   
}

bool payload::make_buffer(){
}
