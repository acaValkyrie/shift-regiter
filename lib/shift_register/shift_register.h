#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

class ShiftRegister {
  private:
    int PIN_SER, PIN_RCLK, PIN_SRCLK;

  public:
    ShiftRegister(int pin_ser, int pin_rclk, int pin_srclk);
    void Setup();
    void SetLedRow(byte _byte);
};

#endif