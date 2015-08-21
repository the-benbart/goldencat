#include "drivers_keyboard.h"
#include "drivers_lcd.h"
#include "drivers_captors.h"
#include "interface.h"
////////////////////////////////////////////////////////////////////////////////
//                                PIN TABLE                                   //
////////////////////////////////////////////////////////////////////////////////
// keypad   : A5
// captor   : A4
// LCD -------------NOKIA-5110-----------------
// PIN_SCE  : D7
// PIN_RESET: D6
// PIN_DC   : D5
// PIN_SDIN : D4
// PIN_SCLK : D3
// Motor ------------SN754410NE----------------
//          :
//          :
//          :
//          :
//          :

////////////////////////////////////////////////////////////////////////////////
//                                   INIT system                              //
////////////////////////////////////////////////////////////////////////////////
void setup(void)
{
  LcdInitialise();
  LcdClear();
  pinMode(A5, INPUT_PULLUP);
  Serial.begin(9600);

}
void loop(void)
{
  menuScrollLevel();
}
