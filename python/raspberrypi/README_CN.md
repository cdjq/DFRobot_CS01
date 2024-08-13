# DFRobot_GS01

GS01是一款可以在最远3米距离跟踪人体头肩和检测五种手势的传感器

![Product Image](../../resources/images/SEN0486.png)


## 产品链接（https://www.dfrobot.com.cn/goods-3398.html)

  SEN0626:手势识别传感器

## 目录

* [简介](#简介)
* [安装](#安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [贡献者](#贡献者)

## 简介

提供用于控制GS01传感器的python库。

## 安装

要使用此库，首先下载库文件，将其粘贴到 `\Arduino\libraries` 目录中，然后打开示例文件夹并运行其中的示例。

## 方法
```python
  
  
    '''
      @brief Get the device PID
      @return Returns the device PID
    '''
    def read_pid(self):

    '''
      @brief Get the device VID
      @return Returns the device VID
    '''
    def read_vid(self):

    '''
      @brief Get the number of detected faces
      @return Returns the number of detected faces
    '''
    def get_face_number(self):

    '''
      @brief Configure UART
      @param baud Baud rate
      @param parity Parity bit
      @param stop_bit Stop bits
    '''
    def config_uart(self, baud, parity, stop_bit):

    '''
      @brief Get the X location of the face
      @return Returns the X location
    '''
    def get_face_location_x(self):

    '''
      @brief Get the Y location of the face
      @return Returns the Y location
    '''
    def get_face_location_y(self):

    '''
      @brief Get the face score
      @return Returns the face score
    '''
    def get_face_score(self):

    '''
      @brief Get the gesture type
      @return Returns the gesture type
    '''
    def get_gesture_type(self):

    '''
      @brief Get the gesture score
      @return Returns the gesture score
    '''
    def get_gesture_score(self):

    '''
      @brief Set the face detection threshold
      @param score Threshold score
    '''
    def set_face_detect_thres(self, score):

    '''
      @brief Set the face score threshold
      @param x Threshold value
    '''
    def set_detect_thres(self, x):

    '''
      @brief Set the gesture detection threshold
      @param score Threshold score
    '''
    def set_gesturedetect_thres(self, score):

    '''
      @brief Set the device address
      @param addr Address to set
    '''
    def set_addr(self, addr):
```

## 兼容性

| MCU         | Work Well | Work Wrong  | Untested | Remarks |
| ------------ | :--: | :----: | :----: | :--: |
| RaspberryPi4 |  √   |        |        |      |

* Python version 

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :--: | :----: | :----: | ---- |
| Python2 |  √   |        |        |      |
| Python3 |  √   |        |        |      |
## 历史 

- 2024/08/13 - Version 1.0.0 released.

## 贡献者

Written by fengli(li.feng@dfrobot.com), 2024.08.13 (Welcome to our [website](https://www.dfrobot.com/))





