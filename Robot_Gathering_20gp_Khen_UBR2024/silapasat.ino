void silapasat(int t, int f, String in,String out)
{
  FS(30);
  if( in == "L")
  {
     servoL(t,f);
      if( out == "F")
        {
          Motor(-1,-30);delay(200);
          do{Motor(30,-30);}while(adc_F(4) > adc_center_F(4)); 
          Motor(-20,20);delay(10);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
          fline(30,30,0.75,0,'c','s',80, "a5",20);
        }
      else
        {
          do{Motor(-30,-30);}while(adc_B(0) > adc_center_B(0)); 
          Motor(20,20);delay(10);
          Motor(0,0);delay(30);    
          do{Motor(-30,30);}while(adc_B(0) > adc_center_B(0)-250 );
          do{Motor(-30,30);}while(adc_F(4) > adc_center_F(4)-250);
          Motor(20,-20);delay(20);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
        
        }
  }
  else
  {
     servoR(t,f);
      if( out == "F")
        {
          Motor(-30,-30);delay(80);
          Motor(30,30);delay(10);
          do{Motor(-30,30);}while(adc_B(4) > adc_center_B(4)); 
          Motor(20,-20);delay(10);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
          fline(0,0,0.75,10,'c','s',80, "a5",20);
        }
      else
        {
         do{Motor(-30,-30);}while(adc_B(7) > adc_center_B(7)); 
          Motor(20,20);delay(10);
          Motor(0,0);delay(30);    
          do{Motor(30,-30);}while(adc_B(7) > adc_center_B(7)-250 );
          do{Motor(30,-30);}while(adc_F(3) > adc_center_F(3));
          Motor(-20,20);delay(20);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
        }
  }
}
