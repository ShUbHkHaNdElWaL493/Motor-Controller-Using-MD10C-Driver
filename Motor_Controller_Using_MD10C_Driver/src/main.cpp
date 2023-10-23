#include <Arduino.h>
#include "Actuator.h"

//Input pins for the actuator
#define Direction 10
#define PWM 9

actuator_pwm Actuator1(Direction, PWM);

void setup() {
  // put your setup code here, to run once:
  pinMode(Direction,OUTPUT);
  pinMode(PWM,OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter a value.\n");
  while (Serial.available())
  {}
  int input = Serial.parseInt();
  if (input > 0)
  {
    Actuator1.rotateAntiClockwise(50);
  } else if (input < 0)
  {
    Actuator1.rotateClockwise(50);
  } else
  {
    Actuator1.stop();
  }
  delay(5000);
}