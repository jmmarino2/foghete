#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "TB6612FNG.h"

void TB6612FNG::Init()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(Pwm, OUTPUT);
}

void TB6612FNG::Go(int spd)
{
  analogWrite(Pwm, spd);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void TB6612FNG::Back(int spd)
{
  analogWrite(Pwm, spd);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void TB6612FNG::Stop()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}
