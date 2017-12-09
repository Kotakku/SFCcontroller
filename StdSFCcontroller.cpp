#include "StdSFCcontroller.h"

/**
コンストラクタ
@since 1.0.0
@param
@return
**/
SFCcontroller::SFCcontroller(uint8_t clk, uint8_t ps, uint8_t dat)
{
  _CLK = clk;
  _PS = ps;
  _DAT = dat;
  
  OUTPUTPIN_CHANGE(_CLK, reg_CLK, bit_CLK);
  OUTPUTPIN_CHANGE(_PS,  reg_PS,  bit_PS);
  INPUTPIN_CHANGE(_DAT, reg_DAT, bit_DAT);
  
  pinMode(_CLK, OUTPUT);
  pinMode(_PS,  OUTPUT);
  pinMode(_DAT, INPUT);
}

/**
ボタンの状態を更新するループ毎に呼び出す
@since 1.0.0
@param
@return
**/
void SFCcontroller::updateButtonState()
{
  bool pastButtonState = false;

  for(int i = 0; i < 16; i++)
  {
    if (i == 0)
    {
      //PSを一回HIGHにして読み取り開始
      *reg_PS |= bit_PS;
      *reg_CLK |= bit_CLK;
      *reg_PS &= ~bit_PS;
      *reg_CLK &= ~bit_CLK;
    } else
    {
      //CLKをHIGHにして読み取るボタン番号を進める
      *reg_CLK |= bit_CLK;
      *reg_CLK &= ~bit_CLK;
    }

    pastButtonState = _buttonState[i];

    //ボタン読み取り(押したらLOW)
    _buttonState[i] = !(*reg_DAT & bit_DAT);

    if (!pastButtonState && _buttonState[i])
      _buttonClick[i] = true;
    else
      _buttonClick[i] = false;
  }
}

/**
指定したボタンの状態を返す
@since 1.0.0
@param 
uint8_t button ボタンを指定(ヘッダで指定した定数使用可)
@return
bool 指定したボタンが押されてたらtrue
**/
bool SFCcontroller::getButtonPress(uint8_t button)
{
  return _buttonState[button];
}

/**
指定したボタンの状態(クリック)を返す
@since 1.0.0
@param 
uint8_t button ボタンを指定(ヘッダで指定した定数使用可)
@return
bool 指定したボタンがクリックされたらtrue
**/
bool SFCcontroller::getButtonClick(uint8_t button)
{
  return _buttonClick[button];
}