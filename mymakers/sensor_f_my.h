
#ifndef _sensor_f_my_H_
#define _sensor_f_my_H_
#include "coltrol_motor_my.h"
#include <EEPROM.h>
#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;

int i = PB13;  // ขา clk
int j = PB14;  // ขา miso 
int k = PB15; // ขา mosi 
int m = PB12; // ขา cs 1 ข้างหน้า
int n = PA4; // ขา cs 2  ข้างหลัง
//int o = PC14; // ขา cs 3  กลาง

int sensor_F0[120];
int sensor_F1[120];
int sensor_F2[120];
int sensor_F3[120];
int sensor_F4[120];
int sensor_F5[120];
int sensor_F6[120];
int sensor_F7[120];
int sensor_add_F[8];
int sensor_max[8]; // sensor_max[0] ค่าเซนเซอร์ตัวที่1
int sensor_min[8];

int sensor_PA0[120];
int sensor_PA3[120];
int sensor_max_PA[2];
int sensor_min_PA[2];
/*
int adcRead(int sensor)
    {
      adc.begin(i, k, j, o );    
      return adc.readADC(sensor);
    }
*/
int ml_cal;
int mr_cal;
void motor_cal(int sl, int sr)
   {
      ml_cal = sl;
      mr_cal = sr;
   }
int adc_F(int sensor)
    {
      adc.begin(i, k, j, m );    
      return adc.readADC(sensor);
    }
int adc_center_F(int sensor)
    {
      int center = (EEPROM.read(sensor) + EEPROM.read(sensor+8))/2;  
      return center;
    }

int adc_center_PA(int sensor)
    { 
      int center;
      if(sensor == 0)
         {
            center = (EEPROM.read(16) + EEPROM.read(18))/2; 
         }
      else if(sensor == 3)
         {
            center = (EEPROM.read(17) + EEPROM.read(19))/2; 
         } 
      return center;
    }
   
void add_sensor_F()
	{
      pinMode(PA0,INPUT);
      pinMode(PA3,INPUT);
      pinMode(PB4,INPUT);
      pinMode(PB5,INPUT);
      for (int i = 0; i < 30; i ++)         
         {
            Motor(ml_cal,mr_cal);           
            Serial.println(" ");
            sensor_F0[i] = sensor_add_F[0];
            sensor_F1[i] = sensor_add_F[1];
            sensor_F2[i] = sensor_add_F[2];
            sensor_F3[i] = sensor_add_F[3];
            sensor_F4[i] = sensor_add_F[4];
            sensor_F5[i] = sensor_add_F[5];
            sensor_F6[i] = sensor_add_F[6];
            sensor_F7[i] = sensor_add_F[7];
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
     for (int i = 30; i < 90; i ++)         
         {
            Motor(-ml_cal,-mr_cal);           
            Serial.println(" ");
            sensor_F0[i] = sensor_add_F[0];
            sensor_F1[i] = sensor_add_F[1];
            sensor_F2[i] = sensor_add_F[2];
            sensor_F3[i] = sensor_add_F[3];
            sensor_F4[i] = sensor_add_F[4];
            sensor_F5[i] = sensor_add_F[5];
            sensor_F6[i] = sensor_add_F[6];
            sensor_F7[i] = sensor_add_F[7];
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
      for (int i = 90; i < 150; i ++)         
         {
            Motor(ml_cal,mr_cal);           
            Serial.println(" ");
            sensor_F0[i] = sensor_add_F[0];
            sensor_F1[i] = sensor_add_F[1];
            sensor_F2[i] = sensor_add_F[2];
            sensor_F3[i] = sensor_add_F[3];
            sensor_F4[i] = sensor_add_F[4];
            sensor_F5[i] = sensor_add_F[5];
            sensor_F6[i] = sensor_add_F[6];
            sensor_F7[i] = sensor_add_F[7];
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
       for (int i = 150; i < 220; i ++)         
         {
            Motor(-ml_cal,-mr_cal);          
            Serial.println(" ");
            sensor_F0[i] = sensor_add_F[0];
            sensor_F1[i] = sensor_add_F[1];
            sensor_F2[i] = sensor_add_F[2];
            sensor_F3[i] = sensor_add_F[3];
            sensor_F4[i] = sensor_add_F[4];
            sensor_F5[i] = sensor_add_F[5];
            sensor_F6[i] = sensor_add_F[6];
            sensor_F7[i] = sensor_add_F[7];
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
       for( int i = 7; i >=4 ; i--)
        {
	         do{Motor(15,-15);} while(adc_F(i) >= adc_center_F(i)); delay(1); 
	     }
      //Motor(15,15); delay(200);

      Motor(10,10);delay(10);
      Motor(0,0);
      
      BZ(200);
      BZ(200);
      while(digitalRead(PB5)==1)
         {
            Serial.println(" ");
         }
      BZ(200);
      for (int i = 0; i < 30; i ++)         
         {
            Motor(ml_cal,mr_cal);           
            Serial.println(" ");
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
     for (int i = 30; i < 90; i ++)         
         {
            Motor(-ml_cal,-mr_cal);           
            Serial.println(" ");
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
      for (int i = 90; i < 150; i ++)         
         {
            Motor(ml_cal,mr_cal);           
            Serial.println(" ");
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
       for (int i = 150; i < 220; i ++)         
         {
            Motor(-ml_cal,-mr_cal);          
            Serial.println(" ");
            sensor_PA0[i] = analogRead(PA0);
            sensor_PA3[i] = analogRead(PA3);
         
         }
       for( int i = 7; i >=4 ; i--)
        {
	         do{Motor(15,-15);} while(adc_F(i) >= adc_center_F(i)); delay(1); 
	     }
      //Motor(15,15); delay(200);

      Motor(10,10);delay(10);
      Motor(0,0);

      ///////////////////////////////////////////////////////////////////////////////////////////////
      int maxVal0 = sensor_F0[0];
      int minVal0 = sensor_F0[0];
      for (int i = 0; i < (sizeof(sensor_F0) / sizeof(sensor_F0[0])); i++) 
         {
            maxVal0 = max(sensor_F0[i],maxVal0);
            minVal0 = min(sensor_F0[i],minVal0);
            sensor_max[0] = maxVal0;
            sensor_min[0] = minVal0;        
         } 
        
      int maxVal1 = sensor_F1[0];
      int minVal1 = sensor_F1[0];
      for (int i = 0; i < (sizeof(sensor_F1) / sizeof(sensor_F1[0])); i++) 
         {
            maxVal1 = max(sensor_F1[i],maxVal1);
            minVal1 = min(sensor_F1[i],minVal1);
            sensor_max[1] = maxVal1;
            sensor_min[1] = minVal1;         
         }
      
      int maxVal2 = sensor_F2[0];
      int minVal2 = sensor_F2[0];
      for (int i = 0; i < (sizeof(sensor_F2) / sizeof(sensor_F2[0])); i++) 
         {
            maxVal2 = max(sensor_F2[i],maxVal2);
            minVal2 = min(sensor_F2[i],minVal2);
            sensor_max[2] = maxVal2;
            sensor_min[2] = minVal2;         
         }
    
      int maxVal3 = sensor_F3[0];
      int minVal3 = sensor_F3[0];
      for (int i = 0; i < (sizeof(sensor_F3) / sizeof(sensor_F3[0])); i++) 
         {
            maxVal3 = max(sensor_F3[i],maxVal3);
            minVal3 = min(sensor_F3[i],minVal3);
            sensor_max[3] = maxVal3;
            sensor_min[3] = minVal3;         
         }
      int maxVal4 = sensor_F4[0];
      int minVal4 = sensor_F4[0];
      for (int i = 0; i < (sizeof(sensor_F4) / sizeof(sensor_F4[0])); i++) 
         {
            maxVal4 = max(sensor_F4[i],maxVal4);
            minVal4 = min(sensor_F4[i],minVal4);
            sensor_max[4] = maxVal4;
            sensor_min[4] = minVal4;         
         }
      int maxVal5 = sensor_F5[0];
      int minVal5 = sensor_F5[0];
      for (int i = 0; i < (sizeof(sensor_F5) / sizeof(sensor_F5[0])); i++) 
         {
            maxVal5 = max(sensor_F5[i],maxVal5);
            minVal5 = min(sensor_F5[i],minVal5);
            sensor_max[5] = maxVal5;
            sensor_min[5] = minVal5;         
         }
      int maxVal6 = sensor_F6[0];
      int minVal6 = sensor_F6[0];
      for (int i = 0; i < (sizeof(sensor_F6) / sizeof(sensor_F6[0])); i++) 
         {
            maxVal6 = max(sensor_F6[i],maxVal6);
            minVal6 = min(sensor_F6[i],minVal6);
            sensor_max[6] = maxVal6;
            sensor_min[6] = minVal6;         
         }
      int maxVal7 = sensor_F7[0];
      int minVal7 = sensor_F7[0];
      for (int i = 0; i < (sizeof(sensor_F7) / sizeof(sensor_F7[0])); i++) 
         {
            maxVal7 = max(sensor_F7[i],maxVal7);
            minVal7 = min(sensor_F7[i],minVal7);
            sensor_max[7] = maxVal7;
            sensor_min[7] = minVal7;         
         }
      for(int i = 0; i < 8; i++)
         {
            EEPROM.write(i, sensor_max[i]);
         }
      for(int i = 0; i < 8; i++)
         {
            EEPROM.write(i+8, sensor_min[i]);
         }
///////////////////////////////////////////////////////////////////////////////////////////////

      int maxValPA0 = sensor_PA0[0];
      int minValPA0 = sensor_PA0[0];
      for (int i = 0; i < (sizeof(sensor_PA0) / sizeof(sensor_PA0[0])); i++) 
         {
            maxValPA0 = max(sensor_PA0[i],maxValPA0);
            minValPA0 = min(sensor_PA0[i],minValPA0);
            sensor_max_PA[0] = maxValPA0;
            sensor_min_PA[0] = minValPA0;         
         }
      int maxValPA3 = sensor_PA3[0];
      int minValPA3 = sensor_PA3[0];
      for (int i = 0; i < (sizeof(sensor_PA3) / sizeof(sensor_PA3[0])); i++) 
         {
            maxValPA3 = max(sensor_PA3[i],maxValPA3);
            minValPA3 = min(sensor_PA3[i],minValPA3);
            sensor_max_PA[1] = maxValPA3;
            sensor_min_PA[1] = minValPA3;         
         }

      for(int i = 0; i < 2; i++)
         {
            EEPROM.write(i+16, sensor_max_PA[i]);
         }
      for(int i = 0; i < 2; i++)
         {
            EEPROM.write(i+18, sensor_min_PA[i]);
         }

   }
////////////////////////////////////////////////////////////////////////////////////

float errors=0,PID_output=0,integral=0, derivative=0,previous_errors=0, present_position=0;  //ตัวแปร pid แบบ position
int numSensor = 8; 
uint16_t sensor_pin_F[] = {0,1,2,3,4,5,6,7}; 
uint16_t state_on_Line = 0;
uint16_t setpoint;
uint32_t _lastPosition;
uint16_t min_sensorF[] = { EEPROM.read(8),EEPROM.read(9), EEPROM.read(10), EEPROM.read(11), EEPROM.read(12), EEPROM.read(13), EEPROM.read(14), EEPROM.read(15) };

int Position()  
   {        
      uint16_t min_sensor_values_F[] = { EEPROM.read(8),EEPROM.read(9), EEPROM.read(10), EEPROM.read(11), EEPROM.read(12), EEPROM.read(13), EEPROM.read(14), EEPROM.read(15) }; //ค่าที่อ่านได้น้อยสุดหรือ สีดำ
      uint16_t max_sensor_values_F[] = { EEPROM.read(0), EEPROM.read(1), EEPROM.read(2), EEPROM.read(3), EEPROM.read(4), EEPROM.read(5), EEPROM.read(6), EEPROM.read(7) } ; //ค่าที่อ่านได้มากสุด สีขาว                
      /*
      for (int i = 0; i < numSensor ; i++ )
         {
            min_sensor_values_F[i] = EEPROM.read(i+8);
            max_sensor_values_F[i] + EEPROM.read(i+8);
         }
      */
      bool onLine = false;
      long avg = 0;
      long sum = 0;
      adc.begin(i, k, j, m );
      for (uint8_t i = 0; i < numSensor ; i++) 
          {              
              long value = map(adc.readADC(sensor_pin_F[i]), min_sensor_values_F[i], max_sensor_values_F[i], 1000, 0);                                                                         // จากนั้นก็เก็บเข้าไปยังตัวแป value

              if (value > 200) 
                 { 
                    onLine = true;
                 }
              if (value > 50)   
                 {
                    avg += (long)value * (i * 1000);  
                    sum += value;                 
                 }
         }
      if (!onLine)        //เมื่อหุ่นยนต์ไม่อยู่หรือไม่เจอเส้นดำ
         {
            if (_lastPosition < (numSensor - 1) * 1000 / 2)  // ถ้าค่าก่อนหน้าที่จะไม่เจอเส้นดำหรือหลุดจะให้ค่านั้นเป็น 0
               {
                  return 3500;
               }
            else                                          //แต่ถ้ามากกว่าแสดงว่าหลุดออกอีกฝั่ง ค่าก็จะเป็น 1000 คุณด้วยจำนวนเซ็นเซอร์
               {
                 return 3500;                  

               }
 /*           if( (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(2) > adc_center_F(2)) && (adc_F(3) > adc_center_F(3)) && (adc_F(4) > adc_center_F(4)) && (adc_F(5) > adc_center_F(5)) && (adc_F(6) > adc_center_F(6)) && (adc_F(7) > adc_center_F(7)))
               {
                  return 3500;
               }
*/
          }
        _lastPosition = avg / sum;        //นำมาหาค่าเฉลี่ย

        return _lastPosition;            //ส่งค่าที่อ่านได้จากการเฉลี่ยแล้วกลับไปยังฟังก์ชั้น readline
    }
int error_F()
    {
      present_position = Position() / ((numSensor - 1) * 10) ;
      setpoint = 50.0;
      errors = setpoint - present_position;                
      integral = integral + errors ;      
      derivative = (errors - previous_errors) ;
      previous_errors = errors;
      return errors;     
                             
    }

///////////////////////////////////////////////////////////////////////////////////////////

int adc_B(int sensor)
    {
      delay(1);
      adc.begin(i, k, j, n );    
      return adc.readADC(sensor);
    }
int adc_center_B(int sensor)
    {
      int center = (EEPROM.read(sensor+20) + EEPROM.read(sensor+28))/2;  
      return center;
    }


int sensor_B0[100];
int sensor_B1[100];
int sensor_B2[100];
int sensor_B3[100];
int sensor_B4[100];
int sensor_B5[100];
int sensor_B6[100];
int sensor_B7[100];
int sensor_add_B[8];
int sensor_maxB[8]; // sensor_maxB[0] ค่าเซนเซอร์ตัวที่1
int sensor_minB[8];

void add_sensor_B()
  {
      for (int i = 0; i < 20; i ++)         
         {
            Motor(-ml_cal,mr_cal);
            for(int i = 0; i < 8; i ++)
               {
                  sensor_add_B[i] = adc_B(i);
                  Serial.print(adc_B(i)); 
                  Serial.print(" ");                  
                  delay(3);
               }            
            Serial.println(" ");
            sensor_B0[i] = sensor_add_B[0];
            sensor_B1[i] = sensor_add_B[1];
            sensor_B2[i] = sensor_add_B[2];
            sensor_B3[i] = sensor_add_B[3];
            sensor_B4[i] = sensor_add_B[4];
            sensor_B5[i] = sensor_add_B[5];
            sensor_B6[i] = sensor_add_B[6];
            sensor_B7[i] = sensor_add_B[7];         
         }
      for (int i = 20; i < 60; i ++)         
         {
            Motor(ml_cal,-mr_cal);
            for(int i = 0; i < 8; i ++)
               {
                  sensor_add_B[i] = adc_B(i);
                  Serial.print(adc_B(i)); 
                  Serial.print(" ");                  
                  delay(3);
               }
            Serial.println(" ");
            sensor_B0[i] = sensor_add_B[0];
            sensor_B1[i] = sensor_add_B[1];
            sensor_B2[i] = sensor_add_B[2];
            sensor_B3[i] = sensor_add_B[3];
            sensor_B4[i] = sensor_add_B[4];
            sensor_B5[i] = sensor_add_B[5];
            sensor_B6[i] = sensor_add_B[6];
            sensor_B7[i] = sensor_add_B[7];      
         }
      for (int i = 60; i < 80; i ++)          
         {
            Motor(-ml_cal,mr_cal);
            for(int i = 0; i < 8; i ++)
               {
                  sensor_add_B[i] = adc_B(i);
                  Serial.print(adc_B(i)); 
                  Serial.print(" ");                  
                  delay(3);
               }
            Serial.println(" ");
            sensor_B0[i] = sensor_add_B[0];
            sensor_B1[i] = sensor_add_B[1];
            sensor_B2[i] = sensor_add_B[2];
            sensor_B3[i] = sensor_add_B[3];
            sensor_B4[i] = sensor_add_B[4];
            sensor_B5[i] = sensor_add_B[5];
            sensor_B6[i] = sensor_add_B[6];
            sensor_B7[i] = sensor_add_B[7];      
         }
      
      Motor(-10,10);delay(10);
      Motor(0,0);
      int maxVal0 = sensor_B0[0];
      int minVal0 = sensor_B0[0];
      for (int i = 0; i < (sizeof(sensor_B0) / sizeof(sensor_B0[0])); i++) 
         {
            maxVal0 = max(sensor_B0[i],maxVal0);
            minVal0 = min(sensor_B0[i],minVal0);
            sensor_maxB[0] = maxVal0;
            sensor_minB[0] = minVal0;        
         } 
        
      int maxVal1 = sensor_B1[0];
      int minVal1 = sensor_B1[0];
      for (int i = 0; i < (sizeof(sensor_B1) / sizeof(sensor_B1[0])); i++) 
         {
            maxVal1 = max(sensor_B1[i],maxVal1);
            minVal1 = min(sensor_B1[i],minVal1);
            sensor_maxB[1] = maxVal1;
            sensor_minB[1] = minVal1;         
         }
      
      int maxVal2 = sensor_B2[0];
      int minVal2 = sensor_B2[0];
      for (int i = 0; i < (sizeof(sensor_B2) / sizeof(sensor_B2[0])); i++) 
         {
            maxVal2 = max(sensor_B2[i],maxVal2);
            minVal2 = min(sensor_B2[i],minVal2);
            sensor_maxB[2] = maxVal2;
            sensor_minB[2] = minVal2;         
         }
    
      int maxVal3 = sensor_B3[0];
      int minVal3 = sensor_B3[0];
      for (int i = 0; i < (sizeof(sensor_B3) / sizeof(sensor_B3[0])); i++) 
         {
            maxVal3 = max(sensor_B3[i],maxVal3);
            minVal3 = min(sensor_B3[i],minVal3);
            sensor_maxB[3] = maxVal3;
            sensor_minB[3] = minVal3;         
         }
      int maxVal4 = sensor_B4[0];
      int minVal4 = sensor_B4[0];
      for (int i = 0; i < (sizeof(sensor_B4) / sizeof(sensor_B4[0])); i++) 
         {
            maxVal4 = max(sensor_B4[i],maxVal4);
            minVal4 = min(sensor_B4[i],minVal4);
            sensor_maxB[4] = maxVal4;
            sensor_minB[4] = minVal4;         
         }
      int maxVal5 = sensor_B5[0];
      int minVal5 = sensor_B5[0];
      for (int i = 0; i < (sizeof(sensor_B5) / sizeof(sensor_B5[0])); i++) 
         {
            maxVal5 = max(sensor_B5[i],maxVal5);
            minVal5 = min(sensor_B5[i],minVal5);
            sensor_maxB[5] = maxVal5;
            sensor_minB[5] = minVal5;         
         }
      int maxVal6 = sensor_B6[0];
      int minVal6 = sensor_B6[0];
      for (int i = 0; i < (sizeof(sensor_B6) / sizeof(sensor_B6[0])); i++) 
         {
            maxVal6 = max(sensor_B6[i],maxVal6);
            minVal6 = min(sensor_B6[i],minVal6);
            sensor_maxB[6] = maxVal6;
            sensor_minB[6] = minVal6;         
         }
      int maxVal7 = sensor_B7[0];
      int minVal7 = sensor_B7[0];
      for (int i = 0; i < (sizeof(sensor_B7) / sizeof(sensor_B7[0])); i++) 
         {
            maxVal7 = max(sensor_B7[i],maxVal7);
            minVal7 = min(sensor_B7[i],minVal7);
            sensor_maxB[7] = maxVal7;
            sensor_minB[7] = minVal7;         
         }
      for(int i = 0; i < 8; i++)
         {
            EEPROM.write(i+20, sensor_maxB[i]);
         }
      for(int i = 0; i < 8; i++)
         {
            EEPROM.write(i+28, sensor_minB[i]);
         }
   }

int PositionB()  
   {  
      uint16_t min_sensor_values_F[] = { EEPROM.read(28),EEPROM.read(29), EEPROM.read(30), EEPROM.read(31), EEPROM.read(32), EEPROM.read(33), EEPROM.read(34), EEPROM.read(35)   }; //ค่าที่อ่านได้น้อยสุดหรือ สีดำ
      uint16_t max_sensor_values_F[] = { EEPROM.read(20), EEPROM.read(21), EEPROM.read(22), EEPROM.read(23), EEPROM.read(24), EEPROM.read(25), EEPROM.read(26), EEPROM.read(27) } ; //ค่าที่อ่านได้มากสุด สีขาว                
      bool onLine = false;
      long avg = 0;
      long sum = 0;
      adc.begin(i, k, j, n );
      for (uint8_t i = 0; i < numSensor ; i++) 
          {              
              long value = map(adc.readADC(sensor_pin_F[i]), min_sensor_values_F[i], max_sensor_values_F[i], 1000, 0);                                                                         // จากนั้นก็เก็บเข้าไปยังตัวแป value

              if (value > 200) 
                 { 
                    onLine = true;
                 }
              if (value > 50)   
                 {
                    avg += (long)value * (i * 1000);  
                    sum += value;                 
                 }
         }
      if (!onLine)        //เมื่อหุ่นยนต์ไม่อยู่หรือไม่เจอเส้นดำ
         {
            if (_lastPosition < (numSensor - 1) * 1000 / 2)  // ถ้าค่าก่อนหน้าที่จะไม่เจอเส้นดำหรือหลุดจะให้ค่านั้นเป็น 0
               {
                  return 3500;
               }
            else                                          //แต่ถ้ามากกว่าแสดงว่าหลุดออกอีกฝั่ง ค่าก็จะเป็น 1000 คุณด้วยจำนวนเซ็นเซอร์
               {
                 return 3500;                   

               }
          }
        _lastPosition = avg / sum;        //นำมาหาค่าเฉลี่ย
        return _lastPosition;            //ส่งค่าที่อ่านได้จากการเฉลี่ยแล้วกลับไปยังฟังก์ชั้น readline
    }
int error_B()
    {
      present_position = PositionB() / ((numSensor - 1) * 10) ;
      setpoint = 50.0;
      errors = setpoint - present_position;                
      integral = integral + errors ;
      previous_errors = errors;
      derivative = (errors - previous_errors) ;
      return errors;                                   
    }


 #endif
