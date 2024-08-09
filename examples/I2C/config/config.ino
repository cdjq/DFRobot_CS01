#include "DFRobot_GS01.h"


#define DEVICE_ID  0x72 

DFRobot_GS01_I2C cs01(DEVICE_ID);

void setup(){
  
    cs01.begin(&Wire);
    Serial.begin(115200);
    cs01.configUart(eBaud_115200,UART_CFG_PARITY_NONE,UART_CFG_STOP_BITS_2);
	cs01.setDeviceAddr(0x72);
}




void loop()
{

}