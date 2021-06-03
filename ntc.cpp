#include "ntc.h"

Ntc::Ntc(int TermistorPin)
{
  pinMode(TermistorPin,INPUT);
  beta=(log(RT1/RT2))/((1/T1)-(1/T2));
  Rinf=R0*exp(-beta/T0);
}

float Ntc::TemperatureCalc(int TermistorPin,float *TempResult){
  Vout=Vin*((float)(analogRead(TermistorPin))/1024.0); // calc for ntc value
  Rout=(Rt*Vout/(Vin-Vout));

  TempK=(beta/log(Rout/Rinf)); // calc for temperature value
  TempC=TempK-273.15;
  *TempResult=TempC;
}
