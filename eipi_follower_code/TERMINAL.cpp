#include "TERMINAL.h"
extern int line_color;
extern int kp, ki, kd, velocidad, set_point;

terminal_actions actions[]={
  {terminalAction_a,'a',2,"Muestra sensores sin mapear n veces cada x tiempo","Mostrar los sensores sin mapear"},
  {terminalAction_b,'b',2,"Muestra sensores mapeados n veces cada x tiempo","Mostrar los valores mapeados"},
  {terminalAction_c,'c',1,"Calibra x veces","Calibrado"},
  {terminalAction_e,'e',1,"Lee o escribe los valores de EEPROM","EEPROM done"},
  {terminalAction_m,'m',2,"Muestra la posicion de la linea n veces cada x tiempo","Linea mostrada"},
  {terminalAction_p,'p',1,"Cambio de linea","Linea cambiada"},
  {terminalAction_k,'k',2,"Constantes del PID","PID actualizado"},
  {terminalAction_r,'r',1,"Mostrando constantes del PID","Valores leidos"},
};


#define TERMINAL_ACTIONS_SIZE (sizeof(actions)/sizeof(terminal_actions))

void terminal_lab(void){
  if(UART_PORT.available()){
      char caracter;
      int Numbers[20];
      int bufferSize=0;

        if(uart_get(&caracter,&bufferSize,Numbers)){
           bool found = false;
      
              for(int i = 0;i<TERMINAL_ACTIONS_SIZE;i++){
                if(caracter == actions[i].caracter){
                  found = true;
                  if(actions[i].tam == bufferSize){
                    actions[i].Callback(Numbers);
                    UART_PORT.println(actions[i].actionString);
                  }                
                }
              }
              if(found==false){
                UART_PORT.println("------ERROR----- \n comando introducido no encontrado");
                for(int i=0; i<TERMINAL_ACTIONS_SIZE; i++){
                  UART_PORT.println("  -" + String(actions[i].caracter)+"-"+String(actions[i].helpString));
                  
                }
              }
        }
  }  
}

void welcome_messege(void){
   UART_PORT.println("---Bienvenido a EIPI FOLLOWER---");
                for(int i=0; i<TERMINAL_ACTIONS_SIZE; i++){
                  UART_PORT.println("  -" + String(actions[i].caracter)+"-"+String(actions[i].helpString));
                }
}
void terminalAction_a(int var[]){
     for(int i=0; i<var[0]; i++){
          leer_sensores(2);
          imprimir_sensores();
          delay(var[1]);
        }
}

void terminalAction_b(int var[]){
     for(int i=0; i<var[0]; i++){
          leer_sensores(line_color);
          imprimir_sensores();
          delay(var[1]);
        }
}

void terminalAction_c(int var[]){
     for(int i=0; i<10; i++){
          LED_1_ON;
          LED_2_OFF;
          LED_3_OFF;
          delay(100);
          LED_2_ON;
          LED_1_OFF;
          LED_3_OFF;
          delay(100);
          LED_3_ON;
          LED_2_OFF;
          LED_1_OFF;
          delay(100);
        }
        LED_3_OFF;
        LED_2_OFF;
        LED_1_ON;
        calibrar(var[0]);
        LED_1_OFF;
        imprimir_calibracion(); 
}

void terminalAction_e(int var[]){
    UART_PORT.println("Accediendo a EEPROM");
        for(int i=0; i<5; i++){
          LED_1_ON;
          LED_2_OFF;
          LED_3_ON;
          delay(100);
          LED_2_ON;
          LED_1_OFF;
          LED_3_OFF;
          delay(100);
          LED_3_ON;
          LED_2_OFF;
          LED_1_ON;
          delay(100);
        }
        LED_1_OFF;
        LED_2_OFF;
        LED_3_OFF;
        if(var[0]==0){
          save_calibration();
          write_kvalues();
          UART_PORT.println("Guardado");
        }
        else{
          read_calibration();
          read_kvalues();
          UART_PORT.println("Leido");
        }
        
}

void terminalAction_m(int var[]){
     for(int i=0; i<var[0]; i++){
          main_controller();
          delay(var[1]);
        }
}

void terminalAction_p(int var[]){
  if(var[0]==1)line_color=1;
  else if (var[0]==0)line_color=0;  
        EEPROM.write(LINE_COLOR_ADDR, line_color);
        if(line_color){
          UART_PORT.println("Color de la linea negro");
        }
        else{
          UART_PORT.println("Color de la linea blanca");
        }
}

void terminalAction_k(int var[]){
    switch(var[0]){
      case 0:
      kp=var[1];
      break;
      case 1:
      ki=var[1];
      break;
      case 2:
      kd=var[1];
      break;
      case 4:
      velocidad=var[1];
      break;
      case 5:
      set_point=var[1];
      break;
      default:
      break;
    }
}

void terminalAction_r(int var[]){
  switch(var[0]){
    case 0:
    UART_PORT.println("kp= "+ String(kp));
    break;
    case 1:
    UART_PORT.println("ki= "+ String(ki));
    break;
    case 2:
    UART_PORT.println("kd= "+ String(kd));
    break;
    case 3:
    read_calibration();
    imprimir_calibracion();
    case 4:
    UART_PORT.println("Velocidad= "+ String(velocidad));
    break;
    case 5:
    UART_PORT.println("Set point= "+ String(set_point));
    break;
    default:
    break;
    
    

    
  }
}
