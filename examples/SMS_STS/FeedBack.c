/*
回读所有舵机反馈参数:位置、速度、负载、电压、温度、移动状态、电流；
FeedBack函数回读舵机参数于缓冲区，Readxxx(-1)函数返回缓冲区中相应的舵机状态；
函数Readxxx(ID)，ID=-1返回FeedBack缓冲区参数；ID>=0，通过读指令直接返回指定ID舵机状态,
无需调用FeedBack函数。
*/

#include "main.h"
#include <../../SCSLib/SCServo.h>
#include <stdio.h>

void setup(void)
{
	setEnd(0);//SMS_STS舵机为小端存储结构
}

void examples(void)
{
	int Pos;
  int Speed;
  int Load;
  int Voltage;
  int Temper;
  int Move;
  int Current;
	SMS_STS_FeedBack(1);
  if(!getLastError()){
    Pos = SMS_STS_ReadPos(-1);
    Speed = SMS_STS_ReadSpeed(-1);
    Load = SMS_STS_ReadLoad(-1);
    Voltage = SMS_STS_ReadVoltage(-1);
    Temper = SMS_STS_ReadTemper(-1);
    Move = SMS_STS_ReadMove(-1);
		Current = SMS_STS_ReadCurrent(-1);
		printf("Pos:%d\n", Pos);
		printf("Speed:%d\n", Speed);
		printf("Load:%d\n", Load);
		printf("Voltage:%d\n", Voltage);
		printf("Temper:%d\n", Temper);
		printf("Move:%d\n", Move);
    printf("Current:%d\n", Current);
    HAL_Delay(10);
  }else{
		printf("FeedBack err\n");
    HAL_Delay(2000);
  }
  Pos = SMS_STS_ReadPos(1);
  if(!getLastError()){
    printf("Servo position:%d\n", Pos);
    HAL_Delay(10);
  }else{
    printf("read position err\n");
    HAL_Delay(500);
  }
  
  Voltage = SMS_STS_ReadVoltage(1);
  if(!getLastError()){
		printf("Servo Voltage:%d\n", Voltage);
    HAL_Delay(10);
  }else{
    printf("read Voltage err\n");
    HAL_Delay(500);
  }
  
  Temper = SMS_STS_ReadTemper(1);
  if(!getLastError()){
    printf("Servo temperature:%d\n", Temper);
    HAL_Delay(10);
  }else{
    printf("read temperature err\n");
    HAL_Delay(500);    
  }

  Speed = SMS_STS_ReadSpeed(1);
  if(!getLastError()){
    printf("Servo Speed:%d\n", Speed);
    HAL_Delay(10);
  }else{
    printf("read Speed err\n");
    HAL_Delay(500);    
  }
  
  Load = SMS_STS_ReadLoad(1);
  if(!getLastError()){
    printf("Servo Load:%d\n", Load);
    HAL_Delay(10);
  }else{
    printf("read Load err\n");
    HAL_Delay(500);    
  }
  
  Current = SMS_STS_ReadCurrent(1);
  if(!getLastError()){
    printf("Servo Current:%d\n", Current);
    HAL_Delay(10);
  }else{
    printf("read Current err\n");
    HAL_Delay(500);    
  }

  Move = SMS_STS_ReadMove(1);
  if(!getLastError()){
    printf("Servo Move:%d\n", Move);
    HAL_Delay(10);
  }else{
    printf("read Move err\n");
    HAL_Delay(500);    
  }
  printf("\n");
}
