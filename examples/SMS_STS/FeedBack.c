/*
�ض����ж����������:λ�á��ٶȡ����ء���ѹ���¶ȡ��ƶ�״̬��������
FeedBack�����ض���������ڻ�������Readxxx(-1)�������ػ���������Ӧ�Ķ��״̬��
����Readxxx(ID)��ID=-1����FeedBack������������ID>=0��ͨ����ָ��ֱ�ӷ���ָ��ID���״̬,
�������FeedBack������
*/

#include "main.h"
#include <../../SCSLib/SCServo.h>
#include <stdio.h>

void setup(void)
{
	setEnd(0);//SMS_STS���ΪС�˴洢�ṹ
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
