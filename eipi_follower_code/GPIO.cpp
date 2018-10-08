#include "GPIO.h"

void GPIO_init(void){
      pinMode(13,OUTPUT);
      pinMode(4,OUTPUT);
      pinMode(3,OUTPUT);
      pinMode(12,INPUT_PULLUP);
      pinMode(11,INPUT_PULLUP);  
}
