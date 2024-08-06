# DFRobot_GS01
GS01 is a sensor capable of tracking human head and shoulders and detecting five types of gestures from up to 3 meters away.
   
   
![正反面svg效果图](https://github.com/cdjq/DFRobot_GS01/raw/master/resources/images/SEN0245svg4.png)

## 产品链接（链接到英文商城）
    SEN0626:Gesture Sensor 

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


## Summary


Provide an Arduino library to control 

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods
```C++

    /**
     * @brief Constructor for DFRobot_GS01.
     */
    DFRobot_GS01();

    /**
     * @brief Get the PID of the GS01 device.
     * @return PID of the GS01 device.
     */
    uint16_t getGs01Pid();

    /**
     * @brief Get the VID of the GS01 device.
     * @return VID of the GS01 device.
     */
    uint16_t getGs01Vid();

    /**
     * @brief Get the number of faces detected by the device.
     * @return Number of faces detected.
     */
    uint16_t getFaceNumber();

    /**
     * @brief Set the device address.
     * @param addr Device address.
     * @return True if the address is set successfully, otherwise false.
     */
    bool setDeviceAddr(uint16_t addr);

    /**
     * @brief Configure the UART settings.
     * @param baud Baud rate configuration.
     * @param parity Parity configuration.
     * @param stopBit Stop bits configuration.
     * @return Status of the configuration.
     */
    uint16_t configUart(eBaudConfig_t baud, eParityConfig_t parity, eStopbits_t stopBit);

```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
Arduino MEGA2560        |      √       |              |             | 
Arduino Leonardo|      √       |              |             | 
Micro:bit        |      √       |              |             | 
FireBeetle-M0        |      √       |              |             | 
Raspberry Pi      |      √       |              |             | 

## History

- Date 2024-8-1
- Version V0.1
## Credits
Written by fengli(li.feng@dfrobot.com), 2021.7.22 (Welcome to our [website](https://www.dfrobot.com/))
## History