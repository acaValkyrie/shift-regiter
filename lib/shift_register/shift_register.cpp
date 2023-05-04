#include "shift_register.h"
#include <Arduino.h>

ShiftRegister::ShiftRegister(int pin_ser, int pin_rclk, int pin_srclk){
      PIN_SER   = pin_ser;
      PIN_RCLK  = pin_rclk;
      PIN_SRCLK = pin_srclk;
}

void ShiftRegister::Setup(){
  pinMode( PIN_SER, OUTPUT );
  pinMode( PIN_RCLK, OUTPUT );
  pinMode( PIN_SRCLK, OUTPUT );
  digitalWrite(PIN_SRCLK, LOW);
}

void ShiftRegister::SetLedRow(byte _byte){
  // SRCLK はLOWからスタート
  digitalWrite(PIN_SRCLK, LOW);

  // シフトレジスタ動作させる
  // SRCLK の立ち上がりに同期
  // 多分 SRCLK が01クロック信号出しまくってそれでフリップフロップしてる
  shiftOut(PIN_SER, PIN_SRCLK, LSBFIRST, _byte);

  // シフトレジスタの出力をストレージレジスタに転送
  // RCLK の立ち上がりに同期
  digitalWrite(PIN_RCLK, LOW);
  digitalWrite(PIN_RCLK, HIGH);
}