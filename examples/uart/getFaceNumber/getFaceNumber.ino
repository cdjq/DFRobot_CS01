#include "DFRobot_GS01.h"


#define DEVICE_ID  0x72 

DFRobot_GS01_UART cs01(&Serial1,DEVICE_ID);

void setup(){
  
    
	Serial1.begin(115200);
    Serial.begin(115200);
    Serial.println(cs01.getGs01Pid());
    Serial.println(cs01.getGs01Vid());
	
	
	cs01.configUart(eBaud_115200,UART_CFG_PARITY_NONE,UART_CFG_STOP_BITS_2);
}



void loop(){



   Serial.println(cs01.getFaceNumber());
   delay(1500);
}