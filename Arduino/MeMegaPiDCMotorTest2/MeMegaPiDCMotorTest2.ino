/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    MeMegaPiDCMotorTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2016/05/17
 * @brief   Description: this file is sample code for MegaPi DC motor device.
 *
 * Function List:
 *    1. void MeMegaPiDCMotorTest::run(int16_t speed)
 *    2. void MeMegaPiDCMotorTest::stop(void)
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2016/05/17    1.0.0          build the new
 * </pre>
 */
#include "MeMegaPi.h"

MeMegaPiDCMotor motor1(PORT1A);

MeMegaPiDCMotor motor2(PORT1B);

MeMegaPiDCMotor motor3(PORT2A);

MeMegaPiDCMotor motor4(PORT2B);

uint8_t motorSpeed = 250;

#define MOTOR_TUNE 1

void setup()
{
  moveFwd();
  delay(1000);
  turnLeft();
  delay(1000);
  moveFwd();
  delay(1000);
  stop();
  delay(1000);
}

void moveFwd() {
  motor1.run(-MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  motor2.run(-MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  motor3.run(MOTOR_TUNE * motorSpeed);
  motor4.run(MOTOR_TUNE * motorSpeed);
}

void moveBack() {
  motor1.run(MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  motor2.run(MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  motor3.run(-MOTOR_TUNE * motorSpeed);
  motor4.run(-MOTOR_TUNE * motorSpeed);
}

void turnLeft() {
  motor1.run(MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  motor2.run(MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  //motor3.run(-MOTOR_TUNE * motorSpeed);
  //motor4.run(MOTOR_TUNE * motorSpeed);
}

void turnRight() {
  //motor1.run(MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  //motor2.run(-MOTOR_TUNE * motorSpeed); /* value: between -255 and 255. */
  motor3.run(-MOTOR_TUNE * motorSpeed);
  motor4.run(-MOTOR_TUNE * motorSpeed);
}


void stop() {
  motor1.stop();
  motor2.stop();
  motor3.stop();
  motor4.stop();
}

void loop()
{
  
  
//  delay(100);
//  motor1.run(-motorSpeed);
//  motor2.run(-motorSpeed);
//  motor3.run(-motorSpeed);
//  motor4.run(-motorSpeed);
//  delay(2000);
//  motor1.stop();
//  motor2.stop();
//  motor3.stop();
//  motor4.stop();
//  delay(2000);
}
