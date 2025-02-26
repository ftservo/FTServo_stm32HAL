#include "main.h"
#include <../../SCSLib/SCServo.h>
void setup(void)
{
	setEnd(0);//SMS_STS舵机为小端存储结构
}

void examples(void)
{
	SMS_STS_unLockEprom(1);//打开EPROM保存功能
  writeByte(1, SCSCL_ID, 2);//ID
	SMS_STS_LockEprom(2);//关闭EPROM保存功能
	while(1){}
}
