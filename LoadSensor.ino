#include "HX711.h"

#define LOADCELL_DOUT_PIN  6
#define LOADCELL_SCK_PIN  5

HX711 scale;
float calibration_factor = -7050; //-7050 worked for my 440lb max scale setup

void LoadSensorsetup() {
  Serial.begin(9600);  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(); //setscale
  scale.tare(); //Reset the scale to 0
}

void LoadSensorloop() {
  
  delay(1000);
  Serial.println(scale.get_units());  //getscale
  //delay(1000);
}
