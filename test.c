#include <stdio.h>
#include <string.h>

char* str1="ABCD\000EFG"; 
int main(){
  char buf[32]={0};
  memcpy(&buf,str1,8);
  printf("%s\n",buf);
  printf("%s\n",&buf[5]);
  return 0;
}
