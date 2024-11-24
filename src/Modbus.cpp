/*
 * Modbus.h
 * ModbusRtu硬件接口层程序
 * 日期: 2019.2.20
 * 作者: 谭雄乐
 */


#include "Modbus.h"

Modbus::Modbus()
{
	IOTimeOut = 50;
	pSerial = NULL;
}

void Modbus::begin(HardwareSerial *pSerial, long u32speed)
{
	this->pSerial = pSerial;
	pSerial->begin(u32speed);
	txEnd_T35 = ((1000000*35)/u32speed+10);
}

int Modbus::readModbus(uint8_t *nDat, uint8_t nLen)
{
	int Size = 0;
	int ComData;
	unsigned long t_begin = millis();
	unsigned long t_user;
	while(1){
		ComData = pSerial->read();
		if(ComData!=-1){
			if(nDat){
				nDat[Size] = ComData;
			}
			Size++;
			t_begin = millis();
		}
		if(Size>=nLen){
			break;
		}
		t_user = millis() - t_begin;
		if(t_user>IOTimeOut){
			break;
		}
	}
	return Size;
}

int Modbus::writeModbus(uint8_t *nDat, uint8_t nLen)
{
	if(nDat==NULL){
		return 0;
	}
	return pSerial->write(nDat, nLen);
}


void Modbus::flushModbusRx()
{
	while(pSerial->read()!=-1);
}

void Modbus::flushModbusTx()
{
	pSerial->flush();
	delayMicroseconds(txEnd_T35);
}