#include "main.h"
#include <../../SCSLib/SCServo.h>

void setup(void)
{
	setEnd(0);//SMS_STS舵机为大端存储结构
}

void examples(void)
{
  //舵机(ID1/ID2)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，运行至P1=4095位置
  RegWritePosEx(1, 4095, 60, 50);
  RegWritePosEx(2, 4095, 60, 50);
  RegWriteAction();
  HAL_Delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)

  //舵机(ID1/ID2)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，运行至P0=0位置
  RegWritePosEx(1, 0, 60, 50);
  RegWritePosEx(2, 0, 60, 50);
  RegWriteAction();
  HAL_Delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)
}
