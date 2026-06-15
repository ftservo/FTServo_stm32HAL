/*
 * HLS.c
 * 飞特HLS系列串行舵机应用层程序
 * 日期: 2025.10.10
 * 作者: 
 */

#include <string.h>
#include "INST.h"
#include "SCS.h"
#include "HLS.h"

int WritePosEx2(uint8_t ID, int16_t Position, uint16_t Speed, uint8_t ACC, uint16_t Torque)
{
	uint8_t bBuf[7];
	if(Position<0){
		Position = -Position;
		Position |= (1<<15);
	}

	bBuf[0] = ACC;
	Host2SCS(bBuf+1, bBuf+2, Position);
	Host2SCS(bBuf+3, bBuf+4, Torque);
	Host2SCS(bBuf+5, bBuf+6, Speed);
	
	return genWrite(ID, HLS_ACC, bBuf, 7);
}

int RegWritePosEx2(uint8_t ID, int16_t Position, uint16_t Speed, uint8_t ACC, uint16_t Torque)
{
	uint8_t bBuf[7];
	if(Position<0){
		Position = -Position;
		Position |= (1<<15);
	}

	bBuf[0] = ACC;
	Host2SCS(bBuf+1, bBuf+2, Position);
	Host2SCS(bBuf+3, bBuf+4, Torque);
	Host2SCS(bBuf+5, bBuf+6, Speed);
	
	return regWrite(ID, HLS_ACC, bBuf, 7);
}

void SyncWritePosEx2(uint8_t ID[], uint8_t IDN, int16_t Position[], uint16_t Speed[], uint8_t ACC[], uint16_t Torque[])
{
	uint8_t offbuf[32*7];
	uint8_t i;
	uint16_t V;
  for(i = 0; i<IDN; i++){
		if(Position[i]<0){
			Position[i] = -Position[i];
			Position[i] |= (1<<15);
		}

		if(Speed){
			V = Speed[i];
		}else{
			V = 0;
		}
		if(ACC){
			offbuf[i*7] = ACC[i];
		}else{
			offbuf[i*7] = 0;
		}
		Host2SCS(offbuf+i*7+1, offbuf+i*7+2, Position[i]);
    Host2SCS(offbuf+i*7+3, offbuf+i*7+4, Torque[i]);
    Host2SCS(offbuf+i*7+5, offbuf+i*7+6, V);
	}
  syncWrite(ID, IDN, HLS_ACC, offbuf, 7);
}

int WriteSpeEx(uint8_t ID, int16_t Speed, uint8_t ACC, uint16_t Torque)
{
	uint8_t bBuf[7];
	if(Speed<0){
		Speed = -Speed;
		Speed |= (1<<15);
	}
	bBuf[0] = ACC;
	Host2SCS(bBuf+1, bBuf+2, 0);
	Host2SCS(bBuf+3, bBuf+4, Torque);
	Host2SCS(bBuf+5, bBuf+6, Speed);
	
	return genWrite(ID, HLS_ACC, bBuf, 7);
}

int RegWriteSpeEx(uint8_t ID, int16_t Speed, uint8_t ACC, uint16_t Torque)
{
	uint8_t bBuf[7];
	if(Speed<0){
		Speed = -Speed;
		Speed |= (1<<15);
	}

	bBuf[0] = ACC;
	Host2SCS(bBuf+1, bBuf+2, 0);
	Host2SCS(bBuf+3, bBuf+4, Torque);
	Host2SCS(bBuf+5, bBuf+6, Speed);
	
	return regWrite(ID, HLS_ACC, bBuf, 7);
}

void SyncWriteSpeEx(uint8_t ID[], uint8_t IDN, int16_t Speed[], uint8_t ACC[], uint16_t Torque[])
{
	uint8_t offbuf[32*7];
	uint8_t i;
	uint16_t V;
  	for(i = 0; i<IDN; i++){
		if(Speed[i]<0){
			Speed[i] = -Speed[i];
			Speed[i] |= (1<<15);
		}

		if(Speed){
			V = Speed[i];
		}else{
			V = 0;
		}
		if(ACC){
			offbuf[i*7] = ACC[i];
		}else{
			offbuf[i*7] = 0;
		}
		Host2SCS(offbuf+i*7+1, offbuf+i*7+2, 0);
    Host2SCS(offbuf+i*7+3, offbuf+i*7+4, Torque[i]);
    Host2SCS(offbuf+i*7+5, offbuf+i*7+6, V);
	}
  syncWrite(ID, IDN, HLS_ACC, offbuf, 7);
}

int EleMode(uint8_t ID)
{
	return writeByte(ID, HLS_MODE, 2);		
}

int WriteEle(uint8_t ID, int16_t Torque)
{
	if(Torque<0){
		Torque = -Torque;
		Torque |= (1<<15);
	}
	return writeWord(ID, HLS_GOAL_ELE_L, Torque);
}

int RegWriteEle(uint8_t ID, int16_t Torque)
{
	uint8_t bBuf[2];
	if(Torque<0){
		Torque = -Torque;
		Torque |= (1<<15);
	}

	Host2SCS(bBuf+0, bBuf+1, Torque);
	return regWrite(ID, HLS_GOAL_ELE_L, bBuf, 2);
}

void SyncWriteEle(uint8_t ID[], uint8_t IDN, int16_t Torque[])
{
	uint8_t offbuf[32*2];
	uint8_t i;
  for(i = 0; i<IDN; i++){
		if(Torque[i]<0){
			Torque[i] = -Torque[i];
			Torque[i] |= (1<<15);
		}
    Host2SCS(offbuf+i*7+0, offbuf+i*7+1, Torque[i]);
	}
  syncWrite(ID, IDN, HLS_GOAL_ELE_L, offbuf, 2);
}
