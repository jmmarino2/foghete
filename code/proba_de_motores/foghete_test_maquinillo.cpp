#include <Arduino.h>
#include "foghete_test_maquinillo.h"

// La clase maquinillo abstrae el funcionamiento de la mitad de un TB6612FNG.
//
// PINES DE CONTROL DEL TB6612FNG:
// IN1, IN2: Seleccionan el giro del motor (CW, CCW, STOP).
// Pwm: Selecciona la velocidad.
//
// IN1  IN2  GIRO
// LOW  HIGH CW
// HIGH LOW  CCW
// LOW  LOW  STOP
//
// Pwm: Acepta todo el rango de las salidas PWM del Arduino: 0..255


void maquinillo::Init()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(Pwm, OUTPUT);
}

void maquinillo::Pasapadiante(int Lume)
{
  analogWrite(Pwm, Lume);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void maquinillo::Pasapatras(int Lume)
{
  analogWrite(Pwm, Lume);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void maquinillo::Shooo()
{
  analogWrite(Pwm, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
