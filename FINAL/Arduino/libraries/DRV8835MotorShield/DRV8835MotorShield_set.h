#include "DRV8835MotorShield.h"
#include "Ultrasonic.h"
Ultrasonic ulFront(2,3);
Ultrasonic ulRight(29,28);
Ultrasonic ulLeft(26,27);
DRV8835MotorShield motors;
int gear;
bool brk=false;
void straight(int i){
	if(i==0||brk) motors.setSpeeds(0,0);
	else if(i==1) 
	{
		motors.setSpeeds(120,120);
	}
	else if(i==2)
	{
		motors.setSpeeds(240,240);
	}
	else if(i==3)
	{
		motors.setSpeeds(400,400);
	}
	else motors.setSpeeds(0,0);
}
void back(int i){
	if(i==0) motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(-80,-80);
	}
	else if(i==2)
	{
		motors.setSpeeds(-160,-160);
	}
	else if(i==3)
	{
		motors.setSpeeds(-240,-240);
	}
	else motors.setSpeeds(0,0);
}
void stlf(int i)
{
	if(i==0||brk) motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(120,50);
	}
	else if(i==2)
	{
		motors.setSpeeds(240,100);
	}
	else if(i==3)
	{
		motors.setSpeeds(360,150);
	}
	else motors.setSpeeds(0,0);
}
void stri(int i)
{
	if(i==0||brk) motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(50,120);
	}
	else if(i==2)
	{
		motors.setSpeeds(100,240);
	}
	else if(i==3)
	{
		motors.setSpeeds(150,360);
	}
	else motors.setSpeeds(0,0);
}
void bclf(int i)
{
	if(i==0) motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(-70,-35);
	}
	else if(i==2)
	{
		motors.setSpeeds(-140,-70);
	}
	else if(i==3)
	{
		motors.setSpeeds(-210,-105);
	}
	else motors.setSpeeds(0,0);
}
void bcri(int i)
{
	if(i==0)motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(-35,-70);
	}
	else if(i==2)
	{
		motors.setSpeeds(-70,-140);
	}
	else if(i==3)
	{
		motors.setSpeeds(-105,-210);
	}
	else motors.setSpeeds(0,0);
}
void left(int i){
	if(i==0){
		motors.setSpeeds(70,-70);
	}
	else if(i==1)
	{
		motors.setSpeeds(100,-100);
	}
	else if(i==2)
	{
		motors.setSpeeds(150,-150);
	}
	else if(i==3)
	{
		motors.setSpeeds(200,-200);
	}
	else motors.setSpeeds(0,0);
}
void right(int i){
	if(i==0){
		motors.setSpeeds(-70,70);
	}
	else if(i==1)
	{
		motors.setSpeeds(-100,100);
	}
	else if(i==2)
	{
		motors.setSpeeds(-150,150);
	}
	else if(i==3)
	{
		motors.setSpeeds(-200,200);
	}
	else motors.setSpeeds(0,0);
}
void stop()
{
	motors.setSpeeds(0,0);
}
void color(int col)
{
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
		digitalWrite(34,HIGH);
	}
	else if (col==6)
	{ 
		digitalWrite(32,HIGH);
		digitalWrite(33,LOW);
		digitalWrite(34,LOW); 
	}
	else if(col==7)
	{
		digitalWrite(32,LOW);
		digitalWrite(33,LOW);
		digitalWrite(34,LOW); 
	}
	else {
		digitalWrite(32,HIGH);
		digitalWrite(33,HIGH);
		digitalWrite(34,HIGH); 
	}
}

void autoRun(int i)
{
	delay(100);
	if (ulFront.Ranging(CM)>9) straight(i);
	else 
	{
		if(ulLeft.Ranging(CM)<ulRight.Ranging(CM)){
			right(2);
			delay(500);
			while(ulLeft.Ranging(CM)<15){
				straight(i);
				delay(100);
			}
			straight(i);
			delay(1200);
			left(2);
			delay(370);
		}
		else{
			left(2);
			delay(500);
			while(ulRight.Ranging(CM)<15){
				straight(i);
				delay(100);
			}
			straight(i);
			if(i==1) delay(1200);
			else if(i==2) delay(500);
			else if(i==3) delay(330);
			right(2);
			delay(400);
		}
	}
}
int colorVal(){

	if(ulFront.Ranging(CM)<10) return 1;
	else if(ulFront.Ranging(CM)<15) return 2;
	else if(ulFront.Ranging(CM)<20) return 3;
	else if(ulFront.Ranging(CM)<25) return 4;
	else if(ulFront.Ranging(CM)<30) return 5;
	else if(ulFront.Ranging(CM)<30) return 6;

	else if(ulFront.Ranging(CM)<40)  return 7;
	else return 0;

}
