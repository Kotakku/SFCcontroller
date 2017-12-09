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

  if(SFC.getButtonPress(BUTTON_A))
    Serial.println("BUTTON_A");
  if(SFC.getButtonPress(BUTTON_B))
    Serial.println("BUTTON_B");
  if(SFC.getButtonPress(BUTTON_X))
    Serial.println("BUTTON_X");
  if(SFC.getButtonPress(BUTTON_Y))
    Serial.println("BUTTON_Y");
  if(SFC.getButtonPress(BUTTON_UP))
    Serial.println("BUTTON_UP");
  if(SFC.getButtonPress(BUTTON_DOWN))
    Serial.println("BUTTON_DOWN");
  if(SFC.getButtonPress(BUTTON_LEFT))
    Serial.println("BUTTON_LEFT");
  if(SFC.getButtonPress(BUTTON_RIGHT))
    Serial.println("BUTTON_RIGHT");
  if(SFC.getButtonPress(BUTTON_L))
    Serial.println("BUTTON_L");
  if(SFC.getButtonPress(BUTTON_R))
    Serial.println("BUTTON_R");
  if(SFC.getButtonPress(BUTTON_START))
    Serial.println("BUTTON_START");
  if(SFC.getButtonPress(BUTTON_SELECT))
    Serial.println("BUTTON_SELECT");

}