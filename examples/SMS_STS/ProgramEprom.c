#include "main.h"
#include <../../SCSLib/SCServo.h>
void setup(void)
{
	setEnd(0);//SMS_STS舵机为小端存储结构
}

void examples(void)
{
	unLockEpromEx(1);//打开EPROM保存功能
	writeByte(1, SMS_STS_ID, 2);//ID
	LockEpromEx(2);//关闭EPROM保存功能
	while(1){}
}
