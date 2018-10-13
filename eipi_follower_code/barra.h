#ifndef BARRA_H
#define BARRA_H

#include <Arduino.h>
#include "eipi_follower.h"


#define S0                  17
#define S1                  16
#define S2                  15
#define OUT                 A0
#define CALIBRATION_TIME    0
#define MIN_DENOMINADOR     100
#define UMBRAL              100
              

//#define DEBUG

void output_leds (int x);
void barra_init (void);
bool leer_sensores(int x);
void imprimir_sensores(void);
void calibrar(int x); 
void imprimir_calibracion(void);
void save_calibration(void);
void read_calibration(void);
int leer_linea(int y);

// leer_sensores(2); sin mapear
// leer_sensores(1); mapeados en linea negra
// leer_sensores(0); mapeados en linea blanca 

#endif
