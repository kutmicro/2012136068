#include"JoystickShield_IS_set.h"
SoftwareSerial BT(14,15);
void setup(){
  BT.begin(9600);
  Serial.begin(9600);
}

void loop(){
  
  Joy.processCallbacks();
  int dir;
  dir = Joystick_XY();
  int but;
  but = Joystick_Button();
  int sum=dir*10+but;
  BT.write(sum);
  Serial.println(sum);
  Serial.print("x : ");
  Serial.println(analogRead(0));
  
  Serial.print("y : ");
  Serial.println(analogRead(1));
  
  delay(100);
  
  Joy.clear();
}

