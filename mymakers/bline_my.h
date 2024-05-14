#ifndef _bline_my_H_
#define _bline_my_H_

#include "sensor_f_my.h"
#include "fline_my.h"
void bline (int spl ,int spr, float kp, int tim, char nfc, char splr, int power, char sensor[], int endt)     //////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
  {

    int sensor_f = atoi(&sensor[1]); 
    if (tim > 1)
      {
        lasts_time=millis();
        while(millis()-lasts_time <tim)
          {
            PID_output = (kp * error_B()) + (0.00015 * integral) + (kd_b* derivative);
            Motor(-(spl + PID_output), -(spr - PID_output));                       
          }
      }
    else
      {
        while(1)
          {                   
            PID_output = (kp * error_B()) + (0.00015 * integral) + (kd_b* derivative);
            Motor(-(spl + PID_output), -(spr - PID_output)); 
            if( (adc_B(0) < adc_center_B(0)) && (adc_B(1) < adc_center_B(1)) && (adc_B(6) < adc_center_B(6)) && (adc_B(7) < adc_center_B(7))
                || (adc_B(0) < adc_center_B(0)) && (adc_B(3) < adc_center_B(3)) 
                || (adc_B(0) < adc_center_B(0)) && (adc_B(4) < adc_center_B(4)) 
                || (adc_B(7) < adc_center_B(7)) &&  (adc_B(4) < adc_center_B(4)) 
                || (adc_B(7) < adc_center_B(7)) &&  (adc_B(3) < adc_center_B(3)) 
                || (adc_B(0) < adc_center_B(0)) && (adc_B(3) > adc_center_B(3)) 
                || (adc_B(7) < adc_center_B(7)) &&  (adc_B(4) > adc_center_B(4)) 
                //|| (adc_B(0) < adc_center_B(0)) && (adc_B(1) < adc_center_B(1)) && (adc_B(2) < adc_center_B(2))
               //|| (adc_B(7) < adc_center_B(7)) && (adc_B(6) < adc_center_B(6)) && (adc_B(5) < adc_center_B(5))
               ) 
              {
                break;
              }                         
          }
      }
    if (nfc == 'n')
      {
        if (splr == 'p')
          {
            if(spl > 1)
              {
                while(1)
                  {                   
                    PID_output = (0.3 * error_B()) + (0.00015 * integral) + (kd_b* derivative);
                    Motor(-(spl + PID_output), -(spr - PID_output));  
                    if( (adc_B(0) < adc_center_B(0)) && (adc_B(1) < adc_center_B(1)) && (adc_B(6) < adc_center_B(6)) && (adc_B(7) < adc_center_B(7))
                        || (adc_B(0) < adc_center_B(0)) && (adc_B(1) < adc_center_B(1)) && (adc_B(2) < adc_center_B(2))
                        || (adc_B(7) < adc_center_B(7)) && (adc_B(6) < adc_center_B(6)) && (adc_B(5) < adc_center_B(5)) ) 
                      {
                        break;
                      }                         
                  }
              }
            else
              {
                while(1)
                  {                   
                    PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(-(slmotor + PID_output), -(srmotor - PID_output)); 
                    if( (adc_B(0) < adc_center_B(0)) && (adc_B(1) < adc_center_B(1)) && (adc_B(6) < adc_center_B(6)) && (adc_B(7) < adc_center_B(7))
                        || (adc_B(0) < adc_center_B(0)) && (adc_B(1) < adc_center_B(1)) && (adc_B(2) < adc_center_B(2))
                        || (adc_B(7) < adc_center_B(7)) && (adc_B(6) < adc_center_B(6)) && (adc_B(5) < adc_center_B(5)) ) 
                      {
                        break;
                      }                         
                  }
              }
          }
      }
    else if (nfc == 'f')
      {
        if (tim > 1 and spl == 0)
          {
            while(1)
              {                   
                PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(-(slmotor + PID_output), -(srmotor - PID_output));    
                if( analogRead(PA0) < adc_center_PA(0)
                    || analogRead(PA3) < adc_center_PA(3)
                     )
                  {
                    break;
                  }                         
              }
          }
        else{}
      }
    else if (nfc == 'c')
      {
        if( splr == 'p')
          {
            if (spl == 0)
              {
                Motor(-slmotor, -srmotor);
                delay(10);
                while(1)
                  {                     
                    PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(-(slmotor + PID_output), -(srmotor - PID_output)); 
                    if( analogRead(PA0) < adc_center_PA(0)
                        || analogRead(PA3) < adc_center_PA(3) 
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
                    PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(-(spl + PID_output), -(spr - PID_output)); 
                    if( adc_B(1) > adc_center_B(1) && adc_B(6) > adc_center_B(6) )  
                      {
                        break;
                      }                                                               
                  }
              }
          }
        else
          {
            while(1)
              {                     
                PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(-(slmotor + PID_output), -(srmotor - PID_output));
 
                if( analogRead(PA0) < adc_center_PA(0)
                    || analogRead(PA3) < adc_center_PA(3) 
                    )
                  {
                    break;
                  }  
                                     
              }
          }          
      }
    //else{}
  
    if (splr == 's')
      {
        Motor(slmotor+10 ,srmotor+10) ;
        delay(endt);
        Motor(0,0);
        delay(5);
      }

    else if (splr == 'p')
      {        
        while(1)
          {  
            PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
            Motor(-(spl + PID_output), -(spr - PID_output)); 
            if( adc_B(1) > adc_center_B(1) && adc_B(6) > adc_center_B(6) )  
              {
                break;
              }                                                                
          }                  
        delay(20); 
      }
    else if (splr == 'l')
      {
        
        if ((nfc == 'f') || (nfc == 'n' && spl > 0 && tim == 0))
          {
            while(1)
              {  
                 Motor(-slmotor,-srmotor); delay(1); 
                if( adc_B(1) > adc_center_B(1) && adc_B(6) > adc_center_B(6) )  
                  {
                      break;
                  }                                                               
              }
            delay(10);

            for ( int i = 0; i < sensor_f; i++ )
              {
                 do{ Motor(-((flmr*power)/100), -((flml*power)/100)); } while( adc_F(i) > adc_center_F(i) ); delay(1);
             
              }                            
          }
        else
          { 
            if (spl > 0 )
              {
                Motor(slmotor ,srmotor) ; delay(break_fc);
                Motor(0,0); delay(5);
              }
            else{}
           
            if (sensor[0] == 'a')
              {
                if (sensor_f > 5)
                  {
                    for ( int i = 0; i < sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i+5) > adc_center_F(i+5)); delay(1);
                      } 
                  }
                else
                  {
                    for ( int i = 0; i < sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i) > adc_center_F(i)); delay(1);
                      } 
                  }
              }
            else
              {
                for ( int i = 0; i < sensor_f; i++ )
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
            Motor(0,0);delay(5);                
          }
      
      }
     else if (splr == 'r')
      {
        if (nfc == 'f')
          {
             while(1)
              {  
                Motor(-slmotor,-srmotor); delay(1); 
                if( adc_B(1) > adc_center_B(1) && adc_B(6) > adc_center_B(6) )  
                  {
                      break;
                  }                                                               
              }
            delay(10);
            for ( int i = 7; i > sensor_f; i -- )
              {
                do{ Motor(-((frmr*power)/100), -((frml*power)/100));  } while (adc_B(i) > adc_center_B(i));delay(1);  
              }
          }
        else
          {
            if (spl > 0 )
              {
                Motor(slmotor ,srmotor) ; delay(break_fc);
                Motor(0,0); delay(5);
              }
            else{}
            if (sensor[0] == 'a')
              {
                if (sensor_f < 2)
                  {
                    for ( int i = 7; i > sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i-5) > adc_center_F(i-5)); delay(2);
                      }
                  }
                else
                  {
                    for ( int i = 7; i > sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i) > adc_center_F(i)); delay(1);
                      }
                  }
              }
            else
              {
                for ( int i = 7; i > sensor_f; i -- )
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
            Motor(0,0);delay(5);
          } 
      }
    else{}

  }

void bline_white (int spl ,int spr, float kp, int tim, char nfc, char splr, int power, char sensor[], int endt)     //////เดินหน้าแบบตั่งค่า  ความเร็ว  KP  KI  KD และเวลาเอง
  {

    int sensor_f = atoi(&sensor[1]); 
    if (tim > 1)
      {
        lasts_time=millis();
        while(millis()-lasts_time <tim)
          {
            PID_output = (kp * error_B()) + (0.00015 * integral) + (kd_b* derivative);
            Motor(-(spl - PID_output), -(spr + PID_output));                       
          }
      }
    else
      {
        while(1)
          {                   
            PID_output = (kp * error_B()) + (0.00015 * integral) + (kd_b* derivative);
            Motor(-(spl - PID_output), -(spr + PID_output));  
            if( (adc_B(0) > adc_center_B(0)) && (adc_B(1) > adc_center_B(1)) && (adc_B(6) > adc_center_B(6)) && (adc_B(7) > adc_center_B(7))
                || (adc_B(0) > adc_center_B(0)) && (adc_B(3) > adc_center_B(3)) 
                || (adc_B(0) > adc_center_B(0)) && (adc_B(4) > adc_center_B(4)) 
                || (adc_B(7) > adc_center_B(7)) &&  (adc_B(4) > adc_center_B(4)) 
                || (adc_B(7) > adc_center_B(7)) &&  (adc_B(3) > adc_center_B(3)) 
               ) 
              {
                break;
              }                         
          }
      }
    if (nfc == 'n')
      {
        if (splr == 'p')
          {
            if(spl > 1)
              {
                while(1)
                  {                   
                    PID_output = (0.3 * error_B()) + (0.00015 * integral) + (kd_b* derivative);
                    Motor(-(spl - PID_output), -(spr + PID_output));  
                    if( (adc_B(0) > adc_center_B(0)) && (adc_B(1) > adc_center_B(1)) && (adc_B(6) > adc_center_B(6)) && (adc_B(7) > adc_center_B(7))
                        || (adc_B(0) > adc_center_B(0)) && (adc_B(1) > adc_center_B(1)) && (adc_B(2) > adc_center_B(2))
                        || (adc_B(7) > adc_center_B(7)) && (adc_B(6) > adc_center_B(6)) && (adc_B(5) > adc_center_B(5)) ) 
                      {
                        break;
                      }                         
                  }
              }
            else
              {
                while(1)
                  {                   
                    PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(-(slmotor - PID_output), -(srmotor + PID_output)); 
                    if( (adc_B(0) > adc_center_B(0)) && (adc_B(1) > adc_center_B(1)) && (adc_B(6) > adc_center_B(6)) && (adc_B(7) > adc_center_B(7))
                        || (adc_B(0) > adc_center_B(0)) && (adc_B(1) > adc_center_B(1)) && (adc_B(2) > adc_center_B(2))
                        || (adc_B(7) > adc_center_B(7)) && (adc_B(6) > adc_center_B(6)) && (adc_B(5) > adc_center_B(5)) ) 
                      {
                        break;
                      }                         
                  }
              }
          }
      }
    else if (nfc == 'f')
      {
        if (tim > 1 and spl == 0)
          {
            while(1)
              {                   
                PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(-(slmotor - PID_output), -(srmotor + PID_output));    
                if( analogRead(PA0) > adc_center_PA(0)
                    || analogRead(PA3) > adc_center_PA(3)
                     )
                  {
                    break;
                  }                         
              }
          }
        else{}
      }
    else if (nfc == 'c')
      {
        if( splr == 'p')
          {
            if (spl == 0)
              {
                Motor(-slmotor, -srmotor);
                delay(10);
                while(1)
                  {                     
                    PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(-(slmotor - PID_output), -(srmotor + PID_output)); 
                    if( analogRead(PA0) > adc_center_PA(0)
                        || analogRead(PA3) > adc_center_PA(3) 
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
                    PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                    Motor(-(spl - PID_output), -(spr + PID_output)); 
                    if( adc_B(1) < adc_center_B(1) && adc_B(6) < adc_center_B(6) )  
                      {
                        break;
                      }                                                               
                  }
              }
          }
        else
          {
            while(1)
              {                     
                PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
                Motor(-(slmotor - PID_output), -(srmotor + PID_output));
 
                if( analogRead(PA0) > adc_center_PA(0)
                    || analogRead(PA3) > adc_center_PA(3) 
                    )
                  {
                    break;
                  }  
                                     
              }
          }          
      }
    //else{}
  
    if (splr == 's')
      {
        Motor(slmotor+10 ,srmotor+10) ;
        delay(endt);
        Motor(0,0);
        delay(5);
      }

    else if (splr == 'p')
      {        
        while(1)
          {  
            PID_output = (kp_slow * error_B()) + (0.00015 * integral) + (ki_slow* derivative);
            Motor(-(spl - PID_output), -(spr + PID_output)); 
            if( adc_B(1) < adc_center_B(1) && adc_B(6) < adc_center_B(6) )  
              {
                break;
              }                                                                
          }                  
        delay(20); 
      }
    else if (splr == 'l')
      {
        
        if ((nfc == 'f') || (nfc == 'n' && spl > 0 && tim == 0))
          {
            while(1)
              {  
                 Motor(-slmotor,-srmotor); delay(1); 
                if( adc_B(1) < adc_center_B(1) && adc_B(6) < adc_center_B(6) )  
                  {
                      break;
                  }                                                               
              }
            delay(10);

            for ( int i = 0; i < sensor_f; i++ )
              {
                 do{ Motor(-((flmr*power)/100), -((flml*power)/100)); } while( adc_F(i) < adc_center_F(i) ); delay(1);
             
              }                            
          }
        else
          { 
            if (spl > 0 )
              {
                Motor(slmotor ,srmotor) ; delay(break_fc);
                Motor(0,0); delay(5);
              }
            else{}
           
            if (sensor[0] == 'a')
              {
                if (sensor_f > 5)
                  {
                    for ( int i = 0; i < sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i+5) < adc_center_F(i+5)); delay(1);
                      } 
                  }
                else
                  {
                    for ( int i = 0; i < sensor_f; i++ )
                      {
                        do{ Motor((clml*power)/100,(clmr*power)/100); } while (adc_F(i) < adc_center_F(i)); delay(1);
                      } 
                  }
              }
            else
              {
                for ( int i = 0; i < sensor_f; i++ )
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
            Motor(0,0);delay(5);                
          }
      
      }
     else if (splr == 'r')
      {
        if (nfc == 'f')
          {
             while(1)
              {  
                Motor(-slmotor,-srmotor); delay(1); 
                if( adc_B(1) > adc_center_B(1) && adc_B(6) < adc_center_B(6) )  
                  {
                      break;
                  }                                                               
              }
            delay(10);
            for ( int i = 7; i > sensor_f; i -- )
              {
                do{ Motor(-((frmr*power)/100), -((frml*power)/100));  } while (adc_B(i) < adc_center_B(i));delay(1);  
              }
          }
        else
          {
            if (spl > 0 )
              {
                Motor(slmotor ,srmotor) ; delay(break_fc);
                Motor(0,0); delay(5);
              }
            else{}
            if (sensor[0] == 'a')
              {
                if (sensor_f < 2)
                  {
                    for ( int i = 7; i > sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i-5) < adc_center_F(i-5)); delay(2);
                      }
                  }
                else
                  {
                    for ( int i = 7; i > sensor_f; i -- )
                      {
                        do{ Motor((crml*power)/100,(crmr*power)/100);   } while (adc_F(i) < adc_center_F(i)); delay(1);
                      }
                  }
              }
            else
              {
                for ( int i = 7; i > sensor_f; i -- )
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
            Motor(0,0);delay(5);
          } 
      }
    else{}

  }

#endif