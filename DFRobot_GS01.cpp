#include "DFRobot_GS01.h"
DFRobot_GS01::DFRobot_GS01()
{

}
uint16_t DFRobot_GS01::getGs01Pid()
{
    return reaInputdReg(REG_GS01_PID);
}
uint16_t DFRobot_GS01::getGs01Vid()
{
    return reaInputdReg(REG_GS01_VID);
}


uint16_t DFRobot_GS01::getFaceNumber(){
    return reaInputdReg(REG_GS01_FACE_NEMBER);
}	
uint16_t DFRobot_GS01::configUart(eBaudConfig_t baud,eParityConfig_t parity,eStopbits_t stopBit){
	uint16_t baudRate = baud;
	
	uint16_t verifyAndStop = ((uint16_t)parity<<8) | ((uint16_t)stopBit & 0xff);
	

	writeIHoldingReg(REG_GS01_BAUDRATE,baudRate);
	return writeIHoldingReg(REG_GS01_VERIFY_AND_STOP,verifyAndStop);
   	
}


bool DFRobot_GS01::setDeviceAddr(uint16_t addr){
	
     	
	return writeIHoldingReg(REG_GS01_ADDR,addr);
	
}

DFRobot_GS01_UART::DFRobot_GS01_UART(Stream *s_,uint8_t addr)
:DFRobot_RTU(s_){
  _addr = addr;
}


uint16_t DFRobot_GS01_UART::reaInputdReg(uint16_t reg)
{
    delay(20);
    return readInputRegister(_addr,reg);

}
uint16_t DFRobot_GS01_UART::readHoldingReg(uint16_t reg)
{
  delay(20);
  return readHoldingRegister(_addr,reg);

}
bool DFRobot_GS01_UART::writeIHoldingReg(uint16_t reg,uint16_t data){

     delay(20);
	 return writeHoldingRegister(_addr,reg,data);
}
bool DFRobot_GS01_UART::wirteReg(uint16_t reg,uint16_t data)
{
      return true;
}
uint16_t DFRobot_GS01_UART::readReg(uint16_t reg)
{
    //readInputRegister(_addr,reg)
	return 0;
}








DFRobot_GS01_I2C::DFRobot_GS01_I2C(uint8_t addr)
{
  _addr = addr;
}


bool DFRobot_GS01_I2C::begin(TwoWire *pWire)
{
	
  _pWire = pWire;
  pWire->begin();
}
bool DFRobot_GS01_I2C::wirteReg(uint16_t reg,uint16_t data)
{
  uint16_t value;
  _pWire->beginTransmission(_addr);
  _pWire->write(reg>>8);
  _pWire->write(reg&0xff);
  
  _pWire->write(data>>8);
  _pWire->write(data&0xff);
  _pWire->endTransmission();
  return true;
}
uint16_t DFRobot_GS01_I2C::readReg(uint16_t reg)
{
  uint16_t value;
  _pWire->beginTransmission(_addr);
  _pWire->write(reg>>8);
  _pWire->write(reg&0xff);
  _pWire->endTransmission();
  
  delay(50);
  
  _pWire->requestFrom(_addr,(uint8_t)2);
  value = _pWire->read();
  value = value<<8 | _pWire->read();
  
  delay(500);
  return value;
}
bool DFRobot_GS01_I2C::writeIHoldingReg(uint16_t reg,uint16_t data)
{
    return wirteReg(reg,data);
}
uint16_t DFRobot_GS01_I2C::reaInputdReg(uint16_t reg)
{
    return readReg(INPUT_REG_OFFSET+reg);
}

uint16_t DFRobot_GS01_I2C::readHoldingReg(uint16_t reg){
    return readReg(reg);
}

