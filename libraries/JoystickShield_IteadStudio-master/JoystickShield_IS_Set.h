#include "JoystickShield_Joy.is.h"
int gear;
JoystickShield Joy;
int Joystick_XY(){
	int dir=0;		//방향을 나타낸다.
	if(Joy.isCenter()==true) dir=0;
	else if(Joy.isUp()==true) dir=8;
	else if(Joy.isDown()==true)dir=2;
	else if(Joy.isLeft()==true)dir=4;
	else if(Joy.isRight()==true)dir=6;
	else if(Joy.isLeftUp()==true)dir=7;
	else if(Joy.isLeftDown()==true)dir=1;
	else if(Joy.isRigthUp()==true)dir=9;
	else if(Joy.isRightDown()==true)dir=3;
	else return 0;
	delay(20);
	return dir;
}

int Joystick_Button(){
	int but=0;
	if(Joy.isJoystickButoon()==true) but=1;
	else if(Joy.isUpButton()==true) but=2;
	else if(Joy.isDownButton()==true)but=3;
	else if(Joy.isLeftButton()==true)but=4;
	else if(Joy.isRightButton()==true)but=5;
	else if(Joy.isFButton()==true)but=6;
	else if(Joy.isEButton()==true)but=7;
	else but=0;

	return but;
}
