# DFRobot_CS01

GS01是一款可以在最远3米距离跟踪人体头肩和检测五种手势的传感器

![正反面svg效果图](https://github.com/cdjq/DFRobot_GS01/raw/master/resources/images/SEN0245svg4.png)

## 产品链接（链接到英文商城）

SEN0626: Gesture Sensor 手势传感器

## 目录

* [简介](#简介)
* [安装](#安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [贡献者](#贡献者)

## 简介

提供用于控制GS01传感器的Arduino库。

## 安装

1.要使用此库，首先下载库文件，将其粘贴到 `\Arduino\libraries` 目录中，然后打开示例文件夹并运行其中的示例。
2.使用该库还需下载依赖：https://github.com/DFRobot/DFRobot_RTU
## 方法
```c++
/**
     * @brief DFRobot_GS01 的构造函数。
     */
    DFRobot_GS01();

    /**
     * @brief 获取 GS01 设备的 PID。
     * @return GS01 设备的 PID。
     */
    uint16_t getGs01Pid();

    /**
     * @brief 获取 GS01 设备的 VID。
     * @return GS01 设备的 VID。
     */
    uint16_t getGs01Vid();

    /**
     * @brief 设置设备地址。
     * @param addr 设备地址。
     * @return 如果地址设置成功则返回 true，否则返回 false。
     */
    bool setDeviceAddr(uint16_t addr);

    /**
     * @brief 配置 UART 设置。
     * @param baud 波特率配置。
     * @param parity 校验配置。
     * @param stopBit 停止位配置。
     * @return 配置状态。
     */
    uint16_t configUart(eBaudConfig_t baud, eParityConfig_t parity, eStopbits_t stopBit);

    /**
     * @brief 设置人脸检测阈值。
     * @param score 阈值。
     * @return 如果阈值设置成功则返回 true，否则返回 false。
     */
    bool setFaceDetectThres(uint16_t score);

    /**
     * @brief 设置 X 坐标检测阈值。
     * @param x 阈值。
     * @return 如果阈值设置成功则返回 true，否则返回 false。
     */
    bool setDetectThres(uint16_t x);  

    /**
     * @brief 设置手势检测阈值。
     * @param score 阈值。
     * @return 如果阈值设置成功则返回 true，否则返回 false。
     */
    bool setGestureDetectThres(uint16_t score);

    /**
     * @brief 获取设备检测到的人脸数量。
     * @return 检测到的人脸数量。
     */
    uint16_t getFaceNumber();

    /**
     * @brief 获取检测到的人脸的 X 坐标。
     * @return 人脸的 X 坐标。
     */
    uint16_t getFaceLocationX();

    /**
     * @brief 获取检测到的人脸的 Y 坐标。
     * @return 人脸的 Y 坐标。
     */
    uint16_t getFaceLocationY();

    /**
     * @brief 获取检测到的人脸得分。
     * @return 人脸得分。
     */
    uint16_t getFaceScore();  

    /**
     * @brief 获取检测到的手势类型。
     * @return 手势类型。
     */
    uint16_t getGestureType();

    /**
     * @brief 获取检测到的手势得分。
     * @return 手势得分。
     */
    uint16_t getGestureScore();  


```


## 兼容性

MCU                | 表现良好	|表现异常	|未测试	|备注 |
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
Arduino MEGA2560        |      √       |              |             | 
Arduino Leonardo|      √       |              |             | 
Micro:bit        |      √       |              |             | 
FireBeetle-M0        |      √       |              |             | 
Raspberry Pi      |      √       |              |             | 

## 历史

- Date 2024-8-1
- Version V0.1


## 贡献者

Written by fengli(li.feng@dfrobot.com), 2024.8.01 (Welcome to our [website](https://www.dfrobot.com/))

## History