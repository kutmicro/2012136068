#include "JoysickShield.h"
int gear;
int Joystick_XY(){
	int dir=0;		//방향을 나타낸다.
	if(isCenter()==true) dir=0;
	else if(isUp()==true) dir=8;
	else if(isDown()==true)dir=2;
	else if(isLeft()==true)dir=4;
	else if(isRight()==true)dir=6;
	else if(isLeftUp()==true)dir=7;
	else if(isLeftDown()==true)dir=1;
	else if(isRigthUp()==true)dir=9;
	else if(isRightDown()==true)dir=3;
	else return 0;

	return dir;
}

int Joystick_Button(){
	int but=0;
	if(isJoystickButoon()==true) but=1;
	else if(isUpButton()==true) but=2;
	else if(isDownButton()==true)but=3;
	else if(isLeftButton()==true)but=4;
	else if(isRightButton()==true)but=5;
	else if(isFButton()==true)but=6;
	else if(isEButton()==true)but=7;
	else but=0;

	return but;
}
