

float PID_outputs=0,errorss=0,integrals=0,derivatives=0;

//unsigned long lasts_time_servo=millis();


void servoL(int t,int p)
{
 do{Motor(-30,30);}while(adc_B(6) > adc_center_B(6)); 
  do{Motor(-30,30);}while(adc_B(6) < adc_center_B(6)); 
  Motor(-30,30);delay(t);
  Motor(30,-30);delay(40);
  Motor(0,0);delay(20);
  Motor(30,30);delay(p);
  Motor(-30,-30);delay(10);
  Motor(0,0);delay(30);
  for(int i = 80; i > 10 ; i-- )
      {
        servo(7, i);
        delay(2);
      }
   delay(100);
 
//  Motor(-30,-30);delay(p -30);
//  Motor(30,30);delay(10);
//  do{Motor(30,-30);}while(adc_B(3) > adc_center_B(3)); 
//  Motor(-20,20);delay(20);
//   Motor(0,0);delay(30);
//  servo(6,80);delay(100);
}
void servoR(int t,int p)
{

  do{Motor(30,-30);}while(adc_B(1) > adc_center_B(1)); 
  do{Motor(30,-30);}while(adc_B(1) < adc_center_B(1)); 
  Motor(30,-30);delay(t);
  Motor(-30,30);delay(40);
  Motor(0,0);delay(20);
  Motor(30,30);delay(p);
  Motor(-20,-20);delay(10);
  Motor(0,0);delay(30);
  for(int i = 80; i > 10 ; i-- )
      {
        servo(7, i);
        delay(2);
      }
   delay(100);
 
//  Motor(-30,-30);delay(p -30);
//  Motor(30,30);delay(10);
//  do{Motor(-30,30);}while(adc_B(4) > adc_center_B(4)); 
//  Motor(30,-30);delay(30);
//   Motor(0,0);delay(30);
//  servo(6,80);delay(100);
}

void Out_R()
{
        Motor(-40, -40); delay(100); 
          Motor(40, 40); delay(30); 
         Motor(0, 0); delay(30); 
  Motor(30, -30); delay(150);
    do{Motor(30, -30);}while(adc_F(4) > adc_center_F(4)-250);  
    Motor(-30, 30); delay(20);  
    Motor(0, 0); delay(20);  
  servo(6,80);
  
  }
  void Out_L()
{
        Motor(-40, -40); delay(100); 
         Motor(40, 40); delay(30); 
         Motor(0, 0); delay(30); 
  Motor(-30, 30); delay(150);
    do{Motor(-30, 30);}while(adc_F(3) > adc_center_F(3)-250);  
    Motor(30, -30); delay(20);  
    Motor(0, 0); delay(20);  
  servo(6,80);
  
  }

void servo_kang_noy()
{
servo(7,kangL -100);
servo(0,kangR +100);
}
void Open_SL(){
  servo(7,kangL);
  servo(0,keepR);
}
void Open_SR(){
  servo(7,keepL);
  servo(0,kangR);
}
void keep_up(){
  servo(7,keepL - 20);
  servo(0,keepR + 20);
  delay(500);
}
void yoon(){
  
}
void Get_big()
{
  servo_down();
  FS(20);
  keep_big();
}
void Get_small()
{
  servo_down();
  FS(20);
  keep_small();
}




void   sv_set() // เซตเซอร์โว
{ 
  servo_up(); //กาง// ค่าองศาเซอร์โวตอนเปิดบอร์ด
  servo_kang();  //ยก
  
}


void servo_up()
{
   for(int i = down; i < up ; i++ )
      {
        servo(6, i);
        delay(3);
      }
}
void servo_down()
{
    for(int i = up; i > down ; i-- )
      {
        servo(6, i);
        delay(3);
      }
}
void servo_kang()
{
servo(7,kangL);
servo(0,kangR);
}

void keep_big()
{
 servo(7,keepL);
 servo(0,keepR);
 a = 0 ;
}
 void keep_small()
 {
  servo(7,keepL-15);
  servo(0,keepR+15); 
  a = 1;
 }
 void Put_L(int m)
     {
      Motor(-1,30);
      delay(m);
      Motor(1,-30);
      delay(40);
      Motor(0,0);
      delay(20);
      if(a == 1)
        {
          servo_up();
          delay(300);
          servo_kang();
          Motor(1,-30);
          delay(m);
          Motor(-1,30);
          delay(30);
          Motor(0,0);
          delay(20);   
         }
       else
       {     
          servo_kang_noy();delay(300);
          servo_up();
          delay(300);
          servo_kang();
          Motor(1,-30);
          delay(m);
          Motor(-1,30);
          delay(30);
          Motor(0,0);
          delay(20);   
       }
     }
void Put_R(int m)
     {
      Motor(30,-1);
      delay(m);
      Motor(-30,1);
      delay(40);
      Motor(0,0);
      delay(20); 
       if(a == 1)
        {
        servo_up();
      delay(300);
      servo_kang();
      Motor(-30,1);
      delay(m);
      Motor(30,-1);
      delay(30);
      Motor(0,0);
      delay(20);     
        }
        else
        {
      servo_kang_noy();delay(300);
      servo_up();
      delay(300);
      servo_kang();
      Motor(-30,1);
      delay(m);
      Motor(30,-1);
      delay(30);
      Motor(0,0);
      delay(20);
        }   
     }

void servo_open()
{
servo(7,kangL -70);
servo(0,kangR +70);
}
void  servo_up_open()
  {
    servo(7,kangL); //ซ้าย 
    servo(0,kangR); //ขวา 
    servo(6,up );  //ยก
  }

void servo_down_open()   // 
  {
    servo(7,kangL); //ซ้าย 
    servo(0,kangR); //ขวา 
    servo(6,down );  //ลง
  }

void  servo_up_close()
  {
    servo(7,keepL-20);  //keep small
    servo(0,keepR+20);
    servo(6,up );  //ยก
  }

void  servo_down_close()
  {
    servo(7,keepL-20);  //keep small
    servo(0,keepR+20);
    servo(6,down );  //กลาง
  }

void servo_big()
  {
  servo(7,keepL);
  servo(0,keepR);    
  servo(6,down );  //ลง  
  }


void mission(int SPL ,int SPR, float KP,int TIM,String box) 
    {         
          Motor(0,0);delay(15);
          servo(7,kangL - 25); //ซ้าย
          servo(0,kangR + 25); //ขวา
          //servo(7,servo_down );  //กลาง
          slow_servo();
          delay(100);

           lasts_time_servo=millis();
                 while(millis()-lasts_time_servo<TIM)
                       {
                         PID_output = (KP * error_F()) + (0.00015 * integral) + (12* derivative);
                         Motor(SPL - PID_output,SPR + PID_output); 
                        /*
                         if(analogRead(PB1)>2760)
                            {
                              break;
                            }
                         */                                        
                        }
           Motor(-20,-20);delay(15);

          if (box == "big")
            {
               servo_big(); 
               a = 0 ;       
            }
          else
            {
                servo_down_close();
                a = 1;
            }
          Motor(0,0);delay(15);
                  
    }
  void slow_servo()
  {
    for(int i = up; i > down ; i-- )
      {
        servo(6, i);
        delay(4);
      }
  }

void servo_poy_r()////สบัดหน้าR
{
servo(7,kangL-100);
servo(0,kangR-180);
do{ Motor(70,-70); } 
   while(adc_F(0) > adc_center_F(0));  
   Motor(0,0);  delay(10);

do{ Motor(-40,40); } 
   while(adc_F(4) > adc_center_F(4));  
   Motor(40,-40);  delay(20);
   Motor(0,0);  delay(10);
  sv_set();

}
void servo_poy_l()//สบัดหน้าL
{
servo(7,kangL+110);
servo(1,kangR+85);

do{ Motor(-40,40); } 
   while(adc_F(7) > adc_center_F(7));  
   Motor(0,0);  delay(10);

do{ Motor(40,-40); } 
   while(adc_F(3) > adc_center_F(3));  
   Motor(-40,40);  delay(20);
   Motor(0,0);  delay(10);
  sv_set();
   
}
void servo_kang_r(int L,int R)  //_____________  กำหนดkeeb______
{
  servo_down();
servo(7,L);//(7,L-100);
servo(0,R); //(0,kangR-50);

}

void servo_kang_l(int L,int R )   //_____________  กำหนดkeeb______
{
 servo_down();
servo(7,L);
servo(0,R);

}



/* void poy_big_L()
{
   
       for(pos = keepL; pos < kangL ; pos += 1) 
      {
            servo(7,pos);
            delay(1); 
       }
       for(pos = keepR; pos < 180; pos += 1) 
      {
            servo(0,pos); 
            delay(4); 
       }
       for(pos = 180; pos >=150; pos-=1)
      {
            servo(0,pos);  
           delay(1); 
      } 
    
}

void poy_big_R()
{
     
       for(pos = 135; pos >= kangR ; pos -= 1) 
       
      {
            servo(1,pos); 
            delay(1); 
       }
       for(pos = 50; pos>=0; pos-=1)
      {
            servo(0,pos);
           delay(4); 
      }
       for(pos = 0; pos < 50; pos += 1) 
      {
            servo(0,pos); 
            delay(1); 
       }
       
}*/
