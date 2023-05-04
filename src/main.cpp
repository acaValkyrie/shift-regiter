#include <Arduino.h>
#include "shift_register.h"

ShiftRegister shift_register = ShiftRegister( 2, 3, 4);

void setup() {
  shift_register.Setup();
  randomSeed(analogRead(7));
}

#define DT_MS 100
int num_rand;
void loop() {
  num_rand = random(1,255);
  byte led_row = (byte)num_rand;
  shift_register.SetLedRow(led_row);
  delay(DT_MS);
}