void niti(int t, int f, String in,String out)
{

  if( in == "L")
  {
     fline(30,30,1.6,650,'c','s',80,"a5",30);
     servoL(t,f);
      if( out == "F")
        {
       
       
         Motor(-30,1);delay(180);
         do{Motor(30,-30);}while(adc_B(5) > adc_center_B(5));
         Motor(-30,30);delay(90);
         Motor(0,0);delay(30);        
         fline(0,0,0.95,50,'c','s',80,"a5",20);
         servo(7,80);delay(100);
        }
      else
        {
         do{Motor(-30,-30);}while(adc_B(0) > adc_center_B(0));
         Motor(30,30);delay(10);Motor(0,0);delay(30);
         Motor(30,-30);delay(80);
         do{Motor(30,-30);}while(adc_B(7) > adc_center_B(7));
         Motor(-30,30);delay(90);
         Motor(0,0);delay(30);
         fline(0,0,0.95,50,'c','s',80,"a5",20);
         do{Motor(30,-30);}while(adc_F(7) > adc_center_F(7)-250);
         do{Motor(30,-30);}while(adc_F(4) > adc_center_F(4));
         Motor(-30,30);delay(20);
         Motor(0,0);delay(30);
         servo(7,80);delay(100);
        }
       
  }
  else
  {
     servoR(t,f);
      if( out == "F")
        {
       
        }
      else
        {
         
        }
  }
}
