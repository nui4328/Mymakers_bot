void borihan(int t, int f, String in,String out)
{
  FS(40);
  if( in == "L")
  {
     servoL(t,f);
      if( out == "F")
        {
          Motor(-30,-30);delay(150);
          Motor(30,30);delay(10);
          Motor(0,0);delay(30);
          do{Motor(30,-30);}while(adc_B(3) > adc_center_B(3)); 
          Motor(-20,20);delay(10);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
          fline(0,0,0.95,10,'c','s',80, "a5",20);
        }
      else
        {
          Motor(-30,-30);delay(170);
          Motor(30,30);delay(10);
          do{Motor(-30,30);}while(adc_F(0) > adc_center_F(0)-250 );
          do{Motor(-30,30);}while(adc_F(3) > adc_center_F(3)-250);
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
          Motor(-30,-30);delay(120);
          Motor(30,30);delay(10);
          do{Motor(-30,30);}while(adc_B(4) > adc_center_B(4)); 
          Motor(20,-20);delay(10);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
          fline(0,0,0.95,10,'c','s',80, "a5",20);
        }
      else
        {
          Motor(-30,-30);delay(150);
          Motor(30,30);delay(10); 
          Motor(0,0);delay(30);
          do{Motor(30,-30);}while(adc_F(7) > adc_center_F(7)-250 );
          do{Motor(30,-30);}while(adc_F(4) > adc_center_F(4));
          Motor(-20,20);delay(20);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
        }
  }
}
