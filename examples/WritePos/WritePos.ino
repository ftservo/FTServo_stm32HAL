#include <ModbusRtu.h>

SMS sm;

void setup()
{
  sm.begin(&Serial1, 115200); // baud-rate at 115200
  sm.setTimeOut(100); // if there is no answer in 100 ms, roll over
  Serial.begin(115200);
  delay(1000);
}

void loop()
{
  sm.WritePos(1, 4095);//运行至P1=4095位置
  Serial.print("last error:");
  Serial.println(sm.getLastError());
  delay(2000);
  
  sm.WritePos(1, 0);//运行至P0=0位置
  Serial.print("last error:");
  Serial.println(sm.getLastError());
  delay(2000);
}
