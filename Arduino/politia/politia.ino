#define SPEED 100
#define P_HIGH NOTE_G5
#define P_LOW NOTE_D5
//#define ARDUINO 99


#include "MeMCore.h"
#include <Tone.h>



Tone player; 



MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeLineFollower lineFinder(PORT_2);
MeRGBLed rgbled_7(7, 7 == 7 ? 2 : 4);
MeBuzzer buzzer;

int lastMove = 1;

void moveForward() {
  motor1.run(-SPEED);
  motor2.run(SPEED);
}

void stopMotors() {
  motor1.stop();
  motor2.stop();
}

void rotateRight() {
  motor1.run(80);
  motor2.run(80);
}

void rotateLeft() {
  motor1.run(-80);
  motor2.run(-80);
}

void moveBack () {
  motor1.run(SPEED);
  motor2.run(-SPEED);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Am pornit programul!");
   player.begin(8);

}

void lineFollow() {

  int sensorState = lineFinder.readSensors();
  if (sensorState == S1_OUT_S2_OUT) {
    Serial.println("Sensor 1 and 2 are inside of black line");
    moveForward();
    lastMove = 1;
  } else if (sensorState == S1_OUT_S2_IN) {
    Serial.println("Sensor 2 is outside of black line");
    rotateRight();
    lastMove = 3;

  } else if (sensorState == S1_IN_S2_OUT) {
    Serial.println("Sensor 1 is outside of black line");

    rotateLeft();
    lastMove = 2;
  } else if (sensorState == S1_IN_S2_IN) {
    Serial.println("Sensor 1 and 2 are outside of black line");
    if (lastMove == 1) {
      moveForward();
    } else if (lastMove == 2) {
      rotateLeft();
    } else if (lastMove == 3) {
      rotateRight();
    }
  }
}


  
void ledPolice() {
  rgbled_7.setColor(1, 255, 0, 0);
  rgbled_7.setColor(2, 0, 0, 255);
  rgbled_7.show();
  player.play(P_HIGH);
 
  _delay(0.3);
  rgbled_7.setColor(1, 0, 0, 255);
  rgbled_7.setColor(2, 255, 0, 0);
  rgbled_7.show();
   player.play(P_LOW);
 
  _delay(0.3);
}

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while (millis() < endTime)_loop();
}

void _loop() {
}

void soundPolice() {

}
void loop() {
  lineFollow();
  ledPolice();
  //delay(50);
}
