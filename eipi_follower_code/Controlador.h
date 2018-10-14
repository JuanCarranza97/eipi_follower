#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <Arduino.h>
#include "eipi_follower.h"

#define LINE_COLOR_ADDR   32
#define KP_ADDR           33
#define KI_ADDR           35
#define KD_ADDR           37
#define VELOCIDAD_ADDR    39
#define SET_POINT_ADDR    40
#define KP_DIV       1000000
#define KI_DIV       1000000
#define KD_DIV       1000000

void main_controller (void);
void read_kvalues (void);
void write_kvalues (void);

#endif
