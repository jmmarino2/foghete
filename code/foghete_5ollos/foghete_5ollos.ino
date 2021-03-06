/*
   FOGHETE_2OLLOS
   José Manuel Mariño Mariño
   v0.0
  
   Programado para ser implementado en un Arduino Nano V3 o equivalente
  
   //ASIGNACION PINES SENSORES
   LEFT:     6
   MIDLEFT:  5
   CENTER:   4
   MIDRIGHT: 3
   RIGHT:    2
   //ASIGNACION PINES PARA DRIVER TB6612FNG
   AIN1: 7
   AIN2: 8
   APWM: 9
   BIN1: 12
   BIN2: 11
   BPWM: 10
 
   //ASIGNACION PINES PARA SELECCION VELOCIDAD
   SPD: A0 
 
 */

#include "foghete.h"
foghete Foghete(6, 5, 4, 3, 2, 7, 8, 9, 12, 11, 10);

void setup() 
{
  Foghete.Init();
}

void loop() 
{
  //Pasamos como parametro las velocidades de ambos motores, por separado para poder compensar diferencias.
  Foghete.Go(95, 100);
  //Foghete.Go(110, 120); //Este parece ser el limite de adherencia de las ruedas sobre papel, CON gomas.
  //Foghete.Go(100, 105); //Este parece ser el limite de adherencia de las ruedas sobre papel, sin gomas.
} 

