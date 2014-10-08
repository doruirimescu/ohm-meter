/*

 */

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

#include "OhmMeter.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

OhmMeter::OhmMeter()
{
	old_value=500000;
	val = 0;

}

// Public Methods //////////////////////////////////////////////////////////////

void OhmMeter::calculateResistance(short pin_number,float Rk)
{
	  val = analogRead(pin_number);
	  voltage_read=val*0.004882812; //convert the 0 to 1023 reading into voltage
	  resistance= (5.0 * (Rk/voltage_read)) - Rk;
	  average_resistance=0.0;
	  old_value=500000;   
	  if(resistance<300000.0)
	  {
	    int counter=0;
	    while(resistance<300000.0 )
	    {
	      if(resistance<old_value)
	      {
	        counter++;
	        average_resistance=average_resistance+resistance;
	        old_value=resistance;
	        delay(10);
	        val = analogRead(pin_number);
	        voltage_read=val*0.004882812;
	        resistance=(5.0 * (Rk/voltage_read)) - Rk;
	      }
	      else
	      {
	        delay(10);
	        val = analogRead(pin_number);
	        voltage_read=val*0.004882812;
	        resistance=(5.0 * (Rk/voltage_read)) - Rk;
	      } 
	    }
	    average_resistance=average_resistance/counter;
	    
	    if(average_resistance<1000.0)
	    {
	      Serial.print("\nResistance: " );
	      Serial.print(average_resistance,3);
	      Serial.print("  Ohms" );
	    }
	    else
	    {
	      Serial.print("\nResistance: " );
	      Serial.print(average_resistance/1000.0,3);
	      Serial.print("  KiloOhms" );
	    }
	  }
}

