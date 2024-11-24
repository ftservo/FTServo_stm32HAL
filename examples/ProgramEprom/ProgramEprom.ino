#include <ModbusRtu.h>

int LEDpin = 13;
SMS sm;

void setup()
{
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin, LOW);
  sm.begin(&Serial1, 115200); // baud-rate at 115200
  sm.setTimeOut(100); // if there is no answer in 100 ms, roll over
  Serial.begin(115200);
  
  delay(1000);//等待舵机初始化完成
  
  sm.unLockEprom(1);//打开EPROM保存功能
  sm.writeReg(1, SMS_ID, 2);//ID
  sm.LockEprom(2);//关闭EPROM保存功能
  digitalWrite(LEDpin, HIGH);
}

void loop()
{

}
