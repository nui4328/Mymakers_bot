
#ifndef _Piya_color_H_
#define _Piya_color_H_

#if ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Wire.h>

#define TCS34725_ADDRESS          (0x29)

#define TCS34725_COMMAND_BIT      (0x80)

#define TCS34725_ENABLE           (0x00)
#define TCS34725_ENABLE_AIEN      (0x10)    
#define TCS34725_ENABLE_WEN       (0x08)    
#define TCS34725_ENABLE_AEN       (0x02)    
#define TCS34725_ENABLE_PON       (0x01)    
#define TCS34725_ATIME            (0x01)    
#define TCS34725_WTIME            (0x03)   
#define TCS34725_WTIME_2_4MS      (0xFF)    
#define TCS34725_WTIME_204MS      (0xAB)   
#define TCS34725_WTIME_614MS      (0x00)   
#define TCS34725_AILTL            (0x04)    
#define TCS34725_AILTH            (0x05)
#define TCS34725_AIHTL            (0x06)   
#define TCS34725_AIHTH            (0x07)
#define TCS34725_PERS             (0x0C)   
#define TCS34725_PERS_NONE        (0b0000)                          
#define TCS34725_PERS_1_CYCLE     (0b0001) 
#define TCS34725_PERS_2_CYCLE     (0b0010) 
#define TCS34725_PERS_3_CYCLE     (0b0011)  
#define TCS34725_PERS_5_CYCLE     (0b0100)  
#define TCS34725_PERS_10_CYCLE    (0b0101)  
#define TCS34725_PERS_15_CYCLE    (0b0110)  
#define TCS34725_PERS_20_CYCLE    (0b0111)  
#define TCS34725_PERS_25_CYCLE    (0b1000)  
#define TCS34725_PERS_30_CYCLE    (0b1001)  
#define TCS34725_PERS_35_CYCLE    (0b1010)  
#define TCS34725_PERS_40_CYCLE    (0b1011)  
#define TCS34725_PERS_45_CYCLE    (0b1100)  
#define TCS34725_PERS_50_CYCLE    (0b1101)  
#define TCS34725_PERS_55_CYCLE    (0b1110)  
#define TCS34725_CONFIG           (0x0D)
#define TCS34725_CONFIG_WLONG     (0x02)   
#define TCS34725_CONTROL          (0x0F)    
#define TCS34725_ID               (0x12)    
#define TCS34725_STATUS           (0x13)
#define TCS34725_STATUS_AINT      (0x10)  
#define TCS34725_STATUS_AVALID    (0x01)  
#define TCS34725_CDATAL           (0x14)   
#define TCS34725_CDATAH           (0x15)
#define TCS34725_RDATAL           (0x16)   
#define TCS34725_RDATAH           (0x17)
#define TCS34725_GDATAL           (0x18)  
#define TCS34725_GDATAH           (0x19)
#define TCS34725_BDATAL           (0x1A)   
#define TCS34725_BDATAH           (0x1B)

typedef enum
{
  TCS34725_INTEGRATIONTIME_2_4MS  = 0xFF,   
  TCS34725_INTEGRATIONTIME_24MS   = 0xF6,  
  TCS34725_INTEGRATIONTIME_50MS   = 0xEB,  
  TCS34725_INTEGRATIONTIME_101MS  = 0xD5,  
  TCS34725_INTEGRATIONTIME_154MS  = 0xC0,  
  TCS34725_INTEGRATIONTIME_700MS  = 0x00   
}
tcs34725IntegrationTime_t;

typedef enum
{
  TCS34725_GAIN_1X                = 0x00,   
  TCS34725_GAIN_4X                = 0x01,  
  TCS34725_GAIN_16X               = 0x02,   
  TCS34725_GAIN_60X               = 0x03    
}
tcs34725Gain_t;

class Piya_color {
 public:
  Piya_color(tcs34725IntegrationTime_t = TCS34725_INTEGRATIONTIME_2_4MS, tcs34725Gain_t = TCS34725_GAIN_1X);
  
  boolean  begin(void);
  void     setIntegrationTime(tcs34725IntegrationTime_t it);
  void     setGain(tcs34725Gain_t gain);
  void     getRawData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);
  uint16_t calculateColorTemperature(uint16_t r, uint16_t g, uint16_t b);
  uint16_t calculateLux(uint16_t r, uint16_t g, uint16_t b);
  void     write8 (uint8_t reg, uint32_t value);
  uint8_t  read8 (uint8_t reg);
  uint16_t read16 (uint8_t reg);
  void setInterrupt(boolean flag);
  void clearInterrupt(void);
  void setIntLimits(uint16_t l, uint16_t h);
  void     enable(void);

 private:
  boolean _tcs34725Initialised;
  tcs34725Gain_t _tcs34725Gain;
  tcs34725IntegrationTime_t _tcs34725IntegrationTime; 
  
  void     disable(void);
};

#endif
