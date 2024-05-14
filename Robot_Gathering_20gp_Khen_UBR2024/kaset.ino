void kaset(int t, int f, String in,String out)
{
  
  if( in == "L")
  {
     FS(50);
     servoL(t,f);
      if( out == "F")
        {
        do{Motor(-30,-30);}while(adc_B(7) > adc_center_B(7));
        do{Motor(-30,-30);}while(adc_B(7) < adc_center_B(7));
        Motor(30,30);delay(10);Motor(0,0);delay(30);
        do{Motor(30,-30);}while(adc_B(2) > adc_center_B(2));
        Motor(-30,30);delay(20);
        Motor(0,0);delay(30);
        servo(7,80);delay(100);
        }
      else
        {
          Motor(-30,-30);delay(120);
          Motor(20,20);delay(10);
          Motor(0,0);delay(30);    
          do{Motor(-30,30);}while(adc_F(0) > adc_center_F(0)-250 );
          do{Motor(-30,30);}while(adc_F(3) > adc_center_F(3));
          Motor(20,-20);delay(20);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
        
        }
  }
  else
  {
     CS(50);
     servoR(t,f);
      if( out == "F")
        {
          Motor(-30,-30);delay(120);
          Motor(20,20);delay(10);
          Motor(0,0);delay(30);    
          do{Motor(-30,30);}while(adc_F(0) > adc_center_F(0)-250 );
          do{Motor(-30,30);}while(adc_F(3) > adc_center_F(3));
          Motor(20,-20);delay(20);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
       
        }
      else
        {
          Motor(-30,-30);delay(150);
          Motor(20,20);delay(10);
          Motor(0,0);delay(30);   
          do{Motor(30,-30);}while(adc_B(7) > adc_center_B(7));
          do{Motor(30,-30);}while(adc_F(4) > adc_center_F(4));
          Motor(-20,20);delay(20);
          Motor(0,0);delay(30);
          servo(7,80);delay(100);
        }
  }
}
