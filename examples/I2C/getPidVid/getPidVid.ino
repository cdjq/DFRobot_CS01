#include "DFRobot_GS01.h"


#define DEVICE_ID  0x72 

DFRobot_GS01_I2C cs01(DEVICE_ID);

void setup(){
  
    cs01.begin(&Wire);
    Serial.begin(115200);
    Serial.println(cs01.getGs01Pid());
    Serial.println(cs01.getGs01Vid());
}



void loop(){



   Serial.println(cs01.getFaceNumber());
   delay(1500);
}