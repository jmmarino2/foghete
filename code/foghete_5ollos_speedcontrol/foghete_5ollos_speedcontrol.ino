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

//El pin donde leeremos la velocidad es el A7.
const int speed_pin = 7;

int set;
int lset;
int rset;

//Aqui guardamos el ajuste de velocidades.
//speed_adjust sera la velocidad a sumar a la rueda derecha.
//speed_adjust > 0 significa que la derecha debe correr un poco mas.
//speed_adjust < 0 significa que la izquierda debe correr un poco mas.
int speed_adjust = 5;


void setup() 
{
  Foghete.Init();
  
  //Leemos la velocidad.
  set = analogRead(speed_pin);
  //El fondo escala depende del ajuste de velocidades porque luego hay que sumarlo para la rueda derecha.
  lset = map( set, 0, 1023, 0, (255-speed_adjust) );
  //Establecemos la velocidad de la otra rueda con el ajuste necesario para
  //compensar la diferencia entre motores.
  rset = lset + speed_adjust;
}


void loop() 
{
  //Pasamos como parametro las velocidades de ambos motores, por separado para poder compensar diferencias.
  Foghete.Go(lset, rset);
  //Foghete.Go(110, 120); //Este parece ser el limite de adherencia de las ruedas sobre papel, CON gomas.
  //Foghete.Go(100, 105); //Este parece ser el limite de adherencia de las ruedas sobre papel, sin gomas.
} 
