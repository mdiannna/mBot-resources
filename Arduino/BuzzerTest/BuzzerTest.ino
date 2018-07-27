#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeRGBLed led(7, 7==7?2:4);

MeBuzzer buzzer;

/***************************
 * Buzzer
 ***************************/

 uint8_t startTone = millis();
bool startToneFlag = true;

void buzzerTone(uint16_t frequency, uint32_t duration)
{
  int buzzer_pin = 8;
  int period = 1000000L / frequency;
  int pulse = period / 2;
  
  pinMode(buzzer_pin, OUTPUT);
  
  if(millis()-startTone>=duration) {
    if(startToneFlag==true) {
      digitalWrite(buzzer_pin, HIGH);
    } else {
      digitalWrite(buzzer_pin, LOW);
//      wdt_reset();
    }
    startTone = millis();
    startToneFlag = !startToneFlag;
  }
  // for (long i = 0; i < duration * 1000L; i += period) 
  // {
  //   delayMicroseconds(pulse);
  //   delayMicroseconds(pulse);
  //   wdt_reset();
  // }
}
//void playSound() {
//  buzzer_pin = 8;
//}
//
//void stopSound() {
//  
//}
//
////Echivalent cu
////buzzer.tone(262,5); 
//buzzerTone() {
//}
//
////Echivalent cu
////buzzer.noTone();
//buzzerNoTone() {
//  
//}

//buzzer_pin = 8;
 
void setup() {
//  784, 587
  buzzerTone(784, 2);

  buzzerTone(587, 100);
  
//  Serial.begin(9600);
//
//  ledState = DEVICE_OFF;
//  buzzerState = DEVICE_OFF;
//
//  ledDuration  = 1000; // 1 second
//  buzzerDuration   = 2000; // 2 seconds
//
//  // set the initial LED timer value
//  ledTimer = buzzerTimer = millis();

}

void loop() {
 buzzerTone(784, 4);

  buzzerTone(587, 1002);

 }
