#include <Arduino.h>
#include "ShiftRegister.h"

ShiftRegister shift_register = ShiftRegister( 2, 3, 4);

void setup() {
  shift_register.setup();
  randomSeed(analogRead(7));
}

#define DT_MS 100
int num_rand;

void loop() {
  num_rand = random(1,255);
  byte led_row = (byte)num_rand;
  
  shift_register.setLedRow(led_row);
  delay(DT_MS);
}