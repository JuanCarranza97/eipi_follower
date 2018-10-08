#ifndef GPIO_H
#define GPIO_H

#include <Arduino.h>
#include "eipi_follower.h"

#define LED_1          13
#define LED_2           4
#define LED_3           3
#define SW_1_PIN      12
#define SW_2_PIN      11
#define SW_1          (!digitalRead(SW_1_PIN))
#define SW_2          (!digitalRead(SW_2_PIN))
#define LED_1_ON      (digitalWrite(LED_1,HIGH))
#define LED_2_ON      (digitalWrite(LED_2,HIGH))
#define LED_3_ON      (digitalWrite(LED_3,HIGH))
#define LED_1_OFF     (digitalWrite(LED_1,LOW))
#define LED_2_OFF     (digitalWrite(LED_2,LOW))
#define LED_3_OFF     (digitalWrite(LED_3,LOW))

void GPIO_init(void);




#endif 
