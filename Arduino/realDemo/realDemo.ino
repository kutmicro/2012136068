#include "DRV8835MotorShield_set.h"
#include "Ultrasonic.h"
int val;
int dir;
int but;

Ultrasonic ultrasonic(13,12);
void setup(){
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  digitalWrite(32,HIGH);
  digitalWrite(33,HIGH);
  digitalWrite(34,HIGH);
  
  Serial.begin(9600);
  motors.flipM1(true);
  val=0;
  gear=0; 
  col=0;
}

void loop() {
  
  if(Serial.available()){
    val=Serial.parseInt();
    dir=val/10;
    but=val%10;
  }
  if(ultrasonic.Ranging(CM)<10){
    col=1;
  }
    else if(ultrasonic.Ranging(CM)<15){
    col=2;
    }
  else if(ultrasonic.Ranging(CM)<20){
    col=3;
    }
   else if(ultrasonic.Ranging(CM)<25){
    col=4;
    }
  else if(ultrasonic.Ranging(CM)<30){
    col=5;
  }
 else if(ultrasonic.Ranging(CM)<30){
    col=6;
  }
  
  else if(ultrasonic.Ranging(CM)<40){
    col=7;
  }
  else{
    col=0;
  }
  if(ultrasonic.Ranging(CM)<7) 
   {
    if(dir==7||dir==8||dir==9||dir==6||dir==4)
    {
      dir=0;
    }
   }
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  Serial.println(gear);
  if(dir==0) stop();
  else if(dir==8) straight(gear);
  else if(dir==7) stlf(gear);
  else if(dir==9) stri(gear);
  else if(dir==4) left(gear);
  else if(dir==6) right(gear);
  else if(dir==1) bclf(gear);
  else if(dir==2) back(gear);
  else if(dir==3) bcri(gear);

  if(but==1) gear=0;
  else if(but==2&&gear!=3) gear++;
 /* else if(but==3){
    col++;
    if(col==1){
      digitalWrite(32,LOW);
      digitalWrite(33,HIGH);
      digitalWrite(34,HIGH);
    }
    else if(col==2) {
      digitalWrite(32,HIGH);
      digitalWrite(33,LOW);
      digitalWrite(34,HIGH);
    }
     else if(col==3) {
      digitalWrite(32,HIGH);
      digitalWrite(33,HIGH);
      digitalWrite(34,LOW);
    }
     else if(col==4) {
      digitalWrite(32,LOW);
      digitalWrite(33,HIGH);
      digitalWrite(34,LOW);
    }
     else if(col==5) {
      digitalWrite(32,LOW);
      digitalWrite(33,LOW);
      digitalWrite(34,LOW);
    }
    if (col==6)
    { 
      digitalWrite(32,HIGH);
      digitalWrite(33,HIGH);
      digitalWrite(34,HIGH);
      col=0;
    }
  }*/
  else if(but==5) {
    digitalWrite(33,LOW);
  }
  else if(but==4&&gear!=0) gear--;
  but=0;

  delay(100);

}
