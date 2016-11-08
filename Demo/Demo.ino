#include "DRV8835MotorShieldSet.h"
#include "JoystickShield_IS_Set.h"
void Move()
{
  int but=0;
  but=Joystick_Button();
  int dir=0;
  dir=Joystick_XY();
  if(but==2) {
    if (gear==3) break;
    else gear++;
  }
  else if(but==3) {
    if (gear==0) break;
    else gear--;
  }
  else break;
  if(dir==2) straight(gear);
  else if(dir=8) back(gear);
  else if(dir=9) stri(gear);
  else if(dir=7) stlf(gear);
  else if(dir=1) bclf(gear);
  else if(dir=4) left(gear);
  else if(dir=6) right(gear);
  else if(dir=3) bcri(gear);
  else stop();
}
void setup() {
  gear =0;
}

void loop() {
  Move();

}
