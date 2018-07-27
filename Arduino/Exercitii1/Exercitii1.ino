#include "MeMCore.h"
#define SPEED 150

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeLineFollower lineFinder(PORT_2); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */

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
  motor1.run(SPEED);
  motor2.run(SPEED);
}

void rotateLeft() {
  motor1.run(-SPEED);
  motor2.run(-SPEED);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Am pornit programul!");
}

void loop() {  
   int sensorState = lineFinder.readSensors();
 
   if(sensorState == S1_IN_S2_IN) {
      Serial.println("Sensor 1 and 2 are inside of black line"); 
      moveForward();
      lastMove = 1;
   } else if (sensorState == S1_IN_S2_OUT) {
      Serial.println("Sensor 2 is outside of black line");
      rotateRight();
      lastMove = 3;
   } else if(sensorState == S1_OUT_S2_IN) {
      Serial.println("Sensor 1 is outside of black line");
      rotateLeft();
      lastMove = 2;
   } else if(sensorState == S1_OUT_S2_OUT) {
      Serial.println("Sensor 1 and 2 are outside of black line");
      if(lastMove == 1) {
        moveForward();
      } else if(lastMove == 2) {
        rotateLeft();
      } else if(lastMove == 3) {
        rotateRight();
      }
   }
}
