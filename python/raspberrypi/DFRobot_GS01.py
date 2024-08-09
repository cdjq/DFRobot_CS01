# -*- coding: utf-8 -*-
'''
  @file DFRobot_GS01.py
  @brief 定义 DFRobot_GS01 类的基本结构和基本方法的实现。
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
    # 定义一些寄存器的地址常量
    REG_GS01_ADDR = 0x0000
    REG_GS01_BAUDRATE = 0x0001
    REG_GS01_VERIFY_AND_STOP = 0x0002
    REG_GS01_FACE_THRESHOLD = 0x0003
    REG_GS01_FACE_SCORE_THRESHOLD = 0x0004
    REG_GS01_GESTURE_SCORE_THRESHOLD = 0x0005

    REG_GS01_PID = 0x0000
    REG_GS01_VID = 0x0001
    REG_GS01_HW_VERSION = 0x0002
    REG_GS01_SW_VERSION = 0x0003
    REG_GS01_FACE_NUMBER = 0x0004
    REG_GS01_FACE_LOCATION_X = 0x0005
    REG_GS01_FACE_LOCATION_Y = 0x0006
    REG_GS01_FACE_SCORE = 0x0007
    REG_GS01_GESTURE_TYPE = 0x0008
    REG_GS01_GESTURE_SCORE = 0x0009
    INPUT_REG_OFFSET = 0x06

    def __init__(self):
        # 初始化类
        pass

    '''
      @brief 获取设备pid
      @return 返回设备pid
    '''
    def read_pid(self):
        return self.readInputReg(self.REG_GS01_PID)

    '''
      @brief 获取设备vid
      @return 返回设备vid
    '''
    def read_vid(self):
        return self.readInputReg(self.REG_GS01_VID)

    '''
      @brief 获取人脸数量
      @return 返回人脸数量
    '''
    def get_face_number(self):
        return self.readInputReg(self.REG_GS01_FACE_NUMBER)

    '''
      @brief 配置UART
      @param baud 波特率
      @param parity 校验位
      @param stopBit 停止位
    '''
    def config_uart(self, baud, parity, stop_bit):
        # 设置校验位和停止位并组合成一个16位数据
        verify_and_stop = (parity << 8) | (stop_bit & 0xff)
        # 设置波特率
        self.writeHoldingReg(self.REG_GS01_BAUDRATE, baud)
        # 设置校验位和停止位
        return self.writeHoldingReg(self.REG_GS01_VERIFY_AND_STOP, verify_and_stop)

    '''
      @brief 获取人脸在X方向的位置
      @return 返回X位置
    '''
    def get_face_location_x(self):
        return self.readInputReg(self.REG_GS01_FACE_LOCATION_X)

    '''
      @brief 获取人脸在Y方向的位置
      @return 返回Y位置
    '''
    def get_face_location_y(self):
        return self.readInputReg(self.REG_GS01_FACE_LOCATION_Y)
        
    '''
      @brief 获取人脸得分
      @return 返回得分
    '''
    def get_face_score(self):
        return self.readInputReg(self.REG_GS01_FACE_SCORE)
        
    '''
      @brief 获取手势类型
      @return 返回手势类型
    '''
    def get_gesture_type(self):
        return self.readInputReg(self.REG_GS01_GESTURE_TYPE)
        
    '''
      @brief 获取手势得分
      @return 返回手势得分
    '''
    def get_gesture_score(self):
        return self.readInputReg(self.REG_GS01_GESTURE_SCORE)
        
    '''
      @brief 设置人脸检测的阈值
      @param score 阈值分数
    '''
    def set_face_detect_thres(self, score):
        return self.writeHoldingReg(self.REG_GS01_FACE_THRESHOLD, score)
        
    '''
      @brief 设置人脸得分的阈值
      @param x 阈值
    '''
    def set_detect_thres(self, x):
        return self.writeHoldingReg(self.REG_GS01_FACE_SCORE_THRESHOLD, x)
        
    '''
      @brief 设置手势检测的阈值
      @param score 阈值分数
    '''
    def set_gesturedetect_thres(self, score):
        return self.writeHoldingReg(self.REG_GS01_GESTURE_SCORE_THRESHOLD, score)
        
    '''
      @brief 设置设备地址
      @param addr 要设置的设备地址
    '''
    def set_addr(self, addr):
        return self.writeHoldingReg(self.REG_GS01_ADDR, addr)

class DFRobot_GS01_I2C(DFRobot_GS01): 
    def __init__(self, bus, addr):
        # I2C地址和总线初始化
        self.__addr = addr
        self.i2cbus = smbus.SMBus(bus)
        super(DFRobot_GS01_I2C, self).__init__()

    '''
      @fn write_reg
      @brief 写入数据到寄存器
      @param reg 16位寄存器地址
      @param data 8位配置寄存器值
    '''
    def write_reg(self, reg, data):
        # 将数据拆分为高8位和低8位，写入I2C寄存器
        val_high_byte = (data >> 8) & 0xFF 
        val_low_byte = data & 0xFF         
        self.i2cbus.write_i2c_block_data(self.__addr, reg, [val_high_byte, val_low_byte])
        return 0

    '''
      @fn read_reg
      @brief 从寄存器读取数据
      @param reg 16位寄存器地址
      @param length 读取数据的长度
      @return 读取的数据
    '''
    def read_reg(self, reg, length):
        val_high_byte = (reg >> 8) & 0xFF 
        val_low_byte = reg & 0xFF         
        self.i2cbus.write_i2c_block_data(self.__addr, val_high_byte, [val_low_byte])
        time.sleep(0.15)
        data = self.i2cbus.read_i2c_block_data(self.__addr, reg, length)
        time.sleep(0.1)
        return (data[0] << 8) | data[1]

    def writeHoldingReg(self, reg, data):
        return self.write_reg(reg, data)

    def readInputReg(self, reg):
        return self.read_reg(self.INPUT_REG_OFFSET + reg, 2)

    def readHoldingReg(self, reg):
        return self.read_reg(reg, 2)

class DFRobot_GS01_UART(DFRobot_GS01, DFRobot_RTU): 
    def __init__(self, baud, addr):
        # 初始化UART的波特率和地址
        self.__baud = baud
        self.__addr = addr
        DFRobot_GS01.__init__(self)
        DFRobot_RTU.__init__(self, baud, 8, 'N', 1)

    def writeHoldingReg(self, reg, data):
        return self.write_holding_register(self.__addr, reg, data)

    def readInputReg(self, reg):
        try:
            data = self.read_input_registers(self.__addr, reg, 1)
            
            # 确保 data 列表中至少有三个元素
            if len(data) >= 3:
                regData = (data[1] << 8) | data[2]
            else:
                regData = 0
            
            return regData
        
        except Exception as e:
    
            return 0
    
    def readHoldingReg(self, reg):
        return self.read_holding_registers(self.__addr, reg, 1)
