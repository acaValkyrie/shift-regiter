#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int _pin_ser, int _pin_rclk, int _pin_srclk){
      PIN_SER   = _pin_ser;
      PIN_RCLK  = _pin_rclk;
      PIN_SRCLK = _pin_srclk;
}

void ShiftRegister::setup(){
  pinMode( PIN_SER, OUTPUT );
  pinMode( PIN_RCLK, OUTPUT );
  pinMode( PIN_SRCLK, OUTPUT );
  digitalWrite(PIN_SRCLK, LOW);
}

void ShiftRegister::setLedRow(byte _byte){
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