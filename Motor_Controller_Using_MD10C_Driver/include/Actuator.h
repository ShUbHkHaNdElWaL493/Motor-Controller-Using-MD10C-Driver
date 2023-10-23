#include <Arduino.h>

class actuator
{
  private:
  int motorPin1, motorPin2;
  public:
  actuator(int motorPin1, int motorPin2)
  {
    this->motorPin1 = motorPin1;
    this->motorPin2 = motorPin2;
  }
  void stop()
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  void rotateClockwise()
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
  void rotateAntiClockwise()
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
};

class actuator_enable
{
  private:
  int enablePin, motorPin1, motorPin2;
  public:
  actuator_enable(int enablePin, int motorPin1, int motorPin2)
  {
    this->enablePin = enablePin;
    this->motorPin1 = motorPin1;
    this->motorPin2 = motorPin2;
  }
  void stop()
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  void rotateClockwise(int speedPercentage)
  {
    analogWrite(enablePin, 255 * speedPercentage / 100);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
  void rotateAntiClockwise(int speedPercentage)
  {
    analogWrite(enablePin, 255 * speedPercentage / 100);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
};

class actuator_pwm
{
  private:
  int direction, pwm;
  public:
  actuator_pwm(int direction, int pwm)
  {
    this->direction = direction;
    this->pwm = pwm;
  }
  void stop()
  {
    analogWrite(pwm, 0);
  }
  void rotateClockwise(int speedPercentage)
  {
    digitalWrite(direction, HIGH);
    analogWrite(pwm, 255 * speedPercentage / 100);
  }
  void rotateAntiClockwise(int speedPercentage)
  {
    digitalWrite(direction, LOW);
    analogWrite(pwm, 255 * speedPercentage / 100);
  }
};