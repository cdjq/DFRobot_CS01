#include "DFRobot_CS01.h"
DFRobot_CS01::DFRobot_CS01()
{

}
uint16_t DFRobot_CS01::getCs01Pid()
{
    return reaInputdReg(REG_CS01_PID);
}
uint16_t DFRobot_CS01::getCs01Vid()
{
    return reaInputdReg(REG_CS01_VID);
}


uint16_t DFRobot_CS01::getFaceNumber(){
    return reaInputdReg(REG_CS01_FACE_NEMBER);
}	
uint16_t DFRobot_CS01::configUart(eBaudConfig_t baud,eParityConfig_t parity,eStopbits_t stopBit){
	uint16_t baudRate = baud;
	
	uint16_t verifyAndStop = ((uint16_t)parity<<8) | ((uint16_t)stopBit & 0xff);
	

	writeIHoldingReg(REG_CS01_BAUDRATE,baudRate);
	return writeIHoldingReg(REG_CS01_VERIFY_AND_STOP,verifyAndStop);
   	
}


bool DFRobot_CS01::setDeviceAddr(uint16_t addr){
	
     	
	return writeIHoldingReg(REG_CS01_ADDR,addr);
	
}

DFRobot_CS01_UART::DFRobot_CS01_UART(Stream *s_,uint8_t addr)
:DFRobot_RTU(s_){
  _addr = addr;
}


uint16_t DFRobot_CS01_UART::reaInputdReg(uint16_t reg)
{
    delay(20);
    return readInputRegister(_addr,reg);

}
uint16_t DFRobot_CS01_UART::readHoldingReg(uint16_t reg)
{
  delay(20);
  return readHoldingRegister(_addr,reg);

}
bool DFRobot_CS01_UART::writeIHoldingReg(uint16_t reg,uint16_t data){

     delay(20);
	 return writeHoldingRegister(_addr,reg,data);
}
bool DFRobot_CS01_UART::wirteReg(uint16_t reg,uint16_t data)
{
      return true;
}
uint16_t DFRobot_CS01_UART::readReg(uint16_t reg)
{
    //readInputRegister(_addr,reg)
	return 0;
}








DFRobot_CS01_I2C::DFRobot_CS01_I2C(uint8_t addr)
{
  _addr = addr;
}


bool DFRobot_CS01_I2C::begin(TwoWire *pWire)
{
	
  _pWire = pWire;
  pWire->begin();
}
bool DFRobot_CS01_I2C::wirteReg(uint16_t reg,uint16_t data)
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
uint16_t DFRobot_CS01_I2C::readReg(uint16_t reg)
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
bool DFRobot_CS01_I2C::writeIHoldingReg(uint16_t reg,uint16_t data)
{
    return wirteReg(reg,data);
}
uint16_t DFRobot_CS01_I2C::reaInputdReg(uint16_t reg)
{
    return readReg(INPUT_REG_OFFSET+reg);
}

uint16_t DFRobot_CS01_I2C::readHoldingReg(uint16_t reg){
    return readReg(reg);
}

