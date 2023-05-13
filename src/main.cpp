#include <Arduino.h>
#include "ShiftRegister.h"

ShiftRegister shift_register = ShiftRegister( 2, 3, 4);

byte vertical, horizontal;

void setup() {
  shift_register.setup();
  //randomSeed(analogRead(7));
  vertical   = B00000000;
  horizontal = B00000001;
}

void loop() {
  shift_register.setLedRow(vertical);
  shift_register.setLedRow(horizontal);
  delay(1000);
  horizontal <<= 1;
  if(horizontal == 0){
    horizontal += 1;
  }
}