
#include <mymakers.h>

#include "TCS34725.h"
unsigned long lasts_time_servo=millis();
//---------------------ประกาศตัวแปร--------------------------------------- 
  int kang = 50; 
  int kang_n = 80 ;//ใส่ค่า servo ให้ครบ
  int up   = 150;
  int keep = 180;
  int down = 55;
  int keepL=45;
  int keepR=135;
  int kangL=150;
  int kangR=30;
  int pos ;
  int a = 0;
//------------------------------------------------------------
void setup()
{
    Serial.begin(9600);
  //setup_tfs();
//  seleft_stm32("stm32_512");
 // seleft_stm32("stm32_128"); 
 select_robot("mymakers_2sensor");        // เลือกบอร์ด "mymakers_bord" = บอร์ด shield,  
  //seleft_robot("mymakers_1sensor");        // "mymakers_1sensor" = หุ่นยนต์เดินตามเส้นใช้ แบบเซนเซอร์แผง 1 เซนเซอร์หน้า
  //seleft_robot("mymakers_bord");        // "mymakers_2sensor" = หุ่นยนต์เดินตามเส้นใช้ แบบเซนเซอร์แผง / เซนเซอร์หน้า- หลัง
  motor_cal(15, 15);                  //  มอเตอร์ สำหรับคาริเบรท
  to_set_motor_LR(100, 100);          //ตั้งค่ามอเตอร์ให้หุ่นยนต์วิ่งตรง
  to_slow_motor(15, 15);           // ตั้งค่า ความเร็วมอเตอร์เวลาเข้าแยก
  to_turn_center_l(-80, 80 );   // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวซ้ายแบบ fenter
  to_turn_center_r(80, -80 );   // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวขาวแบบ fenter
  to_turn_front_l(-15, 80);     // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวซ้ายแบบ เซนเซอร์หน้า  เดินหน้า
  to_turn_front_r(80, -15);     // ตั้งค่ามอเตอร์หมุนซ้ายขวา ตอนเลี้ยวขวาแบบ เซนเซอร์หน้า  เดินหน้า
  to_speed_turn_fl(60, 30, 30);  // ค่าพุ่งตัวออกหลังจากการเลี้ยว มีผลต่อตัวแปรสุดท้ายของคำสั่งเลี้ยว ถ้าเป็น 0
  to_speed_turn_fr(30, 60, 30);  // ค่าพุ่งตัวออกหลังจากการเลี้ยว มีผลต่อตัวแปรสุดท้ายของคำสั่งเลี้ยว ถ้าเป็น 0
  
  to_brake_fc(5, 15);            // ตั้งค่าในการหยุดมอเตอร์ก่อนหมุนซ้ายขวา to_brake_ff(...f..., ....f...); 
  to_delay_f(30);                 // ระยะทางในการข้ามเส้นเวลาหมุนตัวแบบ f

  kp_sl(2.15, 2.15);  // kp และ ki ในฟังก์ เดินตามเส้นแบบช้า
  kd_fw(8.5);
  kd_bw(0.9);
//  sv_set();
//keep_big();
servo(6,80);
servo(0,80);
  //====================================== 
    startROBOT();  //รอปุ่มกด
    ///============================================
   
    
CR(30);
CP(30);
CL(30);    
CS(30);
CP(30);
CP(30);
CL(30);
CP(30);
CR(30);
CP(30);
CR(30);
CP(30);
CP(30);
CR(30);
CR(30);
CP(30);
CS(40);
CR(30);
CP(30);
CL(30);
CS(30);
    
    
    
    sw();
    box1();
//    box2();
//    box3();
//    box4();
//    box5();
//    box_end();
//    sw();
//===================================================
 niti(150, 160,"L","F");sw();
 niti(150, 160,"L","B");sw();
 niti(150, 160,"R","F");sw();
 niti(150, 160,"R","B");sw();
 
//kaset(110, 160,"L","F");sw();
//
//kaset(110, 160,"L","B");sw();
kaset(300, 160,"R","F");sw();

kaset(300, 160,"R","B");sw();

CS(40);pesach(110, 160,"L","F");sw();
CS(40);pesach(110, 160,"L","B");sw();
pesach(230, 180,"R","F");sw();
pesach(230, 180,"R","B");sw();



silapayuk(120, 160,"L","F");sw();
silapayuk(120, 160,"L","B");sw();
silapayuk(160, 180,"R","F");sw();
silapayuk(160, 180,"R","B");sw();

patsat(140, 160,"L","F");sw();
patsat(140, 160,"L","B");sw();
patsat(160, 180,"R","F");sw();
patsat(170, 190,"R","B");sw();

rathasat(140, 130,"L","F");sw();
rathasat(140, 130,"L","B");sw();
rathasat(150, 130,"R","F");sw();
rathasat(150, 130,"R","B");sw();

nures(120, 130,"L","F");sw();
nures(120, 130,"L","B");sw();
nures(150, 130,"R","F");sw();
nures(150, 130,"R","B");sw();

science(120, 100,"L","F");sw();
science(120, 100,"L","B");sw();
science(150, 100,"R","F");sw();
science(150, 100,"R","B");sw();

vidwa(120, 100,"L","F");sw();
vidwa(120, 100,"L","B");sw();
vidwa(130, 100,"R","F");sw();
vidwa(130, 100,"R","B");sw();

    

//=======================================================

}

void  loop()
{
Serial.println(analogRead(PA0));delay(20);
 
 }
