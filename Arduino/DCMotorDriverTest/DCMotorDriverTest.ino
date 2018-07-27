#include "MeMCore.h"

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

uint8_t motorSpeed = 100;
int ADJUST_MOTOR_LEFT = -1;
int ADJUST_MOTOR_RIGHT = 1.7;


void setup(){   
  motor1.run(ADJUST_MOTOR_LEFT * motorSpeed); /* value: between -255 and 255. */  
  motor2.run(ADJUST_MOTOR_RIGHT * motorSpeed); /* value: between -255 and 255. */   
  delay(2000);   
  motor1.stop();  
  motor2.stop();}

  
void loop(){
}
