#include <OhmMeter.h>

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  OhmMeter ohm; //create an OhmMeter object
  ohm.calculateResistance(0,1000.0); //calculate the resistance measured,with analog input 0 and 1k resistor.To calculate resistances bigger than 50K,
                                    //check the fritzing schematic (OhmMeter.fzz) and change the 1K resistor with some bigger value.The maximum resistance to be measured is 300000,but that value can be changed from the .cpp file

  delay(200);
}

