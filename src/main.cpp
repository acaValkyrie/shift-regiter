#include <Arduino.h>

const int PIN_SER   =  2;
const int PIN_LATCH  =  3;
const int PIN_CLK    = 4;

void SetLedRow(byte _byte){
  digitalWrite(PIN_LATCH, LOW);
  shiftOut(PIN_SER, PIN_CLK, LSBFIRST, _byte);
  digitalWrite(PIN_LATCH, HIGH);
}

void setup() {
  pinMode( PIN_SER, OUTPUT );
  pinMode( PIN_LATCH, OUTPUT );
  pinMode( PIN_CLK, OUTPUT );

  delay(1000);
}

void loop() {
  SetLedRow(0b01010101);
  delay(1000);
  SetLedRow(0b10101010);
  delay(1000);
}