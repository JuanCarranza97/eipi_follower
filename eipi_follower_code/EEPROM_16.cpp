#include "EEPROM_16.h"

int eeprom_read_16(int addr){
  int LSB=EEPROM.read(addr);
  int MSB=EEPROM.read(addr+1)<<8;
  int x= MSB|LSB;
  return x;
}

void eeprom_write_16(int addr, int val){
    int LSB= val&0x00FF;
    int MSB= (val&0xFF00)>>8;
    #ifdef DEBUG
      Serial.print("MSB= ");
      Serial.print(MSB,HEX);
      Serial.print(", LSB= ");
      Serial.println (LSB,HEX);
    #endif
    EEPROM.write(addr, (byte)(LSB));
    EEPROM.write(addr+1,(byte)(MSB));
}

