#ifndef _start_my_H_
#define _start_my_H_
#include "sensor_f_my.h"

String robo_bord ;
void select_robot(String robo) 
{  
  robo_bord = robo;
}
/*
void BZ(int tim) 
{  
  pinMode(PA14,OUTPUT);
  digitalWrite(PA14,HIGH); 
  delay(tim);
  digitalWrite(PA14,LOW); 
  delay(50); 
}
*/
void BZ(int tim) 
{  
  pinMode(PA2,OUTPUT);
  digitalWrite(PA2,HIGH); 
  delay(tim);
  digitalWrite(PA2,LOW); 
  delay(50); 
}

void LD(int tim) 
{  
  pinMode(PC13,OUTPUT);
  digitalWrite(PC13,LOW); 
  delay(tim);
  digitalWrite(PC13,HIGH); 
  delay(tim); 
  digitalWrite(PC13,LOW); 
  delay(tim); 
}
void sw()
{
  pinMode(PA15,INPUT);
  while(digitalRead(PA15)==1){}
  BZ(100);
  delay(500); 
}
void read_sen()
  {
        Serial.print(Position());
        Serial.print(" " );
        Serial.print(error_F()); 
        Serial.print(" " );
        Serial.print( adc_F(0));
        Serial.print(" " );
        Serial.print( adc_F(1));
        Serial.print(" " );
        Serial.print(adc_F(2));
        Serial.print(" " );
        Serial.print(adc_F(3));
        Serial.print(" " );
        Serial.print(adc_F(4));
        Serial.print(" " );
        Serial.print(adc_F(5));
        Serial.print(" " );
        Serial.print(adc_F(6));
        Serial.print(" " );
        Serial.print(adc_F(7));
        Serial.print("        " );


        Serial.print(PositionB());
        Serial.print(" " );
        Serial.print(error_B());
        Serial.print(" " );
        Serial.print( adc_B(0));
        Serial.print(" " );
        Serial.print( adc_B(1));
        Serial.print(" " );
        Serial.print(adc_B(2));
        Serial.print(" " );
        Serial.print(adc_B(3));
        Serial.print(" " );
        Serial.print(adc_B(4));
        Serial.print(" " );
        Serial.print(adc_B(5));
        Serial.print(" " );
        Serial.print(adc_B(6));
        Serial.print(" " );
        Serial.print(adc_B(7));
        Serial.print("    " ); 
        Serial.print("  " );
        Serial.print(analogRead(PA0) );
        Serial.print(" " );
        Serial.print(analogRead(PA3));
        Serial.print(" " );
        Serial.print(adc_center_PA(0));
        Serial.print(" " );
        Serial.println(adc_center_PA(3));
      
  }
void startROBOT()
 { 
    pinMode(PB4,INPUT);
    pinMode(PB5,INPUT);
    BZ(50);
    LD(50);
    BZ(50);
    LD(50);
     while(1)
      {     
        if (robo_bord == "mymakers_2sensor")
          {  

                 read_sen();
                if (digitalRead(PB5)==0)
                  {                                                  
                    delay(200);
                    BZ(50);delay(500);
                    add_sensor_F();                          
                    delay(1000);BZ(50);delay(30);BZ(50); 
                    delay(500);BZ(500);  BZ(50);delay(30);BZ(50);      

                                                                               
                  } 

                if (digitalRead(PB4)==0)
                  {                                                  
                    delay(200);
                    BZ(50);delay(500);
                    add_sensor_B();                          
                    delay(1000);BZ(50);delay(30);BZ(50); 
                    delay(500);BZ(500);  BZ(50);delay(30);BZ(50);                                                                  
                  }

                if (digitalRead(PA15)==0)
                  {
                    break;            
                  } 

          }
         else if (robo_bord == "mymakers_1sensor")
          {  

                read_sen();
                if (digitalRead(PB5)==0)
                  {                                                  
                    delay(200);
                    BZ(50);delay(500);
                    add_sensor_F();                          
                    delay(1000);BZ(50);delay(30);BZ(50); 
                    delay(500);BZ(500);  BZ(50);delay(30);BZ(50);                                                                  
                  } 
                if (digitalRead(PA15)==0)
                  {
                    break;            
                  } 

             
          }
        else 
          {
                 read_sen();
                if (digitalRead(PA15)==0)
                  {
                    break;            
                  } 
 
          }
       
      }
     BZ(500);delay(500);
  }


#endif
