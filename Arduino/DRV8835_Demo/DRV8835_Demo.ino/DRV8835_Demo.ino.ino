#include "DRV8835MotorShield_set.h"


int val;
void setup(){
  Serial.begin(9600);
  motors.flipM1(true);
  val=0;
  
}

void loop(){
  if(Serial.available()){
    val=Serial.parseInt();
  }

  if(val==1) {
    Serial.print(1);
    straight(1);
  }
  else if(val==2) left(1);
  else if(val==3) right(1);
  else if(val==4) back(1);
  else stop();
  color();
  delay(100);
  
}

