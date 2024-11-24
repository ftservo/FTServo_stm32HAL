/*
 * SMS.h
 * ModbusRtu应用层程序
 * 日期: 2021.10.16
 * 作者: 谭雄乐
 */

#ifndef _SMS_H
#define _SMS_H


//波特率定义
#define	 SMS_1M 0
#define	 SMS_0_5M 1
#define	 SMS_250K 2
#define	 SMS_128K 3
#define	 SMS_115200 4
#define	 SMS_76800 5
#define	 SMS_57600 6
#define	 SMS_38400 7

//内存表定义
//-------EPROM(只读)--------
#define SMS_VERSION 0
#define SMS_MODEL 1

//-------EPROM(读写)--------
#define SMS_ID 10
#define SMS_BAUD_RATE 11
#define SMS_MIN_ANGLE_LIMIT 13
#define SMS_MAX_ANGLE_LIMIT 14
#define SMS_OFS 15
#define SMS_MODE 16
#define SMS_P 17
#define SMS_D 18
#define SMS_I 19

//-------SRAM(读写)--------
#define SMS_GOAL_POSITION 128
#define SMS_TORQUE_ENABLE 129
#define SMS_ACC 130
#define SMS_GOAL_SPEED 131
#define SMS_TORQUE_LIMIT 132
#define SMS_LOCK 133
#define SMS_FAULT_RESET 134

//-------SRAM(只读)--------
#define SMS_PRESENT_ERROR 256
#define SMS_PRESENT_POSITION 257
#define SMS_PRESENT_SPEED 258
#define SMS_PRESENT_LOAD 259
#define SMS_PRESENT_VOLTAGE 260
#define SMS_PRESENT_TEMPERATURE 261
#define SMS_MOVING 262
#define SMS_PRESENT_CURRENT 263


//重置舵机状态宏
#define SMS_FAULT_TORQUE (1<<0)
#define SMS_FAULT_ELE (1<<1)
#define SMS_FAULT_OFS (1<<2)


#include "modbus.h"

class SMS : public Modbus
{
public:
	SMS();
	virtual int WritePosEx(uint8_t ID, int16_t Position, uint16_t Speed, uint8_t ACC = 0);//普通写位置指令
	virtual int WritePos(uint8_t ID, int16_t Position);
	virtual int joinMode(uint8_t ID);//普通伺服模式
	virtual int wheelMode(uint8_t ID);//恒速模式
	virtual int pwmMode(uint8_t ID);//PWM输出模式
	virtual int WriteSpe(uint8_t ID, int16_t Speed, uint8_t ACC = 0);//恒速模式控制指令
	virtual int WritePWM(uint8_t ID, int16_t pwmOut);//PWM输出模式指令
	virtual int EnableTorque(uint8_t ID, uint8_t Enable);//扭力控制指令
	virtual int unLockEprom(uint8_t ID);//eprom解锁
	virtual int LockEprom(uint8_t ID);//eprom加锁
	virtual int CalibrationOfs(uint8_t ID);//中位校准
	virtual int FeedBack(int ID);//反馈舵机信息
	virtual int ReadPos(int ID);//读位置
	virtual int ReadSpeed(int ID);//读电流
	virtual int ReadLoad(int ID);//读输出扭力
	virtual int ReadVoltage(int ID);//读电压
	virtual int ReadTemper(int ID);//读温度
	virtual int ReadMove(int ID);//读移动状态
	virtual int ReadCurrent(int ID);//读电流
private:
	uint16_t Mem[SMS_PRESENT_CURRENT-SMS_PRESENT_ERROR+1];
};

#endif