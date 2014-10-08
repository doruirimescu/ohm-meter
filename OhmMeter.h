/*
  OhmMeter.h v.1.0 - Resistance measuring library for arduino
  2014 Doru Irimescu 

*/

// ensure this library description is only included once
#ifndef OhmMeter_h
#define OhmMeter_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// library interface description
class OhmMeter
{
  // user-accessible "public" interface
  public:
  OhmMeter();
  void calculateResistance(short pin_number,float Rk);
	
  // library-accessible "private" interface
  private:
  // variables
  int val; // variable used to store the value coming from reading analog input
  float resistance,voltage_read,average_resistance,old_value; //other values used in calculating the resistance

};

#endif
