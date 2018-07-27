#include "MeOrion.h"

// brat robotic - pe port 1
MeDCMotor brat(PORT_1);
// motoare
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

uint8_t motorSpeed = 100;

void sus() {
  brat.run(-motorSpeed); /* valori: intre -255 si 255. */
  delay(4000);
  brat.stop();
}

void jos(){
  brat.run(motorSpeed); /* valori: intre -255 si 255. */
  delay(1000);
  brat.stop();
}

void moveFwd() {
    motor1.run(-motorSpeed); /* valori: intre -255 si 255. */
    motor2.run(motorSpeed); /* valori: intre -255 si 255. */
}

void moveBackward() {
    motor1.run(motorSpeed); /* valori: intre -255 si 255. */
    motor2.run(-motorSpeed); /* valori: intre -255 si 255. */
}
void stopMovement() {
  motor1.stop();
  motor2.stop();
}

// Initializare - actiunile se executa o singura data
void setup()
{
  moveFwd();
  delay(3000);
  stopMovement();
  delay(1000);
  jos();
  delay(2000);
  sus();
}

// Loop - instructiunile se repeta la infinit
void loop()
{
  
}
