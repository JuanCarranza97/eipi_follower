#include "Controlador.h"
int line_color= true; //si es 1 es linea negra; si es 0 linea blanca
<<<<<<< HEAD
bool state=true;

=======
//puto el que lo lea
>>>>>>> 7c3e8ed65640f1d58b3e62d3c3e3cf27e1345c34
void main_controller(void){
  int posicion = leer_linea(line_color);

          if(posicion==-3){
             set_motors(0,0);
             while(!SW_2){
               LED_1_ON;
               LED_2_ON;
               LED_3_ON;
               delay(100);
               LED_1_OFF;
               LED_2_OFF;
               LED_3_OFF;
               delay(100);
             }
             while(SW_2);
             delay (50);
             state=false;
          }
          else{
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

          }
}

