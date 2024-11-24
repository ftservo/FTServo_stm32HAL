/*
 * Modbus.h
 * ModbusRtu硬件接口层程序
 * 日期: 2019.2.20
 * 作者: 谭雄乐
 */

#ifndef _MODBUS_H
#define _MODBUS_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Rtu.h"


class Modbus : public Rtu
{
public:
	Modbus();
	void begin(HardwareSerial *pSerial, long u32speed);
	void setTimeOut(uint16_t u16timeOut) { IOTimeOut = u16timeOut; }
protected:
	virtual int writeModbus(uint8_t *nDat, uint8_t nLen);//输出nLen字节
	virtual int readModbus(uint8_t *nDat, uint8_t nLen);//输入nLen字节
	virtual void flushModbusRx();//刷新接收缓冲区
	virtual void flushModbusTx();//刷新发送缓冲区
	
public:
	uint32_t IOTimeOut;//输入输出超时
	HardwareSerial *pSerial;//串口指针
    uint32_t txEnd_T35;
};

#endif