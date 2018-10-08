#include "Controlador.h"
int line_color= true; //si es 1 es linea negra; si es 0 linea blanca

void main_controller(void){
  int posicion = leer_linea(line_color);
          if (posicion>0){
            LED_1_OFF;
            LED_2_ON;
            LED_3_OFF;
            Serial.println(posicion);
          }
          else if(posicion==-1){
            LED_1_ON;
            LED_2_OFF;
            LED_3_OFF;
          }
          else if(posicion==-2){
            LED_1_OFF;
            LED_2_OFF;
            LED_3_ON;
          }
  if(posicion<2500){
    set_motors(10,20);
    if(posicion==-1){
      set_motors(20,10);
    }
    if(posicion==-2){
      set_motors(10,20);
    }
  }
  else if(posicion>=2500 && posicion<=4500){
    set_motors(20,20);
  }
  else if(posicion>4500){
    set_motors(20,10);
  }
}

