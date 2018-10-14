#include "eipi_follower.h"
bool line_run = false;
extern int line_color;
extern bool state;

/*  S1 corre
 *  si esta corriendo y se levanta S2 lo saca del ciclo
 */
void setup() {
  uart_init();
  welcome_messege();
  ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));  // remove bits set by Arduino library
  ADCSRA |= (1 << ADPS2);    // set our own prescaler to 64*/
  barra_init();
  motores_init();
  GPIO_init();
  read_calibration();
  imprimir_calibracion();
  read_kvalues();
  line_color= EEPROM.read(LINE_COLOR_ADDR);
  if(line_color){
          UART_PORT.println("Color de la linea negro");
        }
        else{
          UART_PORT.println("Color de la linea blanca");
        }
  
}

void loop() {

  if(SW_1){
    LED_1_ON;
    LED_2_ON;
    LED_3_ON;
    while(SW_1);
    for(int i=0; i<3; i++){
      LED_1_OFF;
      LED_2_OFF;
      LED_3_OFF;
      delay(100);
      LED_1_ON;
      LED_2_OFF;
      LED_3_OFF;
      delay(100);
      LED_1_ON;
      LED_2_ON;
      LED_3_OFF;
      delay(100);
      LED_1_ON;
      LED_2_ON;
      LED_3_ON;
      delay(100);
    }
    
    while(!SW_1 && state){
      main_controller();
    }
    set_motors(0,0);
    state=true;
    Serial.println("Me sali del modo carrera");
    LED_1_OFF;
    LED_2_OFF;
    LED_3_OFF;
    while(SW_1);
    delay(50);
    
  }
    terminal_lab();
  
}


