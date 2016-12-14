#include "DRV8835MotorShield_set.h"
#include <SoftwareSerial.h>
SoftwareSerial BT(12,11);
int val;
int dir;
int but;
bool coloff=false;
bool at;

void setup(){

  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  digitalWrite(32,HIGH);
  digitalWrite(33,HIGH);
  digitalWrite(34,HIGH);
  BT.begin(9600);
  Serial.begin(9600);
  motors.flipM1(true);
  brk=false;
  val=0;
  gear=0; 
  at=false;
}

void loop(){
  but=0;
  if(BT.available()){
    brk=false; 
    val=BT.read();
    dir=val/10;
    but=val%10;
  }
  if(but==1) gear=0;
  else if(but==2&&gear!=3) gear++;
  else if(but==3) brk=true;
  else if(but==4&&gear!=0) gear--;
  else if(but==5) gear=3;
  else if(but==6) at=true;
  else if(but==7) {
    if(coloff) coloff=false;
    else coloff=true;
  }
  while(at){
    but=0;
    autoRun(gear);
    if(!coloff) color(colorVal());
    else color(0);
    if(BT.available()){

      val=BT.read();
      dir=val/10;
      but=val%10;
    }  
    if(but==2&&gear!=3) gear++;
    else if(but==4&&gear!=0) gear--;
    else if(but==7) {
      if(coloff) coloff=false;
      else coloff=true;
    }
    else if(but==1) at=false;
  }

  if (gear==1)
  {
    if(ulFront.Ranging(CM)<7) 
    brk=true;
  }
  else if(gear==2)
  {
   if (ulFront.Ranging(CM)<10) 
    brk=true;
  }

  else if(gear==3){
  if (ulFront.Ranging(CM)<12) 
    brk=true;
  }
    Serial.println(val);
  Serial.println(brk);
  if(dir==0) stop();
  else if(dir==8) straight(gear);
  else if(dir==7) stlf(gear);
  else if(dir==9) stri(gear);
  else if(dir==4) left(gear);
  else if(dir==6) right(gear);
  else if(dir==1) bclf(gear);
  else if(dir==2) back(gear);
  else if(dir==3) bcri(gear);
  
  if(!coloff) color(colorVal());
  else color(0);
  brk=false;
  delay(70);
}
