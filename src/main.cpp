#include <Arduino.h>
#include "ShiftRegister.h"

ShiftRegister shift_register = ShiftRegister( 2, 3, 4);


const int analog = 50;
const int freq_Hz = 60;
const int time_high_ms = analog / 255.0 / freq_Hz * 1000;
const int time_low_ms = 1.0/freq_Hz * 1000 - time_high_ms;

byte vertical, horizontal;

void setup() {
  shift_register.setup();
  //randomSeed(analogRead(7));
  vertical   = B00000000;
  horizontal = B00000001;
}

#define DT_MS 100
int num_rand;



void loop() {
  shift_register.setLedRow(vertical);
  shift_register.setLedRow(horizontal);
  delay(1000);
  horizontal <<= 1;
  if(horizontal == 0){
    horizontal += 1;
  }
}