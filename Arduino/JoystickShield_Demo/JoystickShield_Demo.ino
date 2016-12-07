#include"JoystickShield_IS_set.h"
SoftwareSerial BT(14,15);
void setup(){
  Serial.begin(9600);
  BT.begin(9600);
}

void loop(){

  Joy.processCallbacks();
  int dir;
  dir = Joystick_XY();
  int but;
  but = Joystick_Button();
  int sum=dir*10+but;
  BT.print(dir);
  
  Serial.print(sum);
 // Serial.print(but);
  delay(100);
  Joy.clear();
}

