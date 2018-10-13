#ifndef EEPROM_16_H
#define EEPROM_16_H

#include <Arduino.h>
#include<EEPROM.h>
#include "eipi_follower.h"

int eeprom_read_16(int addr);
void eeprom_write_16(int addr, int val);

#endif
