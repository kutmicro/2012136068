#include "DRV8835MotorShield.h"

DRV8835MotorShield motors;

void straight(int i){
	if(i==0) motors.setSpeeds(0,0);
	else if(i==1) 
	{
		motors.setSpeeds(100,100);
	}
	else if(i==2)
	{
		motors.setSpeeds(200,200);
	}
	else if(i==3)
	{
		motors.setSpeeds(300,300);
	}
	else motors.setSpeeds(0,0);
}
void back(int i){
	if(i==0) motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(-70,-70);
	}
	else if(i==2)
	{
		motors.setSpeeds(-140,-140);
	}
	else if(i==3)
	{
		motors.setSpeeds(-210,-210);
	}
	else motors.setSpeeds(0,0);
}
void stri(int i)
{
	if(i==0) motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(100,50);
	}
	else if(i==2)
	{
		motors.setSpeeds(200,100);
	}
	else if(i==3)
	{
		motors.setSpeeds(300,150);
	}
	else motors.setSpeeds(0,0);
}
void stlf(int i)
{
	if(i==0) motors.setSpeeds(0,0);
	else if(i==1)
	{
		motors.setSpeeds(50,100);
	}
	else if(i==2)
	{
		motors.setSpeeds(100,200);
	}
	else if(i==3)
	{
		motors.setSpeeds(150,300);
	}
	else motors.setSpeeds(0,0);
}
void bcri(int i)
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
void bclf(int i)
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
		motors.setSpeeds(-210,-105);
	}
	else motors.setSpeeds(0,0);
}
void right(int i){
	if(i==0){
		motors.setSpeeds(70,-30);
	}
	else if(i==1)
	{
		motors.setSpeeds(100,0);
	}
	else if(i==2)
	{
		motors.setSpeeds(150,0);
	}
	else if(i==3)
	{
		motors.setSpeeds(200,0);
	}
	else motors.setSpeeds(0,0);
}
void left(int i){
	if(i==0){
		motors.setSpeeds(-30,70);
	}
	else if(i==1)
	{
		motors.setSpeeds(0,100);
	}
	else if(i==2)
	{
		motors.setSpeeds(0,150);
	}
	else if(i==3)
	{
		motors.setSpeeds(0,200);
	}
	else motors.setSpeeds(0,0);
}