#include "eipi_follower.h"
bool line_run = false;
extern int line_color;
extern bool state;

/*  S1 corre
 *  si esta corriendo y se levanta S2 lo saca del ciclo
 */
void setup() {
  Serial.begin(9600);
  Serial.println("Bienvenido al seguidor ealaipicito");
  ayuda();
  ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));  // remove bits set by Arduino library
  ADCSRA |= (1 << ADPS2);    // set our own prescaler to 64*/
  barra_init();
  motores_init();
  GPIO_init();
  read_calibration();
  imprimir_calibracion();
  line_color= EEPROM.read(LINE_COLOR_ADDR);
  if(line_color){
          Serial.println("Color de la linea negro");
        }
        else{
          Serial.println("Color de la linea blanca");
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
    terminal();
  
}
void ayuda(void){
  Serial.println();
  Serial.println("**********AYUDA**********");
  Serial.println("a-imprime los valores de la barra sin mapear");
  Serial.println("b-imprime los valores de la barra mapeados");
  Serial.println("c-calibra");
  Serial.println("s-guarda la calibracion");
  Serial.println("p-cambia el color de la linea");
  Serial.println("m-muestra la posicion de la linea");
  Serial.println("***********************");
  Serial.println();
}

void terminal (void){
  if (Serial.available()){
    int x = Serial.read();
    switch(x){
      
      case 's':
        Serial.println("Guardando en EEPROM");
        for(int i=0; i<10; i++){
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
        save_calibration();
        Serial.println("Guardado");
        break;
        
      case 'c': 
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
        calibrar(20000);
        LED_1_OFF;
        imprimir_calibracion(); 
        break;
        
      case 'a':
        for(int i=0; i<250; i++){
          leer_sensores(2);
          imprimir_sensores();
          delay(50);
        }
        break;
        
      case 'b':
        for(int i=0; i<250; i++){
          leer_sensores(line_color);
          imprimir_sensores();
          delay(50);
        }
        break;
        
      case 'm':
        for(int i=0; i<250; i++){
          main_controller();
          delay(50);
        }
        break;

      case 'p':
        line_color=!line_color;
        EEPROM.write(LINE_COLOR_ADDR, line_color);
        if(line_color){
          Serial.println("Color de la linea negro");
        }
        else{
          Serial.println("Color de la linea blanca");
        }
        break; 
        
      default: 
        Serial.println();
        Serial.println("-------------ERROR-------------");
        Serial.println("CARACTER INTRODUCIDO NO VALIDO");
        ayuda();
        break;
     
    }
  }
}

