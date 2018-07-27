/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    LineFollowerTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/09
 * @brief   Description: this file is sample code for Me line follower module.
 *
 * Function List:
 * 1. uint8_t MeLineFollower::readSensors(void)
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/09/09    1.0.0            Rebuild the old lib.
 * </pre>
 */
#include "MeMCore.h"

MeLineFollower lineFinder(PORT_2); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

float MOTOR1_TUNE = -1.0;
float MOTOR2_TUNE = 1.0;

uint8_t motorSpeed = 100;

bool prev_move_left = false;
bool prev_move_fwd = true;

void setup()
{
  //led.setpin(13);
  pinMode(7, INPUT); //Define button pin as input
  while (analogRead(7) > 100) {
    delay(50); //Wait till button pressed to start.
  }
//  buzzer.tone(200, 200);   //Buzzer beep to indicate start

  Serial.begin(9600);
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

void loop()
{
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: 
      Serial.println("Sensor 1 and 2 are inside of black line"); 
      bothMotorsRun();
      prev_move_left = false;
      prev_move_fwd = true;
      break;
    
    case S1_IN_S2_OUT: 
      Serial.println("Sensor 2 is outside of black line");
      turnRight();
      prev_move_left = false;
      prev_move_fwd = false;
      break;
      
    case S1_OUT_S2_IN: 
      Serial.println("Sensor 2 is outside of black line"); 
      prev_move_left = true;
      prev_move_fwd = false;
      turnLeft();
      break;
    
    case S1_OUT_S2_OUT: 
      if(prev_move_fwd) {
        bothMotorsRun();
      }
      else if(prev_move_left) {
        turnLeft();
      } else {
        turnRight();
      } 
      
      Serial.println("Sensor 1 and 2 are outside of black line"); 
      break;
    
    default: break;
  }
//  delay(100);
}
