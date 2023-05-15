#include <Arduino.h>
#include "ShiftRegister.h"

ShiftRegister shift_register = ShiftRegister( 2, 3, 4);

byte matrix_data_y, matrix_data_x;

void setup() {
  shift_register.setup();
  //randomSeed(analogRead(7));
  matrix_data_y = B10101010;
  matrix_data_x = B00000001;
}

#define FPS 120.0 /*fps*/
#define COLUMN 8.0 /*行*/
#define DELAY_T_US (1000000.0 / FPS / COLUMN)

void loop() {
  shift_register.setLedRow(matrix_data_y);
  shift_register.setLedRow(matrix_data_x);

  delayMicroseconds(DELAY_T_US);

  matrix_data_y <<= 1;
  if(matrix_data_y  == B01010100){
    matrix_data_y += 1;
  }

  matrix_data_x <<= 1;
  if(matrix_data_x == 0){
    matrix_data_x += 1;
  }
}