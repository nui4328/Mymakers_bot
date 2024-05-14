#ifndef _huskylensRead_H_
#define _huskylensRead_H_
#include <HUSKYLENS.h>

HUSKYLENS huskylens;
//Srial1(PA10, PA9); // RX, TX
//HUSKYLENS green line >> Pin PA10; blue line >> Pin PA9

int obj(int val) 
  {
    int cal_obj = 0;
    int servo_limit = 90;
    Serial1.begin(9600);
    while (!huskylens.begin(Serial1))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
    while(1)
      {
        if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
        else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
        else if(!huskylens.available()) 
          {
            Serial.println(F("No block or arrow appears on the screen!")) ;
            Motor(0 , 0);
            //servo(7,80 );
          }
        else
        {

            while (huskylens.available())
            {
                HUSKYLENSResult result = huskylens.read();
                if (result.command == COMMAND_RETURN_BLOCK)
                  {
                    //Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID); 
                    if (val == 0)
                      {
                        return result.xCenter;
                      }
                    else if (val == 1)
                      {
                        return result.yCenter;
                      }
                    else if (val == 2)
                      {
                        return result.width;
                      }
                    else if (val == 3)
                      {
                        return result.height;
                      }
                    else if (val == 4)
                      {
                        return result.ID;
                      }
                  }
                  
          }    
        }
      }
  }

#endif
