#include <ModbusRtu.h>

SMS sm;

int LEDpin = 13;
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
  int ID = sm.Ping(0);
  if(ID!=-1){
    digitalWrite(LEDpin, LOW);
    Serial.print("slave ID:");
    Serial.println(ID, DEC);
    delay(10);
  }else{
    Serial.print("last error:");
    Serial.println(sm.getLastError());
    digitalWrite(LEDpin, HIGH);
    delay(2000);
  }
}
