#include <Arduino.h>

const int PIN_SER   =  2;
const int PIN_RCLK  =  3;
const int PIN_SRCLK    = 4;

void SetLedRow(byte _byte){
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

void setup() {
  pinMode( PIN_SER, OUTPUT );
  pinMode( PIN_RCLK, OUTPUT );
  pinMode( PIN_SRCLK, OUTPUT );
  digitalWrite(PIN_SRCLK, LOW);

  randomSeed(analogRead(7));
}

// clock frequency 24 (https://electronicwork.shop/items/622dd0c07d1161644599dfa0)
#define DT_MS 100
int num_rand;
void loop() {
  num_rand = random(1,255);
  byte led_row = (byte)num_rand;
  SetLedRow(led_row);
  delay(DT_MS);
}