
#ifndef UART_1_H
#define UART_1_H

  #include <Arduino.h>

  #include "eipi_follower.h"
  
  #define UART_PORT          Serial
  #define UART_BAUD            9600

  #define MAX_TIME             2000
  #define CHAR_ENDS              '\n'
  #define NUMBERS_BETWEEN         ','
  
  //#define UART_LOG

  void uart_init(void);
  bool uart_get(char *caracter_salida,int *size_,int _datos[]); 

#endif
