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
  int Pos;
  int Speed;
  int Load;
  int Voltage;
  int Temper;
  int Move;
  int Current;
  sm.FeedBack(1);
  if(sm.getLastError()==0){
    digitalWrite(LEDpin, LOW);
    Pos = sm.ReadPos(-1);
    Speed = sm.ReadSpeed(-1);
    Load = sm.ReadLoad(-1);
    Voltage = sm.ReadVoltage(-1);
    Temper = sm.ReadTemper(-1);
    Move = sm.ReadMove(-1);
    Current = sm.ReadCurrent(-1);
    Serial.println(Pos);
    Serial.println(Speed);
    Serial.println(Load);
    Serial.println(Voltage);
    Serial.println(Temper);
    Serial.println(Move);
    Serial.println(Current);
    Serial.println();
    delay(10);
  }else{
    Serial.print("last error:");
    Serial.println(sm.getLastError());
    digitalWrite(LEDpin, HIGH);
    delay(2000);
  }
}
