#ifndef _DFROBOT_CS01_H
#define _DFROBOT_CS01_H

#include "Arduino.h"
#include "DFRobot_RTU.h"
#include <Wire.h>
#include <stdint.h>
//#define ENABLE_DBG
#ifdef ENABLE_DBG
#define LDBG(...)  {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define LDBG(...)
#endif







#define REG_CS01_ADDR            0x00
#define REG_CS01_BAUDRATE        0x01
#define REG_CS01_VERIFY_AND_STOP 0x02
#define REG_CS01_FACE_THRESHOLD  0x03                     //人体头肩检测阈值，X坐标
#define REG_CS01_FACE_SCORE_THRESHOLD  0x04           //人体头肩得分阈值
#define REG_CS01_GESTURE_SCORE_THRESHOLD    0x05     //手势检测得分阈值





#define REG_CS01_PID                 0x00
#define REG_CS01_VID                 0x01
#define REG_CS01_HW_VERSION          0x02
#define REG_CS01_SW_VERSION          0x03
#define REG_CS01_FACE_NEMBER         0x04       //人脸数量
#define REG_CS01_FACE_LOCATION_X     0x05       //人脸X坐标
#define REG_CS01_FACE_LOCATION_Y     0x06       //人脸y坐标
#define REG_CS01_FACE_SCORE          0x07       //人脸得分
#define REG_CS01_GESTURE_YTPE        0x08       //手势类型
#define REG_CS01_GESTURE_SCORE       0x09       //手势得分

#define INPUT_REG_OFFSET             0x06



typedef enum{
	eBaud_1200 = 1,
	eBaud_2400,
	eBaud_4800,
	eBaud_9600,
	eBaud_14400,
	eBaud_19200,
	eBaud_38400,
	eBaud_57600,	
	eBaud_115200,
	eBaud_230400,
	eBaud_460800,
	eBaud_921600,
}eBaudConfig_t;

typedef enum  {
	UART_CFG_PARITY_NONE = 0,
	UART_CFG_PARITY_ODD,
	UART_CFG_PARITY_EVEN,
	UART_CFG_PARITY_MARK,
	UART_CFG_PARITY_SPACE,
}eParityConfig_t;

typedef enum  {
	UART_CFG_STOP_BITS_0_5 = 0,
	UART_CFG_STOP_BITS_1,
	UART_CFG_STOP_BITS_1_5,
	UART_CFG_STOP_BITS_2,
}eStopbits_t;


class DFRobot_CS01 {
public:	
	DFRobot_CS01();
	uint16_t getCs01Pid();
	uint16_t getCs01Vid();	
	uint16_t getFaceNumber();	
	bool setDeviceAddr(uint16_t addr);
	uint16_t configUart(eBaudConfig_t baud,eParityConfig_t parity,eStopbits_t stopBit);
	
	//virtual bool wirteReg(uint16_t reg,uint16_t data) = 0;
	//virtual uint16_t readReg(uint16_t reg) = 0;
	virtual uint16_t reaInputdReg(uint16_t reg) = 0;
	virtual uint16_t readHoldingReg(uint16_t reg) = 0;
	virtual bool writeIHoldingReg(uint16_t reg,uint16_t data) = 0;
    uint8_t _addr;
};







class DFRobot_CS01_UART : public DFRobot_CS01 , public DFRobot_RTU {
	
public:
    DFRobot_CS01_UART(Stream *s_,uint8_t addr);
	
	uint16_t reaInputdReg(uint16_t reg);
	uint16_t readHoldingReg(uint16_t reg);
	bool writeIHoldingReg(uint16_t reg,uint16_t data);
	bool wirteReg(uint16_t reg,uint16_t data);
	uint16_t readReg(uint16_t reg);
};


class DFRobot_CS01_I2C : public DFRobot_CS01 {
public:	
	DFRobot_CS01_I2C(uint8_t addr);
	bool begin(TwoWire *pWire = &Wire);
	bool writeIHoldingReg(uint16_t reg,uint16_t data);
	uint16_t reaInputdReg(uint16_t reg);
	uint16_t readHoldingReg(uint16_t reg);
	bool wirteReg(uint16_t reg,uint16_t data);
	uint16_t readReg(uint16_t reg);
private:
    TwoWire *_pWire; ///< IIC 通信对象
};

#endif