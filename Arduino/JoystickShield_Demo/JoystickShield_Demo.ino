#include"JoystickShield_IS_set.h"
 int val=0;
SoftwareSerial BT(14,15);
void setup(){
  Serial.begin(9600);
  BT.begin(9600);
 
}

void loop(){
  val=(val/10);
  val=val*10;
  /*Joy.processCallbacks();
  int dir;
  dir = Joystick_XY();
  int but;
  but = Joystick_Button();
  int sum=dir*10+but;
  BT.write(sum);*/
  /*
  Serial.print("x:");
  Serial.println(analogRead(1));
  Serial.print("y:");
  Serial.println(analogRead(0));
*/
  if(Serial.available())
   {
    val=Serial.parseInt();
    BT.write(val);
  
   }
  Serial.print(val);
  delay(100);
  Joy.clear();
}

