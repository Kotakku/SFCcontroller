#include <StdSFCcontroller.h>

#define PIN_CLK 3
#define PIN_PS  4
#define PIN_DAT 5

SFCcontroller SFC(PIN_CLK, PIN_PS, PIN_DAT);

void setup()
{
  Serial.begin(57600);
}

void loop()
{
  SFC.updateButtonState();

  if(SFC.getButtonClick(BUTTON_A))
    Serial.println("BUTTON_A");
  if(SFC.getButtonClick(BUTTON_B))
    Serial.println("BUTTON_B");
  if(SFC.getButtonClick(BUTTON_X))
    Serial.println("BUTTON_X");
  if(SFC.getButtonClick(BUTTON_Y))
    Serial.println("BUTTON_Y");
  if(SFC.getButtonClick(BUTTON_UP))
    Serial.println("BUTTON_UP");
  if(SFC.getButtonClick(BUTTON_DOWN))
    Serial.println("BUTTON_DOWN");
  if(SFC.getButtonClick(BUTTON_LEFT))
    Serial.println("BUTTON_LEFT");
  if(SFC.getButtonClick(BUTTON_RIGHT))
    Serial.println("BUTTON_RIGHT");
  if(SFC.getButtonClick(BUTTON_L))
    Serial.println("BUTTON_L");
  if(SFC.getButtonClick(BUTTON_R))
    Serial.println("BUTTON_R");
  if(SFC.getButtonClick(BUTTON_START))
    Serial.println("BUTTON_START");
  if(SFC.getButtonClick(BUTTON_SELECT))
    Serial.println("BUTTON_SELECT");

}