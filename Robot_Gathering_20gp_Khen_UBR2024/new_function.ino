void FR(int p)
{
fline(p,p,0.9,0,'f','r',70, "a5", 30); //เซนเซอร์หน้าเเตะเลี้ยวขวา
}
void FL(int p)
{
fline(p,p,0.9,0,'f','l',70, "a2", 30); //เซนเซอร์หน้าเเตะเลี้ยวซ้าย
}
void FP(int p)
{
fline(p,p,1.25,0,'f','p',80, "a5", 1); //ผ่านเซนเซอร์หน้า
}
void FS(int p)
{
fline(p,p,0.5,0,'f','s',80, "a5",45); //หยุดทีเซนเซอร์หน้า
}
void FT(int p,int t)
{
fline(p,p,0.7,t,'n','s',80,"a5",40);//วิ่งตามเวลา  
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void CR(int p)
{
//fline(p,p,0.9,0,'c','r',60, "a5", 25); //เซนเซอร์กลางเเตะเลี้ยวขวา
  fline(p,p,1.15,0,'c','s',60, "a5", 45);
 
  do{Motor(40,-40);}while(adc_F(7) > adc_center_F(7)-250); 
  do{Motor(40,-40);}while(adc_F(5) > adc_center_F(5)-250); 
  Motor(-50,50);delay(50);
  Motor(0,0);delay(20);
}
void CL(int p)
{
//fline(p,p,0.9,0,'c','l',60, "a2", 25); //เซนเซอร์กลางเเตะเลี้ยวซ้าย
  fline(p,p,1.15,0,'c','s',60, "a2", 45);

  do{Motor(-40,40);}while(adc_F(0) > adc_center_F(0)-250); 
  do{Motor(-40,40);}while(adc_F(2) > adc_center_F(2)-250); 
  Motor(50,-50);delay(50);
  Motor(0,0);delay(20);
}
void CP(int p)
{
fline(p,p,0.9,0,'c','p',80, "a5", 1); //ผ่านเซนเซอร์กลาง
}
void CS(int p)
{
fline(p,p,0.75,0,'c','s',80, "a5", 25); //หยุดทีเซนเซอร์กลาง
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void BR(int p)
{
//bline(p,p,0.5,0,'c','r',50, "a2", 20); //ถอยหลังเลี้ยวขวา

 bline(p,p,0.75,0,'c','s',80, "a5", 30);
    do{Motor(40,-40);}while(adc_F(7) > adc_center_F(7)-250); 
  do{Motor(40,-40);}while(adc_F(5) > adc_center_F(5)-250); 
  Motor(-50,50);delay(50);
  Motor(0,0);delay(20);
}
void BL(int p)
{
//bline(p,p,0.5,0,'c','l',50, "a5", 20); //ถอยหลังเลี้ยวซ้าย
  bline(p,p,0.75,0,'c','s',80, "a5", 30);
  
 do{Motor(-40,40);}while(adc_F(0) > adc_center_F(0)-250); 
  do{Motor(-40,40);}while(adc_F(2) > adc_center_F(2)-250); 
  Motor(50,-50);delay(50);
  Motor(0,0);delay(20);
}
void BP(int p)
{
bline(p,p,0.75,0,'c','p',80, "a5", 1); //ถอยหลังเซนเซอร์กลางผ่านเส้น
}
void BS(int p)
{
bline(p,p,0.75,0,'c','s',80, "a5", 30); //ถอยหลังหยุดทีเซนเซอร์กลาง
}
//////////////////////////////////////////////////
void UT_R()
{
//fline(0,0,0.5,50,'n','r',50, "a4", 45); //utr
  Motor(40,-40);delay(250);
  do{Motor(40,-40);}while(adc_F(7) > adc_center_F(7)-250); 
  do{Motor(40,-40);}while(adc_F(5) > adc_center_F(5)-250); 
  Motor(-50,50);delay(50);
  Motor(0,0);delay(20);
}
void UT_L()
{
//fline(0,0,0.5,50,'n','l',50, "a2",45); //ulr
  Motor(-40,40);delay(250);
  do{Motor(-40,40);}while(adc_F(0) > adc_center_F(0)-250); 
  do{Motor(-40,40);}while(adc_F(2) > adc_center_F(2)-250); 
  Motor(50,-50);delay(50);
  Motor(0,0);delay(20);
}
void CR_B(int p)
{
fline(p,p,0.5,0,'c','r',50, "b3", 40); //เซนเซอร์กลางเเตะเลี้ยวขวา
}
void CL_B(int p)
{
fline(p,p,0.5,0,'c','l',50, "b4", 35); //เซนเซอร์กลางเเตะเลี้ยวซ้าย
}
void FW(int pl,int pr,int t)
{
Motor(pl,pr);delay(t);Motor(0,0);delay(100);
}
/////////////////////////////
void AO()
{
  Motor(0,0);delay(100);
}
void pass_curve_L()
{
  fline_curve(30,30, 2.5, "a0", 'p', 20);delay(200);/////เส้นอยู่ทางซ้าย
}
void pass_curve_R()
{
  fline_curve(30,30, 2.5, "a7", 'p', 20);delay(200);/////เส้นอยู่ทางขวา    
}
void stop_curve()
{
  fline_curve(30,30, 2.5, "a7", 's', 20);
}
//----------------------------------------------------------------------------------------
void fline_curve(int spl, int spr, float kp, String a07, char sp, int en)
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

            PID_output = (kp * errors) + (0.00015 * integral) + (0.2* derivative);
            Motor(spl - PID_output, spr + PID_output);

            
            if( adc_F(0) < adc_center_F(0) || adc_F(7) < adc_center_F(7) )
              {
                break;
              }                              
          }
       ///////////////////////////////////////////////////////   
       if(a07 == "a0")
          {
              if(sp == 'p')
                  {
                    do{ Motor(spl, spr/2); }while( adc_F(0) < adc_center_F(0) );
                    delay(30);
                  }
               else
                  {
                    Motor(-spl, -spr); delay(en);
                    Motor(0, 0);  delay(10);
                  }               
          }
        else
          {
              if(sp == 'p')
                  {
                    do{ Motor(spl/2, spr); }while( adc_F(7) < adc_center_F(7) );
                    delay(30);
                  }
               else
                  {
                    Motor(-spl, -spr); delay(en);
                    Motor(0, 0);  delay(10);
                  }  
          }      
    }
 void small_mission_3yak_L()   //  เข้าทางซ้ายของกล่อง
  {
    
    fline(0,0,0.5,10,'n','r',50, "b4", 30);
    do{Motor(30, 30);}while(adc_B(0) > adc_center_B(0));
    Motor(-30, -30); delay(20);
    do{Motor(30, -30);}while(adc_F(7) > adc_center_F(7));
    do{Motor(30, -30);}while(adc_F(0) > adc_center_F(0));
    fline(0,0,0.5,10,'n','r',30, "a3", 10);  delay(100); 
    
    do{Motor(-30, -30);}while(adc_F(0) > adc_center_F(0));
    Motor(30, 30);delay(20);
    Motor(0, 0);delay(20);
    servo_kang() ;delay(200);
    
    while(1)
      { 
            int error_L = map(adc_F(2), EEPROM.read(10), EEPROM.read(2), 0, 20 );
            int error_R = map(adc_F(5), EEPROM.read(13), EEPROM.read(5), 0, 20 );
                
            errors = error_R - error_L;                 
            integral = integral + errors ;      
            derivative = (errors - previous_errors) ;
            previous_errors = errors;            
            integral = integral + errors ;      

            PID_output = (0.8 * errors) + (0.00015 * integral) + (0.2* derivative);
            Motor(80 - PID_output, 80 + PID_output); 
            if( analogRead(PA0) <= adc_center_PA(0) || analogRead(PA3) <= adc_center_PA(3)) 
              {
                break;   
              } 
       }
    
    Motor(-70, -70); delay(10);
    Motor(0, 0); delay(30);
     
  }   

  void small_mission_3yak_R()   //  เข้าทางขวาของกล่อง
  {
    
    fline(0,0,0.5,10,'c','l',50, "b3", 30);
    do{Motor(30, 30);}while(adc_B(7) > adc_center_B(7));
    Motor(-30, -30); delay(20);
    do{Motor(-30, 30);}while(adc_F(0) > adc_center_F(0));
    do{Motor(-30, 30);}while(adc_F(7) > adc_center_F(7));
    fline(0,0,0.5,10,'n','l',30, "a3", 10);  delay(100); 
    
    do{Motor(-30, -30);}while(adc_F(0) > adc_center_F(0));
    Motor(30, 30);delay(20);
    Motor(0, 0);delay(20);
    servo_kang() ;delay(200);
    
    while(1)
      { 
            int error_L = map(adc_F(2), EEPROM.read(10), EEPROM.read(2), 0, 20 );
            int error_R = map(adc_F(5), EEPROM.read(13), EEPROM.read(5), 0, 20 );
                
            errors = error_R - error_L;                 
            integral = integral + errors ;      
            derivative = (errors - previous_errors) ;
            previous_errors = errors;            
            integral = integral + errors ;      

            PID_output = (0.8 * errors) + (0.00015 * integral) + (0.2* derivative);
            Motor(80 - PID_output, 80 + PID_output); 
            if( analogRead(PA0) <= adc_center_PA(0) || analogRead(PA3) <= adc_center_PA(3)) 
              {
                break;   
              } 
       }
    
    Motor(-70, -70); delay(10);
    Motor(0, 0); delay(30);
     
  }
void TL_noline()
{
   //Motor(-30,30);delay(10);
   do{ Motor(-40,40); } 
   while( analogRead(PA3) > adc_center_PA(3)  );  
   Motor(20,-20);  delay(10);
   Motor(0,0);  delay(10);
  
  }
void TR_noline()
{
  
   do{ Motor(75,-75); } 
   while( analogRead(PA0) > adc_center_PA(0)  );  
   Motor(-10,10);  delay(10);
   Motor(0,0);  delay(10);
  
}






   

















  
