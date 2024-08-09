# -*- coding: utf-8 -*-
import smbus
import time
import serial
import sys
sys.path.append("../")
from DFRobot_GS01 import DFRobot_GS01_I2C, DFRobot_GS01_UART

# 定义宏 (通过设置变量来模拟)
USE_I2C = False  # 如果需要使用I2C，设置为True；使用UART则设置为False

# 定义设备地址和波特率
DEVICE_ID = 0x72
UART_BAUD_RATE = 115200

# 根据宏选择使用I2C或UART
if USE_I2C:
    # 使用I2C接口
    cs01 = DFRobot_GS01_I2C(bus=1, addr=DEVICE_ID)  # 这里假设使用的是I2C总线1
else:
    # 使用UART接口
    cs01 = DFRobot_GS01_UART(baud=UART_BAUD_RATE, addr=DEVICE_ID)

def setup():
    if USE_I2C:
        # I2C 不需要额外初始化
        print("I2C setup complete.")
    else:
        # 配置UART通信
        cs01.config_uart(baud=UART_BAUD_RATE, parity=0, stop_bit=2)
        print("UART configured.")
    
    # 设置设备地址
    cs01.set_addr(DEVICE_ID)
    print("Device address set to: {}".format(DEVICE_ID))

def loop():
    # 主循环，暂时为空
    while True:
        time.sleep(1)  # 类似于Arduino的delay函数

# 执行setup函数
setup()

# 执行loop函数
loop()