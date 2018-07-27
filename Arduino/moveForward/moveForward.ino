#include "MeMCore.h"

MeLineFollower lineFinder(PORT_2); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

float MOTOR1_TUNE = -1.0;
float MOTOR2_TUNE = 1.0;

uint8_t motorSpeed = 100;
bool run = false;

void setup()
{
  pinMode(7, INPUT); //Define button pin as input
  while (analogRead(7) > 100) {
    delay(50); //Wait till button pressed to start.
  }
  run = true;
   bothMotorsRun();
    
//  buzzer.tone(200, 200);   //Buzzer beep to indicate start

  Serial.begin(9600);
  delay(2000);
}

void activateLeftMotor() {
   motor1.run(MOTOR1_TUNE*motorSpeed); /* value: between -255 and 255. */
}

void activateRightMotor() {
   motor2.run(MOTOR2_TUNE*motorSpeed); /* value: between -255 and 255. */
}

void stopLeftMotor() {
   motor1.stop();
}

void stopRightMotor() {
   motor2.stop();
}

void turnLeft() {
  activateLeftMotor();
  stopRightMotor();
}

void turnRight() {
  activateRightMotor();
  stopLeftMotor();
}


void bothMotorsRun() {
  activateRightMotor();
  activateLeftMotor();
 }

 void stopMotors() {
  stopRightMotor();
  stopLeftMotor();
 }

void loop()
{
      if(analogRead(7) <100) {
       run = !run;
       if(run==true) {
        stopMotors(); 
       } else {
        bothMotorsRun();
       }
    }

    delay(1000);
    

     
  
}
