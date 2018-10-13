#ifndef MOTORES_H
#define MOTORES_H

#include <Arduino.h>
#include "LINE_CHAVA.h"

#define IN1       9
#define IN2      10
#define IN3       6
#define IN4       5

void motores_init(void);
void set_left_motor(int x);
void set_right_motor(int x);
void set_motors(int x, int y);


#endif
