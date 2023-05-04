#ifndef LIB_SHIFTREGISTER_SHIFTREGISTER_H_
#define LIB_SHIFTREGISTER_SHIFTREGISTER_H_
#include <Arduino.h>

class ShiftRegister {
  private:
    int PIN_SER, PIN_RCLK, PIN_SRCLK;

  public:
    ShiftRegister(int _pin_ser, int _pin_rclk, int _pin_srclk);
    void setup();
    void setLedRow(byte _byte);
};

#endif // LIB_SHIFTREGISTER_SHIFTREGISTER_H_