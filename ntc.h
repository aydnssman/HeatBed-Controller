#ifndef ntc_h
#define ntc_h

#define Termistor1pin 0
#define Termistor2pin 1
#define Termistor3pin 2
#define Termistor4pin 3
#define Termistor5pin 4

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Ntc 
{
private:
  float Vin=5.0;     // [V]        
  float Rt=10000;    // Resistor t [ohm]
  float R0=100000;   // value of rct in T0 [ohm]
  float T0=298.15;   // use T0 in Kelvin [K]
  float Vout=0.0;    // Vout in A0 
  float Rout=0.0;    // Rout in A0
                     // use the datasheet to get this data.
  float T1=273.15;   // [K] in datasheet 0º C
  float T2=373.15;   // [K] in datasheet 100° C
  float RT1=35563;   // [ohms]  resistence in T1
  float RT2=549;     // [ohms]   resistence in T2
  float beta=0.0;    // initial parameters [K]
  float Rinf=0.0;    // initial parameters [ohm]   
  float TempK=0.0;   // variable output
  float TempC=0.0;   // variable output
  
public: 
  Ntc(int TermistorPin);
  float TemperatureCalc(int TermistorPin,float *TermistorResult);
};

#endif
