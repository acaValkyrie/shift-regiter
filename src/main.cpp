#include <Arduino.h>
#include "ShiftRegister.h"

ShiftRegister shift_register = ShiftRegister( 2, 3, 4);


const int analog = 50;
const int freq_Hz = 60;
const int time_high_ms = analog / 255.0 / freq_Hz * 1000;
const int time_low_ms = 1.0/freq_Hz * 1000 - time_high_ms;


void setup() {
  shift_register.setup();
  randomSeed(analogRead(7));
  
}

#define DT_MS 100
int num_rand;



void loop() {
  byte led_row = B00000011;
  shift_register.setLedRow(led_row);
  delay(time_high_ms);

  led_row = B00000010;
  shift_register.setLedRow(led_row);
  delay(time_low_ms);
}