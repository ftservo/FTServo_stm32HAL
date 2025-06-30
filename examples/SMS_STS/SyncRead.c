/*
同步读支持SMS/STS两个型号舵机
*/

#include "main.h"
#include <../../SCSLib/SCServo.h>
#include <stdio.h>

int16_t Position;
int16_t Speed;
uint8_t ID[] = {1, 2};
uint8_t rxPacket[4];

void setup(void)
{
  setEnd(0);//SMS_STS舵机为小端存储结构
}

void examples(void)
{
	uint8_t i;
	uint8_t ID[] = {1, 2};
	uint8_t rxPacket[4];

  syncReadPacketTx(ID, sizeof(ID), SMS_STS_PRESENT_POSITION_L, sizeof(rxPacket));//同步读指令包发送
	for(i=0; i<sizeof(ID); i++){
		//接收ID[i]同步读返回包
		if(!syncReadPacketRx(ID[i], rxPacket)){
			printf("ID:%d sync read error!\n", ID[i]);
			continue;//接收解码失败
		}
		Position = syncReadRxPacketToWrod(15);//解码两个字节 bit15为方向位,参数=0表示无方向位
		Speed = syncReadRxPacketToWrod(15);//解码两个字节 bit15为方向位,参数=0表示无方向位
		printf("ID:%d Position:%d Speed:%d ", ID[i], Position, Speed);
		HAL_Delay(10);
	}
	printf("\n");
}
