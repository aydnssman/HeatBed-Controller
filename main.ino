#include "ntc.h"

Ntc termistor1(Termistor1pin);
Ntc termistor2(Termistor2pin);
Ntc termistor3(Termistor3pin);
Ntc termistor4(Termistor4pin);
Ntc termistor5(Termistor5pin);

float TempResultSensor1,TempResultSensor2,TempResultSensor3,TempResultSensor4,TempResultSensor5;

void setup() {
Serial.begin(9600);
}

void loop() {
  TempResultSensor1=termistor1.TemperatureCalc(Termistor1pin,&TempResultSensor1);
  TempResultSensor2=termistor2.TemperatureCalc(Termistor2pin,&TempResultSensor2);
  TempResultSensor3=termistor3.TemperatureCalc(Termistor3pin,&TempResultSensor3);
  TempResultSensor4=termistor4.TemperatureCalc(Termistor4pin,&TempResultSensor4);
  TempResultSensor5=termistor5.TemperatureCalc(Termistor5pin,&TempResultSensor5);

  Serial.print(TempResultSensor1);Serial.print(",");
  Serial.print(TempResultSensor2);Serial.print(",");
  Serial.print(TempResultSensor3);Serial.print(",");
  Serial.print(TempResultSensor4);Serial.print(",");
  Serial.println(TempResultSensor5);
}
