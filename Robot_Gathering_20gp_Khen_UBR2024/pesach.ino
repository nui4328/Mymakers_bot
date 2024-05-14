void pesach(int t, int f, String in,String out)
{
  if( in == "L")
  {
     CS(30);
     servoL(t,f);
      if( out == "F")
        {
        Motor(-30,-30);delay(120);
        Motor(30,30);delay(10);
        do{Motor(30,-30);}while(adc_B(3) > adc_center_B(3)); 
        Motor(-20,20);delay(20);
        Motor(0,0);delay(30);
       
        }
      else
        {
        Motor(-30,-1);delay(200);
        do{Motor(-30,30);}while(adc_F(0) > adc_center_F(0)-250); 
        do{Motor(-30,30);}while(adc_F(3) > adc_center_F(3));
        Motor(20,-20);delay(20);
        Motor(0,0);delay(30);
       
        }
  }
  else
  {
     FS(40);
     servoR(t,f);
      if( out == "F")
        {
           Motor(-30,-30);delay(80);
          Motor(30,30);delay(10);
            //--------------หมุนไปด้านหน้า--------------
            Motor(-30,30);delay(100);
            do{Motor(-30,30);}while(adc_B(0) > adc_center_B(0)); 
            do{Motor(-30,30);}while(adc_B(3) > adc_center_B(3)); 
            Motor(20,-20);delay(20);
        }
      else
        {
        do{Motor(30,-30);}while(adc_F(7) < adc_center_F(7));
        do{Motor(30,-30);}while(adc_F(7) > adc_center_F(7)); 
        do{Motor(30,-30);}while(adc_F(4) > adc_center_F(4)); 
        Motor(-20,20);delay(20);
        }
         Motor(-20,20);delay(20);
         Motor(0,0);delay(30);
         
  }
  servo(7,80);delay(100);
}
