#include "MeMCore.h"

MeRGBLed led(7, 7==7?2:4);

void setup() {
  Serial.begin(9600);
}

unsigned long startPoliceLights = millis();
bool changePoliceLights = 0;
  
void policeLights() {
  
  unsigned long period = millis() - startPoliceLights;
  
  Serial.println(period);
  
  if(period >= 1000) {
    if(changePoliceLights == 0) { 
      led.setColor(0, 254, 0, 0);
      led.setColor(1, 0, 0, 254);
      changePoliceLights = 1;
    }  else {
      led.setColor(0, 0, 0, 254);
      led.setColor(1, 254, 0, 0);    
      changePoliceLights = 0;
    }
    led.show();
    startPoliceLights = millis();
    
  }
}

void loop() {
  policeLights();
}
