#include "DFRobot_GS01.h"


#define DEVICE_ID  0x72 

DFRobot_GS01_UART cs01(&Serial1,DEVICE_ID);

void setup(){
  
	Serial1.begin(9600);
    Serial.begin(115200);
    Serial.println(cs01.getGs01Pid());
    Serial.println(cs01.getGs01Vid());
}



void loop(){



   Serial.println(cs01.getFaceNumber());
   delay(1500);
}