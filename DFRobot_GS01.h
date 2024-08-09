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







/// Register addresses for GS01 configuration
#define REG_GS01_ADDR            0x00  ///< Device address register
#define REG_GS01_BAUDRATE        0x01  ///< Baud rate configuration register
#define REG_GS01_VERIFY_AND_STOP 0x02  ///< Parity and stop bits configuration register
#define REG_GS01_FACE_THRESHOLD  0x03  ///< Face detection threshold, X coordinate
#define REG_GS01_FACE_SCORE_THRESHOLD  0x04  ///< Face score threshold
#define REG_GS01_GESTURE_SCORE_THRESHOLD 0x05 ///< Gesture score threshold

/// Register addresses for GS01 data
#define REG_GS01_PID                 0x00  ///< Product ID register
#define REG_GS01_VID                 0x01  ///< Vendor ID register
#define REG_GS01_HW_VERSION          0x02  ///< Hardware version register
#define REG_GS01_SW_VERSION          0x03  ///< Software version register
#define REG_GS01_FACE_NEMBER         0x04  ///< Number of detected faces
#define REG_GS01_FACE_LOCATION_X     0x05  ///< Face X coordinate
#define REG_GS01_FACE_LOCATION_Y     0x06  ///< Face Y coordinate
#define REG_GS01_FACE_SCORE          0x07  ///< Face score
#define REG_GS01_GESTURE_YTPE        0x08  ///< Gesture type
#define REG_GS01_GESTURE_SCORE       0x09  ///< Gesture score

#define INPUT_REG_OFFSET             0x06  ///< Input register offset

/**
 * @brief Baud rate configuration enumeration.
 */
typedef enum {
    eBaud_1200 = 1,     ///< Baud rate 1200
    eBaud_2400,         ///< Baud rate 2400
    eBaud_4800,         ///< Baud rate 4800
    eBaud_9600,         ///< Baud rate 9600
    eBaud_14400,        ///< Baud rate 14400
    eBaud_19200,        ///< Baud rate 19200
    eBaud_38400,        ///< Baud rate 38400
    eBaud_57600,        ///< Baud rate 57600
    eBaud_115200,       ///< Baud rate 115200
    eBaud_230400,       ///< Baud rate 230400
    eBaud_460800,       ///< Baud rate 460800
    eBaud_921600,       ///< Baud rate 921600
} eBaudConfig_t;

/**
 * @brief UART parity configuration enumeration.
 */
typedef enum {
    UART_CFG_PARITY_NONE = 0,  ///< No parity
    UART_CFG_PARITY_ODD,       ///< Odd parity
    UART_CFG_PARITY_EVEN,      ///< Even parity
    UART_CFG_PARITY_MARK,      ///< Mark parity
    UART_CFG_PARITY_SPACE,     ///< Space parity
} eParityConfig_t;

/**
 * @brief UART stop bits configuration enumeration.
 */
typedef enum {
    UART_CFG_STOP_BITS_0_5 = 0, ///< 0.5 stop bits
    UART_CFG_STOP_BITS_1,       ///< 1 stop bit
    UART_CFG_STOP_BITS_1_5,     ///< 1.5 stop bits
    UART_CFG_STOP_BITS_2,       ///< 2 stop bits
} eStopbits_t;

/**
 * @brief DFRobot_GS01 class.
 * 
 * Provides an interface for interacting with DFRobot GS01 devices.
 */
class DFRobot_GS01 {
public: 
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

    
	bool setFaceDetectThres(uint16_t score);

	bool setDetectThres(uint16_t x);  
	
	bool setGestureDetectThres(uint16_t score);

	
	/**
     * @brief Get the number of faces detected by the device.
     * @return Number of faces detected.
     */
    uint16_t getFaceNumber();
	
	
	uint16_t getFaceLocationX();
    
	
	uint16_t getFaceLocationY();
	
	
	uint16_t getFaceScore();	
	
	
	uint16_t getGestureType();

    	
	uint16_t getGestureScore();	
	
	
	
	
    /**
     * @brief Read input register.
     * @param reg Register address.
     * @return Value of the input register.
     */
    virtual uint16_t reaInputdReg(uint16_t reg) = 0;

    /**
     * @brief Read holding register.
     * @param reg Register address.
     * @return Value of the holding register.
     */
    virtual uint16_t readHoldingReg(uint16_t reg) = 0;

    /**
     * @brief Write to the holding register.
     * @param reg Register address.
     * @param data Data to write.
     * @return True if the write is successful, otherwise false.
     */
    virtual bool writeIHoldingReg(uint16_t reg, uint16_t data) = 0;

protected:
    uint8_t _addr; ///< Device address
};

/**
 * @brief DFRobot_GS01_UART class.
 * 
 * Provides UART specific implementation for DFRobot GS01 devices.
 */
class DFRobot_GS01_UART : public DFRobot_GS01 ,public DFRobot_RTU{
public:
    /**
     * @brief Constructor for DFRobot_GS01_UART.
     * @param s_ Pointer to the Stream object.
     * @param addr Device address.
     */
    DFRobot_GS01_UART(Stream *s_, uint8_t addr);

    uint16_t reaInputdReg(uint16_t reg);
    uint16_t readHoldingReg(uint16_t reg);
    bool writeIHoldingReg(uint16_t reg, uint16_t data);
    bool wirteReg(uint16_t reg, uint16_t data);
    uint16_t readReg(uint16_t reg);
};

/**
 * @brief DFRobot_GS01_I2C class.
 * 
 * Provides I2C specific implementation for DFRobot GS01 devices.
 */
class DFRobot_GS01_I2C : public DFRobot_GS01 {
public: 
    /**
     * @brief Constructor for DFRobot_GS01_I2C.
     * @param addr Device address.
     */
    DFRobot_GS01_I2C(uint8_t addr);

    /**
     * @brief Initialize the I2C communication.
     * @param pWire Pointer to the TwoWire object, default is &Wire.
     * @return True if initialization is successful, otherwise false.
     */
    bool begin(TwoWire *pWire = &Wire);

    bool writeIHoldingReg(uint16_t reg, uint16_t data);
    uint16_t reaInputdReg(uint16_t reg);
    uint16_t readHoldingReg(uint16_t reg);
    bool wirteReg(uint16_t reg, uint16_t data);
    uint16_t readReg(uint16_t reg);

private:
    TwoWire *_pWire; ///< I2C communication object
};
#endif