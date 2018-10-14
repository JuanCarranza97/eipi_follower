#ifndef TERMINAL_H
#define TERMINAL_H

  #include <Arduino.h>

  #include "eipi_follower.h"
  
  #define TERMINAL_LOG
  
  typedef void (*terminalCallback)(int var[]);  

  typedef struct{
    terminalCallback Callback;
    const char caracter;
    int tam;
    const char *helpString;
    const char *actionString;
  }terminal_actions;

  void terminal_lab(void);
  void welcome_messege(void); 
  void terminalAction_a(int var[]);
  void terminalAction_b(int var[]);
  void terminalAction_c(int var[]);
  void terminalAction_e(int var[]);
  void terminalAction_m(int var[]);
  void terminalAction_p(int var[]);
  void terminalAction_k(int var[]);
  void terminalAction_r(int var[]);

#endif
