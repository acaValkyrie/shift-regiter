#include <Arduino.h>

const int PIN_SER   =  2;
const int PIN_RCLK  =  3;
const int PIN_SRCLK    = 4;

void SetLedRow(byte _byte){
  // シフトレジスタ動作させる
  // SRCLK の立ち上がりに同期
  // 多分 SRCLK が01クロック信号出しまくってそれでフリップフロップしてる
  // オシロで見たけどクロック信号出てない...
  shiftOut(PIN_SER, PIN_SRCLK, LSBFIRST, _byte);

  // シフトレジスタの出力をストレージレジスタに転送
  // RCLK の立ち上がりに同期
  digitalWrite(PIN_RCLK, LOW);
  digitalWrite(PIN_RCLK, HIGH);
}

void setup() {
  pinMode( PIN_SER, OUTPUT );
  pinMode( PIN_RCLK, OUTPUT );
  pinMode( PIN_SRCLK, OUTPUT );
  digitalWrite(PIN_SRCLK, LOW);
}

#define DT_MS 200

void loop() {
  SetLedRow(0b11110000);
  delay(DT_MS);
  SetLedRow(0b00001111);
  delay(DT_MS);
}