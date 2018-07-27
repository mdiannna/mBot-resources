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
//#include "MeOrion.h"
#include "MeMCore.h"

MeLineFollower lineFinder(PORT_2); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

float MOTOR1_TUNE = -1.0;
float MOTOR2_TUNE = 1.0;

uint8_t motorSpeed = 100;

bool prev_move_left = true;

void setup()
{
  Serial.begin(9600);
}

void activateLeftMotor() {
   motor1.run(-motorSpeed); /* value: between -255 and 255. */
}

void activateRightMotor() {
   motor2.run(motorSpeed); /* value: between -255 and 255. */
}

void stopLeftMotor() {
   motor1.stop();
}

void stopRightMotor() {
   motor2.stop();
}

void leftMotorRunDistance(int distance) {
  activateLeftMotor();
  delay(distance);
  stopLeftMotor();
}

void rightMotorRunDistance(int distance) {
  activateRightMotor();
  delay(distance);
  stopRightMotor();
}

void turnLeft() {
  activateLeftMotor();
  stopRightMotor();
}

void turnRight() {
  activateRightMotor();
  stopLeftMotor();
}

void bothMotorsRunDistance(int distance) {
  activateRightMotor();
  activateLeftMotor();
  delay(distance);
  stopRightMotor();
  stopLeftMotor();
}

void bothMotorsRunDistanceNoStop() {
  activateRightMotor();
  activateLeftMotor();
 // delay(distance);
  //stopRightMotor();
  //stopLeftMotor();
}

void loop()
{
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN: 
      Serial.println("Sensor 1 and 2 are inside of black line"); 
      bothMotorsRunDistanceNoStop(); //500ms
      break;
    
    case S1_IN_S2_OUT: 
     
      Serial.println("Sensor 2 is outside of black line");
      turnRight();
      prev_move_left = false;
      break;
    case S1_OUT_S2_IN: 
      Serial.println("Sensor 2 is outside of black line"); 
      prev_move_left = true;
      turnLeft();
      break;
    case S1_OUT_S2_OUT: 
      //stopLeftMotor();
      //stopRightMotor();
      if(prev_move_left) {
        turnLeft();
      } else {
        turnRight();
      } 
      
      Serial.println("Sensor 1 and 2 are outside of black line"); 
      //leftMotorRunDistance(200); //300ms
     // bothMotorsRunDistance(300); //500ms
      break;
    default: break;
  }
//  delay(100);
}
