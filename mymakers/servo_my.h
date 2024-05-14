
#ifndef _servo_my_H_
#define _servo_my_H_
#include "Servo.h"
#define sevoLEO0 PB0
#define sevoLEO1 PB1

#define sevoLEO6 PA6
#define sevoLEO7 PA7
Servo servo_LEO0;
Servo servo_LEO1;

Servo servo_LEO6;
Servo servo_LEO7;

void servo(int servo,int angle)
{  

  if (servo==0)
    {
        servo_LEO0.attach(sevoLEO0);
        servo_LEO0.write(angle);
    }
  
  if (servo==1)
    {
        servo_LEO1.attach(sevoLEO1);
        servo_LEO1.write(angle);
    }

  if (servo==6)
    {
        servo_LEO6.attach(sevoLEO6);
        servo_LEO6.write(angle);
    }
  if (servo==7)
    {
        servo_LEO7.attach(sevoLEO7);
        servo_LEO7.write(angle);
    }
}

void servo_non(int servo)
{  
       pinMode(PB0,OUTPUT);
       pinMode(PB1,OUTPUT);
     
       pinMode(PA6,OUTPUT);
       pinMode(PA7,OUTPUT);
 
  if (servo==1)
    {
       analogWrite(PB1,0);
    }


  if (servo==6)
    {
       analogWrite(PA6,0);
    }
  if (servo==7)
    {
      analogWrite(PA7,0);
    }

}
/*
void servo_non(int servo)
{  
       
  if (servo==0)
    {
        servo_LEO0.attach(sevoLEO0);       
        servo_LEO0.attached();
        servo_LEO0.detach();
        
    }

  if (servo==1)
    {
        servo_LEO1.attach(sevoLEO1);
        servo_LEO1.attached();
        servo_LEO1.detach();
    }


  if (servo==6)
    {
        servo_LEO6.attach(sevoLEO6);
        servo_LEO6.attached();
        servo_LEO6.detach();
    }
  if (servo==7)
    {
        servo_LEO7.attach(sevoLEO7);
        servo_LEO7.attached();
        servo_LEO7.detach();
    }

}
*/
#endif
