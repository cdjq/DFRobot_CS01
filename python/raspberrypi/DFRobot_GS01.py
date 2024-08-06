# -*- coding: utf-8 -*
'''
  @file DFRobot_GS01.py
  @brief Define the basic structure of class DFRobot_GS01, the implementation of basic methods.
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT license (MIT)
  @author [fengli](li.feng@dfrobot.com)
  @version  V1.0
  @date  2021-6-28
  @https://github.com/DFRobot/DFRobot_GS01
'''


import serial
import time
import smbus
from DFRobot_RTU import *

class DFRobot_GS01(object):



     REG_GS01_ADDR             =                   0x0000
     REG_GS01_BAUDRATE         =                   0x0001
     REG_GS01_VERIFY_AND_STOP  =                   0x0002
     REG_GS01_FACE_THRESHOLD   =                   0x0003
     REG_GS01_FACE_SCORE_THRESHOLD =               0x0004
     REG_GS01_GESTURE_SCORE_THRESHOLD =            0x0005
                                               
     REG_GS01_PID             =                    0x0000
     REG_GS01_VID             =                    0x0001
     REG_GS01_HW_VERSION             =             0x0002
     REG_GS01_SW_VERSION             =             0x0003
     REG_GS01_FACE_NEMBER             =            0x0004
     REG_GS01_FACE_LOCATION_X  =                   0x0005
     REG_GS01_FACE_LOCATION_Y  =                   0x0006
     REG_GS01_FACE_SCORE             =             0x0007
     REG_GS01_GESTURE_YTPE             =           0x0008
     REG_GS01_GESTURE_SCORE             =          0x0009
     INPUT_REG_OFFSET             =                0x06
 
 
 
 
 
 
  ''' register configuration '''
  
  
  ''' Conversion data '''

  def __init__(self):
     pass

  '''
    @brief 获取设备pid
    @return 返回16设备pid
  '''
  def read_pid(self):
     return self.readHoldingReg(self.REG_GS01_PID)

  '''
    @brief 获取设备vid
    @return 返回16设备vid
  '''
  def read_vid(self):
     return self.readHoldingReg(self.REG_GS01_VID)
  
  '''
    @brief 设置设备地址
    @param addr 要设置的设备地址
    @return Exception code:
    @n      0 : sucess.
    @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
    @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
    @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
    @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
    @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
    @n      9 or eRTU_RECV_ERROR:  Receive packet error.
    @n      10 or eRTU_MEMORY_ERROR: Memory error.
    @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
  '''
  

  def getFaceNumber(self):
     return self.reaInputdReg(self.REG_GS01_FACE_NEMBER);


  def configUart(self,baud,parity,stopBit):

    verifyAndStop = (parity<<8) | (stopBit & 0xff);
	writeIHoldingReg(self.REG_GS01_BAUDRATE,baudRate);
	return writeIHoldingReg(self.REG_GS01_VERIFY_AND_STOP,verifyAndStop);
    
    
  def set_addr(self,addr):
    return self.writeIHoldingReg(self.__Addr,self.REG_GS01_ADDR,addr)
     


class DFRobot_GM60_I2C(DFRobot_GM60): 

  def __init__(self ,bus ,addr):
    self.__addr = addr
    super(DFRobot_GM60_I2C, self).__init__(bus,0)
    

  def write_reg(self, reg, data):
  '''
    @fn write_reg
    @brief Write data to register
    @param reg 16-bit register address
    @param data 8-bit config register value
    @param len  Continuously configure register numbers
  '''
    val_high_byte = (data >> 8) & 0xFF 
    val_low_byte = data & 0xFF         
    self.i2cbus.write_i2c_block_data(self.__addr,reg,[val_high_byte,val_high_byte])
    return 0
  

  def read_reg(self,reg,data,length):
  '''
    @fn read_reg
    @brief Read data from the register
    @param reg 16-bit register address
    @param data Storage location for the read register value
    @param length  Continuously read register numbers
  '''
    data[0,1]
    data = self.read_i2c_block_data(self.__addr,reg,2)
    
    
    return (data[0]<<8)|data[1]
       

  def writeIHoldingReg(self, reg,data):
  '''
    @fn write_data
    @brief Write a data to the sensor
    @param data The data to be written
  '''
    return self.write_reg(self.__addr,reg,data)
    

  def readInputdReg(self,reg):
  '''
    @fn read
    @brief Read data from the sensor
    @param len Length of the data to be read
    @return Return the read data as an array
  '''
    return self.readReg(self.__addr,INPUT_REG_OFFSET+reg);
  def readHoldingReg(self,reg):
  '''
    @fn read
    @brief Read data from the sensor
    @param len Length of the data to be read
    @return Return the read data as an array
  '''
    return self.readReg(self.__addr,INPUT_REG_OFFSET);
    
    
    
class DFRobot_GM60_UART(DFRobot_GM60): 

  def __init__(self ,Baud):
    self.__Baud = Baud;
    super(DFRobot_GM60_UART, self).__init__(0,Baud)


  def writeIHoldingReg(self, reg,data):
  '''
    @fn write_data
    @brief Write a data to the sensor
    @param data The data to be written
  '''
    return self.write_holding_register(self.__Addr,reg,data)
    

  def reaInputdReg(self,reg):
  '''
    @fn read
    @brief Read data from the sensor
    @param len Length of the data to be read
    @return Return the read data as an array
  '''
    return self.readReg(self.__addr,INPUT_REG_OFFSET+reg);
  def readHoldingReg(self,reg):
  '''
    @fn read
    @brief Read data from the sensor
    @param len Length of the data to be read
    @return Return the read data as an array
  '''
    return self.read_holding_register(self.__Addr,reg)
