#ifndef _tcs_my_H_
#define _tcs_my_H_
#include "sensor_f_my.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TCS34725.h>

// Initialize the TCS34725 color sensor
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

 
 uint16_t color = 0;
 float averag;
 float red ;
 float green ;
 float blue ;
 float average ;
void setup_tcs() {
  Serial.begin(9600);
  Wire.begin();

  // Check if the TCS34725 sensor is connected and working
  if (!tcs.begin()) {
    Serial.println("No TCS34725 color sensor found.");
    while (1);
  }
}


float tcsRead(int rgb )
  {   
    uint16_t r, g, b, c;
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
