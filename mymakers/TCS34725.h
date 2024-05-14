#ifndef _TCS34725_H_
#define _TCS34725_H_
#include "Piya_color.h"
 uint16_t r, g, b, c;
 uint16_t color = 0;
   float averag;
    float red ;
    float green ;
    float blue ;
    float average ;
/* Connect SCL    to PB6
   Connect SDA    to PB7
   Connect VDD    to 5V DC
   Connect GROUND to common ground
   PiyamaharachalaiSchool www.piya.ac.th
 */ 
Piya_color tcs = Piya_color(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);
/*
void setup(void) 
  {
    Serial.begin(9600);
    if(tcs.begin());  
  }
void loop(void) 
  {
    col_cal(); 
  }

void col_cal()
  {   
    tcs.getRawData(&r, &g, &b, &c); 
     averag = (r+g+b)/3;
     red = r/averag;
     green = g/averag;
    blue = b/averag;
     average = (red+green+blue)/3;
    Serial.print("R: "); Serial.print(red); Serial.print(" ");
    Serial.print("G: "); Serial.print(green); Serial.print(" ");
    Serial.print("B: "); Serial.print(blue); Serial.print(" ");
    Serial.print("C: "); Serial.print(c); Serial.print(" ");
    Serial.println(" ");
     
    Serial.print(average);Serial.println(" ");
  
    if(red>green&&red>blue&& red>average&&green<average&&blue<average)
      {Serial.println("RED");}
    else if (red<green&&red<blue&&green>blue&& red<average&&green>average&&blue>average)
      {Serial.println("GREEN");}
    else if (red>green&&red>blue&&green>blue&& red>average&&green>average&&blue<average)
      {Serial.println("YELLOW");}
    else 
      {Serial.println("none");}     
  }
  */
  float tcsRead(int rgb )
  {   
    tcs.getRawData(&r, &g, &b, &c); 
     averag = (r+g+b)/3;
     red = r/averag;
     green = g/averag;
     blue = b/averag;
     
     if(rgb == 0)
      {return red;}
    else if(rgb == 1)
      {return green;}
    else if(rgb == 2)
      {return blue;}
    //Serial.println("hello");
 
  }

#endif
