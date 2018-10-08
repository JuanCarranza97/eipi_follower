#include "barra.h"
int sensores[8], min_value[8],max_value[8];
int last_position = 0;

void output_leds(int x){
  digitalWrite(S0,x&1);
  digitalWrite(S1,(x&2)>>1);
  digitalWrite(S2,(x&4)>>2);
}

void barra_init (void){
    pinMode(S0,OUTPUT);
    pinMode(S1,OUTPUT);
    pinMode(S2,OUTPUT);
}

void leer_sensores (int x){
   if(x==2){
     for(int i=0; i<8; i++){
        output_leds(i);
        sensores[i]= analogRead(OUT);
     }
  }
  else if(x==1){ //se leerá linea negra
    for(int i=0; i<8; i++){
      output_leds(i);
      sensores[i]=map(analogRead(OUT), min_value[i], max_value[i], 0, 1000);
      if(sensores[i]>1000) sensores[i]=1000;
      if(sensores[i]<0) sensores[i]=0;
    }
  }
  else if(x==0){//se leerá linea blanca
    for(int i=0; i<8; i++){
      output_leds(i);
      sensores[i]=map(analogRead(OUT), min_value[i], max_value[i], 1000, 0);
      if(sensores[i]>1000) sensores[i]=1000;
      if(sensores[i]<0) sensores[i]=0;
    }
  }
}

void imprimir_sensores(void){
  for (int i=0; i<7; i++){
      Serial.print(String(sensores[i])+", "); 
  }
  Serial.println(sensores[7]);
  
}

void calibrar (int x){
    leer_sensores(2);
    for(int i=0;i<8;i++){
      max_value[i]=sensores[i];
      min_value[i]=sensores[i];
    }

    for(int i=1;i<x;i++){
          
          leer_sensores(2);
          for(int i=0; i<8;i++){
            if(sensores[i]>max_value[i]) max_value[i]=sensores[i];
            if(sensores[i]<min_value[i]) min_value[i]=sensores[i];
          }
          delay(CALIBRATION_TIME);
    }
}

void imprimir_calibracion (void){
  Serial.print("Max = ");
  for(int i=0; i<7 ; i++){
     Serial.print(String(max_value[i])+",");   
  }
  Serial.println(max_value[7]);

  Serial.print("Min = ");
  for(int i=0; i<7 ; i++){
     Serial.print(String(min_value[i])+",");   
  }
  Serial.println(min_value[7]);
  
}

void save_calibration(void){
  for(int i=0; i<=7; i++){
    eeprom_write_16(2*i, min_value[i]);
    eeprom_write_16((2*i)|(0x10), max_value[i]);
  }
}

void read_calibration(void){
  for(int i=0; i<=7; i++){
    min_value[i] = eeprom_read_16(2*i);
    max_value[i] = eeprom_read_16((2*i)|(0x10));
  }
}

int leer_linea(int y){
  long numerador = 0;
  int denominador = 0;
  leer_sensores(y);

  for (int i=0; i<8; i++){ 
    numerador += (long)(sensores[i])*i*1000;
    denominador += sensores[i];
    //Serial.print(String(numerador)+" ");
    //Serial.print(String(denominador)+ " ");
  }
  /*Serial.println();
  Serial.println(numerador);
  Serial.println(denominador);*/
  if(denominador<MIN_DENOMINADOR) { //No esta en la linea?
    if(last_position<3500) return -2;// la linea está a la izquierda
    else return -1;//la linea está a la derecha
  }
  
  int x = numerador/denominador;
  last_position = x;
  return x;
}


