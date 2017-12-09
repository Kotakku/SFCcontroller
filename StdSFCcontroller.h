/*************************************************
* @Outline: スーパーファミコンのコントローラをArduinoで使う
* @Date: 2017/9/14
* @Author: Takumi Odashima
* @Version: 1.1.0
* @Description:
* @Update:
*   10/10 Ver1.1.0
*     digitalWriteとdigitalReadを使わなくした(ちょっと高速化)
* @TODO:
************************************************/

#ifndef _STD_SFC_CONTROLLER_
#define _STD_SFC_CONTROLLER_

#include <Arduino.h>

typedef volatile uint8_t portRegister;
typedef uint8_t bitMask;

#define OUTPUTPIN_CHANGE(pin, reg, mask) \
  reg = portOutputRegister(digitalPinToPort(pin)); \
  mask = digitalPinToBitMask(pin);

#define INPUTPIN_CHANGE(pin, reg, mask) \
  reg = portInputRegister(digitalPinToPort(pin)); \
  mask = digitalPinToBitMask(pin);

enum buttoneNum
{
  BUTTON_B,
  BUTTON_Y,
  BUTTON_SELECT,
  BUTTON_START,
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_LEFT,
  BUTTON_RIGHT,
  BUTTON_A,
  BUTTON_X,
  BUTTON_L,
  BUTTON_R
};

class SFCcontroller
{
public:
  SFCcontroller(uint8_t clk, uint8_t ps, uint8_t dat);
  void updateButtonState();
  bool getButtonPress(uint8_t button);
  bool getButtonClick(uint8_t button);
private:
  bool _buttonState[16];
  bool _buttonClick[16];

  uint8_t _CLK, _PS, _DAT;
  portRegister *reg_CLK, *reg_PS, *reg_DAT;
  bitMask bit_CLK, bit_PS, bit_DAT;
};
#endif //_STD_SFC_CONTROLLER_
