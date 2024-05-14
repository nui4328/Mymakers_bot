#ifndef _fline_my_H_
#define _fline_my_H_

#include "sensor_f_my.h"
unsigned long T=0 ;
int SP_BEGIN = 0;
unsigned long MT=0 ;

unsigned long lasts_time=millis();

int clml=0, clmr=0;
int crml=0, crmr=0;
int flml=0, flmr=0;
int frml=0, frmr=0;
int slmotor = 0;
int srmotor = 0;
int blml=0, blmr=0;
int brml=0, brmr=0;


int llmotor=0, lrmotor=0, ldelaymotor=0;
int rlmotor=0, rrmotor=0, rdelaymotor=0;

float kd_f=0, kd_b=0;
float kp_slow = 0, ki_slow = 0;

int break_ff = 5;
int break_fc = 50;
int delay_f = 10;
void kp_sl (float kp_sl, float ki_sl) 
  {
    kp_slow = kp_sl;
    ki_slow = ki_sl;
  }

void turn_speed_fl()
     {
   T=0;
  do
     {
       T++;
        PID_output = (0.2 * error_F()) + (0.00015 * integral) + (2* derivative);
        Motor(llmotor + PID_output,lrmotor - PID_output); 
     }
    while (T<ldelaymotor);
    T=0;   
}

void turn_speed_fr()
     {
   T=0;
  do
     {
       T++;
        PID_output = (0.2 * error_F()) + (0.00015 * integral) + (2* derivative);
        Motor(rlmotor + PID_output,rrmotor - PID_output); 
     }
    while (T<rdelaymotor);
    T=0;   
}

void bturn_speed_fl()
     {
   T=0;
  do
     {
       T++;
        PID_output = (0.2 * error_F()) + (0.00015 * integral) + (2* derivative);
        Motor(-(llmotor + PID_output),-((lrmotor-10) - PID_output)); 
     }
    while (T<ldelaymotor);
    T=0; delay(1);  
}

void bturn_speed_fr()
     {
   T=0;
  do
     {
       T++;
        PID_output = (0.2 * error_F()) + (0.00015 * integral) + (2* derivative);
        Motor(-(rlmotor + PID_output),-((rrmotor-10) - PID_output)); 
     }
    while (T<rdelaymotor);
    T=0; delay(1);
  
}
//////////////////////////////////////////////////
void to_brake_fc(int ff, int fc)
     {       
        break_ff = ff;  
        break_fc = fc;       
     }
void to_delay_f(int ff)
     {       
        delay_f = ff;       
     }
void to_slow_motor(int sl, int sr)
     {       
        slmotor = sl;  
        srmotor = sr;       
     }
void to_turn_center_l(int ml,int mr)
     {       
        clml = ml;
        clmr = mr;
     }
void to_turn_center_r(int ml,int mr)
     {       
        crml = ml;
        crmr = mr;
     }
void to_turn_front_l(int ml,int mr)
     {       
        flml = ml;
        flmr = mr;
     }
void to_turn_front_r(int ml,int mr)
     {       
        frml = ml;
        frmr = mr;
     }
void to_turn_behind_l(int ml,int mr)
     {       
        blml = ml;
        blmr = mr;
     }
void to_turn_behind_r(int ml,int mr)
     {       
        brml = ml;
        brmr = mr;
     }

///////////////////////////////////////////////
void to_speed_turn_fl(int inM, int outM, int delayM )
     {
        llmotor = inM;
        lrmotor = outM;
        ldelaymotor = delayM;
     }
void to_speed_turn_fr(int inM, int outM, int delayM )
     {
        rlmotor = inM;
        rrmotor = outM;
        rdelaymotor = delayM;
     }
//////////////////////////////////////////////////////////

void kd_fw(float kd_fw)
  {
	  kd_f = kd_fw;
  }
void kd_bw(float kd_bw)
  {
	  kd_b = kd_bw;
  }
////////////////////////////////////////////////////////////////////////////////////////////

void fline (int spl ,int spr, float kp, int tim, char nfc, char splr, int power, char sensor[], int endt)     //////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
  {
    int sensor_f = atoi(&sensor[1]); 
    if (tim >= 1)
      {
        lasts_time=millis();
        while(millis()-lasts_time <tim)
          {
            PID_output = (kp * error_F()) + (0.00015 * integral) + (kd_f* derivative);
            Motor(spl - PID_output, spr + PID_output);                       
          }
      }
    else
      {
        while(1)
          {                   

            if( (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(6) < adc_center_F(6)) && (adc_F(7) < adc_center_F(7))
                || (adc_F(1) < adc_center_F(1)) && (adc_F(3) < adc_center_F(3)) && (adc_F(4) < adc_center_F(4))
                || (adc_F(6) < adc_center_F(6)) && (adc_F(3) < adc_center_F(3)) && (adc_F(4) < adc_center_F(4))
                || (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(3) < adc_center_F(3))
                || (adc_F(7) < adc_center_F(7)) && (adc_F(6) < adc_center_F(6)) && (adc_F(4) < adc_center_F(4))
                || (adc_F(3) > adc_center_F(3)) && (adc_F(4) > adc_center_F(4)) && (adc_F(7) < adc_center_F(7))
                || (adc_F(3) > adc_center_F(3)) && (adc_F(4) > adc_center_F(4)) && (adc_F(0) < adc_center_F(0))
               // || (adc_F(2) < adc_center_F(2)) && (adc_F(3) < adc_center_F(3)) && (adc_F(4) < adc_center_F(4)) && (adc_F(5) < adc_center_F(5))
               // || (adc_F(4) < adc_center_F(4)) && (adc_F(5) < adc_center_F(5)) && (adc_F(6) < adc_center_F(6)) && (adc_F(7) < adc_center_F(7))
               // || (adc_F(3) < adc_center_F(3)) && (adc_F(2) < adc_center_F(2)) && (adc_F(1) < adc_center_F(1)) && (adc_F(0) < adc_center_F(0))

                ) 
              {
                break;
              }
            PID_output = (kp * error_F()) + (0.00015 * integral) + (kd_f* derivative);
            Motor(spl - PID_output, spr + PID_output);                         
          }
      }
    if (nfc == 'n')
      {
        if (splr == 'p')
          {
            if(spl >= 1)
              {
                while(1)
                  {                   
                    PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(spl - PID_output, spr + PID_output); 
                    if( (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(6) < adc_center_F(6)) && (adc_F(7) < adc_center_F(7))
                        || (adc_F(3) < adc_center_F(3)) && (adc_F(4) < adc_center_F(4)) && (adc_F(5) < adc_center_F(5))&& (adc_F(6) < adc_center_F(6)) 
                        || (adc_F(1) < adc_center_F(1)) && (adc_F(2) < adc_center_F(2)) && (adc_F(3) < adc_center_F(3))&& (adc_F(4) < adc_center_F(4))
                        || (adc_F(2) < adc_center_F(2)) && (adc_F(3) < adc_center_F(3)) && (adc_F(4) < adc_center_F(4))&& (adc_F(5) < adc_center_F(5))
                        || (adc_F(7) < adc_center_F(7)) && (adc_F(6) < adc_center_F(6)) &&  (adc_F(4) < adc_center_F(4)) && (adc_F(3) < adc_center_F(3)) 
                        || (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(4) < adc_center_F(4)) && (adc_F(3) < adc_center_F(3)) ) 
                      {
                        break;
                      }                         
                  }
              }
            else
              {
                while(1)
                  {                   
                    PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(slmotor - PID_output, srmotor + PID_output); 
                    if( (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(6) < adc_center_F(6)) && (adc_F(7) < adc_center_F(7))
                        || (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(2) < adc_center_F(2))
                        || (adc_F(7) < adc_center_F(7)) && (adc_F(6) < adc_center_F(6)) && (adc_F(5) < adc_center_F(5)) ) 
                      {
                        break;
                      }                         
                  }
              }
          }
        else{}
      }
    else if (nfc == 'f')
      {
        if (tim >= 1)
          {
            while(1)
              {                   
                PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(slmotor - PID_output, srmotor + PID_output);    
                if( (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(6) < adc_center_F(6)) && (adc_F(7) < adc_center_F(7))
                    || (adc_F(0) < adc_center_F(0)) && (adc_F(1) < adc_center_F(1)) && (adc_F(2) < adc_center_F(2))
                    || (adc_F(7) < adc_center_F(7)) && (adc_F(6) < adc_center_F(6)) && (adc_F(5) < adc_center_F(5)) ) 
                  {
                    break;
                  }                         
              }
          }
        else{}
      }
    else if (nfc == 'c')
      {
        if (tim >= 1 and spl == 0)
          {
            while(1)
              { 
                int error_L = map(adc_F(2), EEPROM.read(10), EEPROM.read(2), 0, 20 );
                int error_R = map(adc_F(5), EEPROM.read(13), EEPROM.read(5), 0, 20 );
                
                errors = error_R - error_L;                 
                integral = integral + errors ;      
                derivative = (errors - previous_errors) ;
                previous_errors = errors;            
                integral = integral + errors ;                     
                PID_output = (kp_slow * errors) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(slmotor - PID_output, srmotor + PID_output);    
                if( analogRead(PA0) <= adc_center_PA(0)+70 
                    || analogRead(PA3) <= adc_center_PA(3) +70 
                    )
                  {
                    break;
                  }                          
              }
              
          }
        else{}
       
        if (splr == 'p' ){}
        else
          {
            while(1)
              {                   
                PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(slmotor - PID_output, srmotor + PID_output);  
                if( analogRead(PA0) <= adc_center_PA(0)-100 
                   || analogRead(PA3) <= adc_center_PA(3)-100  
                   )
                  {
                    break;
                  }                         
              }
          }
          
      }
    else{}
   
    if (splr == 's')
      {
        Motor(-(slmotor+10) ,-(srmotor+10)) ;
        delay(endt);
        Motor(0,0);
        delay(5);
      }
    else if (splr == 'p')
      {

        delay(10); 
        if(nfc == 'c')
          {
              while(1)
                {  
                  Motor(spl,spr); delay(1); 
                  if( adc_F(0) > adc_center_F(0) && adc_F(7) > adc_center_F(7) )  
                    {
                      break;
                    }                                                               
                } 
              delay(10);
             while(1)
              {                   
                int error_L = map(adc_F(2), EEPROM.read(10), EEPROM.read(2), 0, 20 );
                int error_R = map(adc_F(5), EEPROM.read(13), EEPROM.read(5), 0, 20 );
                
                errors = error_R - error_L;                 
                integral = integral + errors ;      
                derivative = (errors - previous_errors) ;
                previous_errors = errors;            
                integral = integral + errors ;                     
                PID_output = (kp_slow * errors) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(spl - PID_output, spr + PID_output);  
                if( analogRead(PA0) <= adc_center_PA(0)+70 
                   || analogRead(PA3) <= adc_center_PA(3)+70  
                   )
                  {
                    break;
                  }                         
              }
          }
        else
          {
             while(1)
                {  
                  Motor(spl,spr);  
                  if( adc_F(0) > adc_center_F(0) && adc_F(7) > adc_center_F(7) )  
                    {
                      break;
                    }                                                               
                }                  
              delay(40); 
          }
       
      }
    else if (splr == 'l')
      {
        if ((nfc == 'f') || (nfc == 'n' && spl > 0 && tim == 0))
          {
            while(1)
              {  
                 Motor(slmotor,srmotor); delay(1); 
                if( adc_F(0) >= adc_center_F(0)+100 && adc_F(1) >= adc_center_F(1)+100 )  
                  {
                      break;
                  }                                                               
              }
            delay(delay_f);
            Motor(-slmotor,-srmotor); delay(break_ff); 

            for ( int i = 0; i <= sensor_f; i++ )
              {
                do{ Motor((flml*power)/100,(flmr*power)/100); } while( adc_F(i) > adc_center_F(i)-50 ); delay(1);
                do{ Motor((flml*power)/100,(flmr*power)/100); } while( adc_F(0) < adc_center_F(0)-50 ); 
              } 
                                      
          }
        else
          {
            if(nfc=='n')
              {
                Motor(0,0); delay(1);
              }
            else
              {
                if (spl > 0 )
                  {
                    Motor(-(slmotor+30) ,-(srmotor+30)) ; delay(break_fc+20);
                    //Motor(0,0); delay(5);
                  }
                else
                  {
                    Motor(-slmotor ,-srmotor) ; delay(break_fc);
                    //Motor(0,0); delay(5);
                  }
              }
            if (sensor[0] == 'a')
              {
                if (sensor_f >= 5)
                  {
                    for ( int i = 0; i <= sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i+5) > adc_center_F(i+5)); delay(1);
                      } 
                  }
                else
                  {
                    for ( int i = 0; i <= sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i) > adc_center_F(i)); delay(1);
                      } 
                  }
              }
            else
              {
                for ( int i = 0; i <= sensor_f; i++ )
                  {
                    do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_B(i) > adc_center_B(i)); delay(1);
                  } 
              }           
          }
        if(endt==0)
          {
            turn_speed_fl();
          }
        else
          {
            Motor(-((clml*power)/100),-((clmr*power)/100));delay(endt); 
            Motor(0,0);delay(2);                
          }
      }
    else if (splr == 'r')
      {
        if (nfc == 'f')
          {
             while(1)
              {  
                Motor(slmotor,srmotor); delay(1); 
                if( adc_F(6) >= adc_center_F(6)+100 && adc_F(7) >= adc_center_F(7)+100 )  
                  {
                      break;
                  }                                                               
              }
            delay(delay_f);
            Motor(-slmotor,-srmotor); delay(break_ff); 
            for ( int i = 7; i >= sensor_f; i -- )
              {
                do{ Motor((frml*power)/100,(frmr*power)/100);  } while (adc_F(i) > adc_center_F(i)-50);delay(1);  
                do{ Motor((frml*power)/100,(frmr*power)/100);  } while (adc_F(7) < adc_center_F(7)-50);
              }
            
          }
        else
          {
            if(nfc=='n')
              {
                Motor(0,0); delay(1);
              }
            else
              {
                if (spl > 0 )
                  {
                    Motor(-(slmotor+30) ,-(srmotor+30)) ; delay(break_fc+20);
                    //Motor(0,0); delay(5);
                  }
                else
                  {
                    Motor(-slmotor ,-srmotor) ; delay(break_fc);
                    //Motor(0,0); delay(5);
                  }
              }
            if (sensor[0] == 'a')
              {
                if (sensor_f <= 2)
                  {
                    for ( int i = 7; i >= sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i-5) > adc_center_F(i-5)); delay(1);
                      }
                  }
                else
                  {
                    for ( int i = 7; i >= sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i) > adc_center_F(i)); delay(1);
                      }
                  }
              }
            else
              {
                for ( int i = 7; i >= sensor_f; i -- )
                  {
                    do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_B(i) > adc_center_B(i)); delay(1);
                  }
              }
          }
        if(endt==0)
          {
            turn_speed_fr();
          }
        else
          {
            Motor(-((crml*power)/100),-((crmr*power)/100)); delay(endt);  
            Motor(0,0);delay(2);
          } 
      }
    else{}

  }

void fline_white (int spl ,int spr, float kp, int tim, char nfc, char splr, int power, char sensor[], int endt)     //////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
  {
    int sensor_f = atoi(&sensor[1]); 
    if (tim >= 1)
      {
        lasts_time=millis();
        while(millis()-lasts_time <tim)
          {
            PID_output = (kp * error_F()) + (0.00015 * integral) + (kd_f* derivative);
            Motor(spl + PID_output, spr - PID_output);                       
          }
      }
    else
      {
        while(1)
          {                   

            if( (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(6) > adc_center_F(6)) && (adc_F(7) > adc_center_F(7))
                || (adc_F(1) > adc_center_F(1)) && (adc_F(3) > adc_center_F(3)) && (adc_F(4) > adc_center_F(4))
                || (adc_F(6) > adc_center_F(6)) && (adc_F(3) > adc_center_F(3)) && (adc_F(4) > adc_center_F(4))
                || (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(3) > adc_center_F(3))
                || (adc_F(7) > adc_center_F(7)) && (adc_F(6) > adc_center_F(6)) && (adc_F(4) > adc_center_F(4))

                ) 
              {
                break;
              }
            PID_output = (kp * error_F()) + (0.00015 * integral) + (kd_f* derivative);
            Motor(spl + PID_output, spr - PID_output);                        
          }
      }
    if (nfc == 'n')
      {
        if (splr == 'p')
          {
            if(spl >= 1)
              {
                while(1)
                  {                   
                    PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(spl + PID_output, spr - PID_output); 
                    if( (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(6) > adc_center_F(6)) && (adc_F(7) > adc_center_F(7))
                      || (adc_F(1) > adc_center_F(1)) && (adc_F(3) > adc_center_F(3)) && (adc_F(4) > adc_center_F(4))
                      || (adc_F(6) > adc_center_F(6)) && (adc_F(3) > adc_center_F(3)) && (adc_F(4) > adc_center_F(4))
                      || (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(3) > adc_center_F(3))
                      || (adc_F(7) > adc_center_F(7)) && (adc_F(6) > adc_center_F(6)) && (adc_F(4) > adc_center_F(4))

                      )  
                      {
                        break;
                      }                         
                  }
              }
            else
              {
                while(1)
                  {                   
                    PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(slmotor + PID_output, srmotor - PID_output); 
                    if( (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(6) > adc_center_F(6)) && (adc_F(7) > adc_center_F(7))
                        || (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(2) > adc_center_F(2))
                        || (adc_F(7) > adc_center_F(7)) && (adc_F(6) > adc_center_F(6)) && (adc_F(5) > adc_center_F(5)) ) 
                      {
                        break;
                      }                         
                  }
              }
          }
        else{}
      }
    else if (nfc == 'f')
      {
        if (tim >= 1)
          {
            while(1)
              {                   
                PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(slmotor + PID_output, srmotor - PID_output);    
                if( (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(6) > adc_center_F(6)) && (adc_F(7) > adc_center_F(7))
                    || (adc_F(0) > adc_center_F(0)) && (adc_F(1) > adc_center_F(1)) && (adc_F(2) > adc_center_F(2))
                    || (adc_F(7) > adc_center_F(7)) && (adc_F(6) > adc_center_F(6)) && (adc_F(5) > adc_center_F(5)) ) 
                  {
                    break;
                  }                         
              }
          }
        else{}
      }
    else if (nfc == 'c')
      {
        if (tim >= 1 and spl == 0)
          {
            while(1)
              { 
                int error_L = map(adc_F(2), EEPROM.read(10), EEPROM.read(2), 0, 20 );
                int error_R = map(adc_F(5), EEPROM.read(13), EEPROM.read(5), 0, 20 );
                
                errors = error_R - error_L;                 
                integral = integral + errors ;      
                derivative = (errors - previous_errors) ;
                previous_errors = errors;            
                integral = integral + errors ;                     
                PID_output = (kp_slow * errors) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(slmotor + PID_output, srmotor - PID_output);    
                if( analogRead(PA0) >= adc_center_PA(0)+70 
                    || analogRead(PA3) >= adc_center_PA(3) +70 
                    )
                  {
                    break;
                  }                          
              }
              
          }
        else{}
       
        if (splr == 'p' ){}
        else
          {
            while(1)
              {                   
                PID_output = (kp_slow * error_F()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(slmotor + PID_output, srmotor - PID_output);    
                if( analogRead(PA0) >= adc_center_PA(0)+70 
                    || analogRead(PA3) >= adc_center_PA(3) +70 
                    )
                  {
                    break;
                  }                         
              }
          }
          
      }
    else{}
   
    if (splr == 's')
      {
        Motor(-(slmotor+10) ,-(srmotor+10)) ;
        delay(endt);
        Motor(0,0);
        delay(5);
      }
    else if (splr == 'p')
      {

        delay(10); 
        if(nfc == 'c')
          {
              while(1)
                {  
                  Motor(spl,spr); delay(1); 
                  if( adc_F(0) > adc_center_F(0) && adc_F(7) > adc_center_F(7) )  
                    {
                      break;
                    }                                                               
                } 
              delay(10);
             while(1)
              {                   
                int error_L = map(adc_F(2), EEPROM.read(10), EEPROM.read(2), 0, 20 );
                int error_R = map(adc_F(5), EEPROM.read(13), EEPROM.read(5), 0, 20 );
                
                errors = error_R - error_L;                 
                integral = integral + errors ;      
                derivative = (errors - previous_errors) ;
                previous_errors = errors;            
                integral = integral + errors ;                     
                PID_output = (kp_slow * errors) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(spl + PID_output, spr - PID_output);  
                if( analogRead(PA0) >= adc_center_PA(0)+70 
                   || analogRead(PA3) >= adc_center_PA(3)+70  
                   )
                  {
                    break;
                  }                         
              }
          }
        else
          {
             while(1)
                {  
                  Motor(spl,spr);  
                  if( adc_F(0) < adc_center_F(0) && adc_F(7) < adc_center_F(7) )  
                    {
                      break;
                    }                                                               
                }                  
              delay(40); 
          }
       
      }
    else if (splr == 'l')
      {
        if ((nfc == 'f') || (nfc == 'n' && spl > 0 && tim == 0))
          {
            while(1)
              {  
                 Motor(slmotor,srmotor); delay(1); 
                if( adc_F(0) <= adc_center_F(0)+100 && adc_F(1) <= adc_center_F(1)+100 )  
                  {
                      break;
                  }                                                               
              }
            delay(delay_f);
            Motor(-slmotor,-srmotor); delay(break_ff); 

            for ( int i = 0; i <= sensor_f; i++ )
              {
                do{ Motor((flml*power)/100,(flmr*power)/100); } while( adc_F(i) < adc_center_F(i)-50 ); delay(1);
                do{ Motor((flml*power)/100,(flmr*power)/100); } while( adc_F(0) > adc_center_F(0)-50 ); 
              } 
                                      
          }
        else
          {
            if(nfc=='n')
              {
                Motor(0,0); delay(1);
              }
            else
              {
                if (spl > 0 )
                  {
                    Motor(-(slmotor+30) ,-(srmotor+30)) ; delay(break_fc+20);
                    //Motor(0,0); delay(5);
                  }
                else
                  {
                    Motor(-slmotor ,-srmotor) ; delay(break_fc);
                    //Motor(0,0); delay(5);
                  }
              }
            if (sensor[0] == 'a')
              {
                if (sensor_f >= 5)
                  {
                    for ( int i = 0; i <= sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i+5) < adc_center_F(i+5)); delay(1);
                      } 
                  }
                else
                  {
                    for ( int i = 0; i <= sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i) < adc_center_F(i)); delay(1);
                      } 
                  }
              }
            else
              {
                for ( int i = 0; i <= sensor_f; i++ )
                  {
                    do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_B(i) < adc_center_B(i)); delay(1);
                  } 
              }           
          }
        if(endt==0)
          {
            turn_speed_fl();
          }
        else
          {
            Motor(-((clml*power)/100),-((clmr*power)/100));delay(endt); 
            Motor(0,0);delay(2);                
          }
      }
    else if (splr == 'r')
      {
        if (nfc == 'f')
          {
             while(1)
              {  
                Motor(slmotor,srmotor); delay(1); 
                if( adc_F(6) <= adc_center_F(6)+100 && adc_F(7) <= adc_center_F(7)+100 )  
                  {
                      break;
                  }                                                               
              }
            delay(delay_f);
            Motor(-slmotor,-srmotor); delay(break_ff); 
            for ( int i = 7; i >= sensor_f; i -- )
              {
                do{ Motor((frml*power)/100,(frmr*power)/100);  } while (adc_F(i) < adc_center_F(i)-50);delay(1);  
                do{ Motor((frml*power)/100,(frmr*power)/100);  } while (adc_F(7) > adc_center_F(7)-50);
              }
            
          }
        else
          {
            if(nfc=='n')
              {
                Motor(0,0); delay(1);
              }
            else
              {
                if (spl > 0 )
                  {
                    Motor(-(slmotor+30) ,-(srmotor+30)) ; delay(break_fc+20);
                    //Motor(0,0); delay(5);
                  }
                else
                  {
                    Motor(-slmotor ,-srmotor) ; delay(break_fc);
                    //Motor(0,0); delay(5);
                  }
              }
            if (sensor[0] == 'a')
              {
                if (sensor_f <= 2)
                  {
                    for ( int i = 7; i >= sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i-5) < adc_center_F(i-5)); delay(1);
                      }
                  }
                else
                  {
                    for ( int i = 7; i >= sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i) < adc_center_F(i)); delay(1);
                      }
                  }
              }
            else
              {
                for ( int i = 7; i >= sensor_f; i -- )
                  {
                    do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_B(i) < adc_center_B(i)); delay(1);
                  }
              }
          }
        if(endt==0)
          {
            turn_speed_fr();
          }
        else
          {
            Motor(-((crml*power)/100),-((crmr*power)/100)); delay(endt);  
            Motor(0,0);delay(2);
          } 
      }
    else{}

  }

#endif