# -*- coding: utf-8 -*-
import smbus
import time
import serial
import sys
sys.path.append("../")
from DFRobot_GS01 import DFRobot_GS01_I2C, DFRobot_GS01_UART

# 宏定义：设置为True时使用I2C，为False时使用UART
USE_I2C = False  # 使用I2C时为True，使用UART时为False

# 定义设备地址和波特率
DEVICE_ID = 0x72
UART_BAUD_RATE = 115200

# 根据宏定义选择使用I2C或UART
if USE_I2C:
    # 使用I2C接口
    cs01 = DFRobot_GS01_I2C(bus=1, addr=DEVICE_ID)  # 假设使用I2C总线1
else:
    # 使用UART接口
    cs01 = DFRobot_GS01_UART(baud=UART_BAUD_RATE, addr=DEVICE_ID)

def setup():
    
    # 设置人脸检测得分阈值（0~100）
    cs01.set_face_detect_thres(60)
    print("Face detection threshold set to 60.")
    
    # 设置手势检测得分阈值（0~100）
    cs01.set_gesturedetect_thres(60)
    print("Gesture detection threshold set to 60.")
    
    # 设置检测范围，0~100
    cs01.set_gesturedetect_thres(100)
    print("Detection range set to maximum.")

def loop():
    while True:
        # 检查是否检测到人脸
        if cs01.get_face_number() > 0:
            # 获取人脸得分、位置坐标
            face_score = cs01.get_face_score()
            face_x = cs01.get_face_location_x()
            face_y = cs01.get_face_location_y()
            
            print("Detect face at (x = {}, y = {}, score = {})".format(face_x, face_y, face_score))
            
            # 获取手势类型和得分
            gesture_type = cs01.get_gesture_type()
            gesture_score = cs01.get_gesture_score()
            
            print("Detect gesture {}, score = {}".format(gesture_type, gesture_score))
        
        # 延时500毫秒
        time.sleep(0.5)

# 执行setup函数
setup()

# 执行loop函数
loop()
