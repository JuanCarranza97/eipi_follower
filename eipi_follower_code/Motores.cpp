#include "Motores.h"

void motores_init(void){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void set_left_motor(int x){
  if(x>0){
    analogWrite(IN1,map(x,0,100,0,255));
    digitalWrite(IN2, LOW);
  }
  else{
    analogWrite(IN2,map(x,0,-100,0,255));
    digitalWrite(IN1, LOW);
  }
}

void set_right_motor(int x){
  if(x>0){
    analogWrite(IN3,map(x,0,100,0,255));
    digitalWrite(IN4, LOW);
  }
  else{
    analogWrite(IN4,map(x,0,-100,0,255));
    digitalWrite(IN3, LOW);
  }
}

void set_motors(int x, int y){
  set_left_motor(x);
  set_right_motor(y);
}

