#include "Controlador.h"
int line_color= true; //si es 1 es linea negra; si es 0 linea blanca
int kp, ki, kd, velocidad, set_point;
bool state=true;

void read_kvalues (void){
  kp = eeprom_read_16(KP_ADDR);
  ki = eeprom_read_16(KI_ADDR);
  kd = eeprom_read_16(KD_ADDR);
  velocidad = EEPROM.read(VELOCIDAD_ADDR);
  set_point = eeprom_read_16(SET_POINT_ADDR);
}

void write_kvalues (void){
  eeprom_write_16(KP_ADDR, kp);
  eeprom_write_16(KI_ADDR, ki);
  eeprom_write_16(KD_ADDR, kd);
  EEPROM.write(VELOCIDAD_ADDR, velocidad);
  eeprom_write_16(SET_POINT_ADDR, set_point);
  }

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
            if(posicion > 0){
          //Control mamalon
          int error= set_point-posicion;
          float k=(error*(float)(float(kp)/float(KP_DIV)));
          float u=k;
          if(u>100) u=100;
          if(u<-100) u=-100;
          set_motors(velocidad-(int)u, velocidad+(int)u);
          
          if (posicion>0){
            LED_1_OFF;
            LED_2_ON;
            LED_3_OFF;
            //Serial.println(posicion);
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
}

