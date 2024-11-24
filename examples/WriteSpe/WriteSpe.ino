#include <ModbusRtu.h>

SMS sm;

void setup()
{
  sm.begin(&Serial1, 115200); // baud-rate at 115200
  sm.setTimeOut(100); // if there is no answer in 100 ms, roll over
  Serial.begin(115200);
  delay(1000);
  sm.wheelMode(1);
}

void loop()
{
  sm.WriteSpe(1, 80, 0);
  Serial.print("last error:");
  Serial.println(sm.getLastError());
  delay(6000);
  sm.WriteSpe(1, 0, 0);
  Serial.print("last error:");
  Serial.println(sm.getLastError());
  delay(6000);
  sm.WriteSpe(1, -80, 0);
  Serial.print("last error:");
  Serial.println(sm.getLastError());
  delay(6000);
  sm.WriteSpe(1, 0, 0);
  Serial.print("last error:");
  Serial.println(sm.getLastError());
  delay(6000);
}
