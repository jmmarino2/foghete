/*
   FOGHETE_2OLLOS
   José Manuel Mariño Mariño
   v0.0
  
   Programado para ser implementado en un Arduino Nano V3 o equivalente
  
   //ASIGNACION PINES SENSORES
   LEFT:     6
   MIDLEFT:  5  <<<< En la version 2ollos usamos estos dos.
   CENTER:   4
   MIDRIGHT: 3  <<<< En la version 2ollos usamos estos dos.
   RIGHT:    2
   //ASIGNACION PINES PARA DRIVER TB6612FNG
   AIN1: 7
   AIN2: 8
   APWM: 9
   BIN1: 12
   BIN2: 11
   BPWM: 10
 */

#include "foghete.h"
foghete Foghete(5, 3, 7, 8, 9, 12, 11, 10);

void setup() 
{
  Foghete.Init();
}

void loop() 
{
  //Pasamos como parametro las velocidades de ambos motores, por separado para poder compensar diferencias.
  Foghete.Go(85, 90);
} 
