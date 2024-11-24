/*
 * SMS.h
 * ModbusRtu应用层程序
 * 日期: 2021.10.16
 * 作者: 谭雄乐
 */

#include "SMS.h"

SMS::SMS()
{}

//写位置指令
//舵机ID，Position位置，加速度ACC，速度Speed
int SMS::WritePosEx(uint8_t ID, int16_t Position, uint16_t Speed, uint8_t ACC)
{
	uint16_t wDat[4];
	wDat[0] = Position;
	wDat[1] = 1;
	wDat[2] = ACC;
	wDat[3] = Speed;
	return writeReg(ID, SMS_GOAL_POSITION, wDat, 4);
}

//写位置指令
//舵机ID，Position位置
int SMS::WritePos(uint8_t ID, int16_t Position)
{
	return writeReg(ID, SMS_GOAL_POSITION, Position);
}

int SMS::joinMode(uint8_t ID) 
{
	return writeReg(ID, SMS_MODE, 0);	
}

int SMS::wheelMode(uint8_t ID)
{
	return writeReg(ID, SMS_MODE, 1);		
}

int SMS::pwmMode(uint8_t ID)
{
	return writeReg(ID, SMS_MODE, 2);		
}

//速度控制模式
int SMS::WriteSpe(uint8_t ID, int16_t Speed, uint8_t ACC)
{
	uint16_t wDat[2];
	wDat[0] = ACC;
	wDat[1] = Speed;
	return writeReg(ID, SMS_ACC, wDat, 2);
}

//PWM输出模式
 int SMS::WritePWM(uint8_t ID, int16_t pwmOut)
{
	return writeReg(ID, SMS_GOAL_SPEED, pwmOut);
}

int SMS::EnableTorque(uint8_t ID, uint8_t Enable)
{
	return writeReg(ID, SMS_TORQUE_ENABLE, Enable);
}

int SMS::unLockEprom(uint8_t ID)
{
	return writeReg(ID, SMS_LOCK, 0);//打开EPROM保存功能
}

int SMS::LockEprom(uint8_t ID)
{
	return writeReg(ID, SMS_LOCK, 1);//关闭EPROM保存功能
}

int SMS::CalibrationOfs(u8 ID)
{
	return writeReg(ID, SMS_FAULT_RESET, SMS_FAULT_OFS);
}

int SMS::FeedBack(int ID)
{
	return readReg(ID, SMS_PRESENT_ERROR, Mem, sizeof(Mem)/sizeof(uint16_t));
}

int16_t SMS::ReadPos(int ID)
{
	int Pos;
	if(ID==-1){
		Pos = Mem[SMS_PRESENT_POSITION-SMS_PRESENT_ERROR];
	}else{
		Pos = readReg(ID, SMS_PRESENT_POSITION);
	}	
	return Pos;
}

int SMS::ReadSpeed(int ID)
{
	int Speed;
	if(ID==-1){
		Speed = Mem[SMS_PRESENT_SPEED-SMS_PRESENT_ERROR];
	}else{
		Speed = readReg(ID, SMS_PRESENT_SPEED);
	}
	return Speed;
}

int SMS::ReadLoad(int ID)
{
	int Load;
	if(ID==-1){
		Load = Mem[SMS_PRESENT_LOAD-SMS_PRESENT_ERROR];
	}else{
		Load = readReg(ID, SMS_PRESENT_LOAD);
	}
	return Load;
}

int SMS::ReadVoltage(int ID)
{
	int Voltage;
	if(ID==-1){
		Voltage = Mem[SMS_PRESENT_VOLTAGE-SMS_PRESENT_ERROR];	
	}else{
		Voltage = readReg(ID, SMS_PRESENT_VOLTAGE);
	}
	return Voltage;
}

int SMS::ReadTemper(int ID)
{
	int Temper;
	if(ID==-1){
		Temper = Mem[SMS_PRESENT_TEMPERATURE-SMS_PRESENT_ERROR];	
	}else{
		Temper = readReg(ID, SMS_PRESENT_TEMPERATURE);
	}
	return Temper;
}

int SMS::ReadMove(int ID)
{
	int Move;
	if(ID==-1){
		Move = Mem[SMS_MOVING-SMS_PRESENT_ERROR];	
	}else{
		Move = readReg(ID, SMS_MOVING);
	}
	return Move;
}

int SMS::ReadCurrent(int ID)
{
	int Current;
	if(ID==-1){
		Current = Mem[SMS_PRESENT_CURRENT-SMS_PRESENT_ERROR];
	}else{
		Current = readReg(ID, SMS_PRESENT_CURRENT);
	}
	return Current;
}
