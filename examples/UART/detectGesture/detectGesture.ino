#include "DFRobot_GS01.h"


#define DEVICE_ID  0x72 

DFRobot_GS01_UART cs01(&Serial1,DEVICE_ID);
char str[100];
void setup(){
  
	Serial1.begin(115200);
    Serial.begin(115200);
	//人脸得分为0 ~100,设置得分阈值
    cs01.setFaceDetectThres(60);
	//手势得分为0 ~100,设置得分阈值
    cs01.setGestureDetectThres(60);	
	//设置检测范围，0~100，0的检测范围最小,100的检测范围最大
	cs01.setGestureDetectThres(100);
}



void loop(){
   if(cs01.getFaceNumber()>0){

	   uint16_t faceScore = cs01.getFaceScore();
	   uint16_t faceX =  cs01.getFaceLocationX();
	   uint16_t faceY =  cs01.getFaceLocationY();
	   sprintf(str,"detect face at (x = %d,y = %d,scroe=%d)\n",faceX,faceY,faceScore);
	   Serial.print(str);
	   
	   uint16_t gestureType = cs01.getGestureType();
	   uint16_t gestureScore = cs01.getGestureScore();	
	   sprintf(str,"detect gesture %d,scroe=%d\n",gestureType,gestureScore);
	   Serial.print(str);
	   
   }
   
   
   delay(500);
}