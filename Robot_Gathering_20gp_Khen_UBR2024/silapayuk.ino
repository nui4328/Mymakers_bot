void silapayuk(int t, int f, String in,String out)
{
  if( in == "L")
  {

     fline(60,60,1.75,200,'n','s',60, "a5",30);
     fline(35,35,1.55,500,'f','s',60, "a5",45);
     servoL(t,f);
      if( out == "F")
        {
          Motor(-30,-30);delay(150);
          Motor(30,30);delay(10);
          do{Motor(30,-30);}while(adc_B(3) > adc_center_B(3)); 
          Motor(-30,30);delay(30);
          Motor(0,0);delay(30);
          fline(0,0,0.75,10,'c','s',80, "a5",20);
        }
      else
        {
          Motor(-30,-30);delay(150);
          Motor(20,20);delay(10);
          Motor(0,0);delay(30);
          Motor(-30,30);delay(100);    
          do{Motor(-30,30);}while(adc_F(0) > adc_center_F(0)-250 );
          do{Motor(-30,30);}while(adc_F(3) > adc_center_F(3)-250);
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
          Motor(-30,-30);delay(150);
          Motor(30,30);delay(10);
          Motor(0,0);delay(10);
          Motor(-30,30);delay(100);
           do{Motor(-30,30);}while(adc_B(1) > adc_center_B(1)); 
          do{Motor(-30,30);}while(adc_B(3) > adc_center_B(3)); 
          Motor(20,-20);delay(10);
          Motor(0,0);delay(30);
          fline(0,0,0.75,10,'c','s',80, "a5",20);
        }
      else
        {
          Motor(-30,-30);delay(200);
          Motor(30,30);delay(10);
          Motor(0,0);delay(30);    
          do{Motor(30,-30);}while(adc_B(7) > adc_center_B(7)-250 );
          do{Motor(30,-30);}while(adc_F(3) > adc_center_F(3));
          Motor(-20,20);delay(20);
          Motor(0,0);delay(30);
    
        }
  }
        servo(7,80);delay(100);
}
