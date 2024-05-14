#ifndef _coltrol_motor_my_H_
#define _coltrol_motor_my_H_


//#define PWML  PB8 //   motor L
#define IN1L  PA1  // #define IN1L  PA13  // 
#define IN2L  PA5  //
#define PWMR  PA8  //   motor R
#define IN1R  PB10  //  
#define IN2R  PB11  //
/*
#define PWML  PA8 //   motor L
#define IN1L  PB10  // #define IN1L  PA13  // 
#define IN2L  PB11  //
#define PWMR  PB8  //   motor R
#define IN1R  PA1  //  
#define IN2R  PA5  //
*/

int mt_l, mt_r;
String stm32;
void to_set_motor_LR(int ML, int MR)
    {
      mt_l = ML;
      mt_r = MR;
    }

void select_stm32(String stm) 
	{  
  	  stm32 = stm;
	}

void Motor(int spl,int spr)    
   {    
      int sl = 0;
      int sr = 0;
      
      sl = map(spl, -100, 100, -255, 255);
      sr = map(spr, -100, 100, -255, 255);
      
      if(stm32 == "stm32_128")
         {
            #define PWML PB8
            pinMode(PWML,OUTPUT);
            pinMode(IN1L,OUTPUT);
            pinMode(IN2L,OUTPUT);
            
            pinMode(PWMR,OUTPUT); 
            pinMode(IN1R,OUTPUT);
            pinMode(IN2R,OUTPUT);
                  if(sr>255)
                  sr = 255;
                  else if(sr<-255)
                  sr = -255;
               
                  if(sl>255)
                  sl = 255;
                  else if(sl<-255)
                  sl = -255;
               
                  if(sl>0)
                     {
                        digitalWrite(IN1L,HIGH);
                        digitalWrite(IN2L,LOW);     
                        analogWrite(PWML,sl);
                     }
                  else if(sl<0)
                     {    
                        digitalWrite(IN1L,LOW);
                        digitalWrite(IN2L,HIGH);
                        analogWrite(PWML,-sl);
                     }
                  else
                     {        
                        digitalWrite(IN1L,LOW);
                        digitalWrite(IN2L,LOW);
                        analogWrite(PWML,255);
                     }  
            
                  if(sr>0)
                     {
                        digitalWrite(IN1R,HIGH);
                        digitalWrite(IN2R,LOW);
                        analogWrite(PWMR,sr);
                     }
                  else if(sr<0)
                     {    
                        digitalWrite(IN1R,LOW);
                        digitalWrite(IN2R,HIGH);
                        analogWrite(PWMR,-sr);
                     }
                  else
                     {        
                        digitalWrite(IN1R,LOW);
                        digitalWrite(IN2R,LOW);
                        analogWrite(PWMR,255);
                     }    
         }
      else  
         {
                  #define PWML PB9
                  pinMode(PWML,OUTPUT);
                  pinMode(IN1L,OUTPUT);
                  pinMode(IN2L,OUTPUT);
                  
                  pinMode(PWMR,OUTPUT); 
                  pinMode(IN1R,OUTPUT);
                  pinMode(IN2R,OUTPUT);
                  if(sr>255)
                  sr = 255;
                  else if(sr<-255)
                  sr = -255;
               
                  if(sl>255)
                  sl = 255;
                  else if(sl<-255)
                  sl = -255;
               
                  if(sl>0)
                  {
                        digitalWrite(IN1L,HIGH);
                        digitalWrite(IN2L,LOW);     
                        analogWrite(PWML,sl);
                     }
                  else if(sl<0)
                     {    
                        digitalWrite(IN1L,LOW);
                        digitalWrite(IN2L,HIGH);
                        analogWrite(PWML,-sl);
                     }
                  else
                     {        
                        digitalWrite(IN1L,LOW);
                        digitalWrite(IN2L,LOW);
                        analogWrite(PWML,255);
                     }  
            
                  if(sr>0)
                     {
                        digitalWrite(IN1R,HIGH);
                        digitalWrite(IN2R,LOW);
                        analogWrite(PWMR,sr);
                     }
                  else if(sr<0)
                     {    
                        digitalWrite(IN1R,LOW);
                        digitalWrite(IN2R,HIGH);
                        analogWrite(PWMR,-sr);
                     }
                  else
                     {        
                        digitalWrite(IN1R,LOW);
                        digitalWrite(IN2R,LOW);
                        analogWrite(PWMR,255);
                     }  
         }
      
      
    }


#endif
