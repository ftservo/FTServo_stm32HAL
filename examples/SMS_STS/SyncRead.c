/*
ͬ����֧��SMS/STS�����ͺŶ��
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
  setEnd(0);//SMS_STS���ΪС�˴洢�ṹ
}

void examples(void)
{
	uint8_t i;
	uint8_t ID[] = {1, 2};
	uint8_t rxPacket[4];

  syncReadPacketTx(ID, sizeof(ID), SMS_STS_PRESENT_POSITION_L, sizeof(rxPacket));//ͬ����ָ�������
	for(i=0; i<sizeof(ID); i++){
		//����ID[i]ͬ�������ذ�
		if(!syncReadPacketRx(ID[i], rxPacket)){
			printf("ID:%d sync read error!\n", ID[i]);
			continue;//���ս���ʧ��
		}
		Position = syncReadRxPacketToWrod(15);//���������ֽ� bit15Ϊ����λ,����=0��ʾ�޷���λ
		Speed = syncReadRxPacketToWrod(15);//���������ֽ� bit15Ϊ����λ,����=0��ʾ�޷���λ
		printf("ID:%d Position:%d Speed:%d ", ID[i], Position, Speed);
		HAL_Delay(10);
	}
	printf("\n");
}
