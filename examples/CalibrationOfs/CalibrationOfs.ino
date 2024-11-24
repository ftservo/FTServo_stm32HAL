#include <ModbusRtu.h>

int LEDpin = 13;
SMS sm;

void setup()
{
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin, HIGH);
  sm.begin(&Serial1, 115200); // baud-rate at 115200
  sm.setTimeOut(100); // if there is no answer in 100 ms, roll over
  Serial.begin(115200);
  delay(1000);
}

void loop()
{  
  digitalWrite(LEDpin, LOW);
  sm.CalibrationOfs(1);
  digitalWrite(LEDpin, HIGH);
  while(1);
}
