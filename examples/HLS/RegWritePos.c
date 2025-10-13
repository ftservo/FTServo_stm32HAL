#include "main.h"
#include <../../SCSLib/SCServo.h>

void setup(void)
{
	setEnd(0);//HLS舵机为小端存储结构
}

void examples(void)
{
  //舵机(ID1/ID2)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，最大扭矩电流T=3500*6.5=3250mA，运行至P1=4095位置
  RegWritePosEx2(1, 4095, 60, 50, 500);
  RegWritePosEx2(2, 4095, 60, 50, 500);
  RegWriteAction();
  HAL_Delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)

  //舵机(ID1/ID2)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，最大扭矩电流T=500*6.5=3250mA，运行至P1=4095位置
  RegWritePosEx2(1, 0, 60, 50, 500);
  RegWritePosEx2(2, 0, 60, 50, 500);
  RegWriteAction();
  HAL_Delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)
}
