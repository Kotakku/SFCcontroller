#include <StdSFCcontroller.h>

#define PIN_CLK 3
#define PIN_PS  4
#define PIN_DAT 5

SFCcontroller SFC(PIN_CLK, PIN_PS, PIN_DAT);

void setup() {
  Serial.begin(57600);
  Serial.println("init");
}

void loop() {
  SFC.updateButtonState();
  showAllbutton();
}

void showAllbutton()
{
  byte buttonArray[] = {
    BUTTON_A,
    BUTTON_B,
    BUTTON_X,
    BUTTON_Y,
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_R,
    BUTTON_L,
    BUTTON_START,
    BUTTON_SELECT
  };

  for(int i = 0; i < 12; i++)
  {
    if(SFC.getButtonPress(buttonArray[i]))
      Serial.print(F("1"));
    else
      Serial.print(F("0"));
  }
  Serial.println(F(""));
}