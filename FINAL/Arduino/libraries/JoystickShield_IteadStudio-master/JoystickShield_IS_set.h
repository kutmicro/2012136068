#include"JoystickShield_IS.h"
#include "SoftwareSerial.h"
int gear;
JoystickShield Joy;
int Joystick_XY(){
  int dir=0;    //방향을 나타낸다.
  if(Joy.isCenter()) dir=0;
  else if(Joy.isUp()) dir=8;
  else if(Joy.isDown())dir=2;
  else if(Joy.isLeft())dir=4;
  else if(Joy.isRight())dir=6;
  else if(Joy.isLeftUp())dir=7;
  else if(Joy.isLeftDown())dir=1;
  else if(Joy.isRightUp())dir=9;
  else if(Joy.isRightDown())dir=3;
  else return 0;
  delay(20);
  return dir;
}

int Joystick_Button(){
  int but=0;
  if(Joy.isJoystickButton()) but=1;
  else if(Joy.isUpButton()) but=2;
  else if(Joy.isDownButton())but=3;
  else if(Joy.isLeftButton())but=4;
  else if(Joy.isRightButton())but=5;
  else if(Joy.isDButton())but=6;
  else if(Joy.isEButton())but=7;
  else but=0;
  delay(20);
  return but;
}
