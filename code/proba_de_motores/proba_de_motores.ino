/*
   FOGHETE_TEST
   José Manuel Mariño Mariño
   v0.0
  
   Programado para ser implementado en un Arduino Nano V3 o equivalente
  
   AIN1: 7
   AIN2: 8
   APWM: 9
   BIN1: 12
   BIN2: 11
   BPWM: 10
 */

#include "foghete_test.h"
foghete_test Foghete(7,8,9,12,11,10);

void setup()
{
  Foghete.Init();
}

void loop()
{
  Foghete.Pasapadiante(50);
  delay(2000);
  Foghete.Pasapali(50);
  delay(2000);
  Foghete.Pasapatras(50);
  delay(2000);
  Foghete.Pasapala(50);
  delay(2000);
  Foghete.Shooo();
  delay(2000);
}
