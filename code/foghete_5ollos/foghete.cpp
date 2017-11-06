#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "foghete.h"

void foghete::Init()
{
  LSensor.Init();
  MLSensor.Init();
  CSensor.Init();
  MRSensor.Init();
  RSensor.Init();
  LMotor.Init();
  RMotor.Init();
}


void foghete::Go(int lspeed, int rspeed)
{
  int sensor;
  sensor = LSensor.Read();
  sensor = (sensor << 1 ) + MLSensor.Read();
  sensor = (sensor << 1 ) + CSensor.Read();
  sensor = (sensor << 1 ) + MRSensor.Read();
  sensor = (sensor << 1 ) + RSensor.Read();
  
  switch (sensor) {
     case 1: //00001
      //Si detectamos linea en el sensor extremo derecho...
      //... debemos girar MUCHO a la derecha (retrocedemos ligeramente con la rueda derecha).
      LMotor.Go(lspeed);
      RMotor.Back(rspeed/2);
      break;
    case 3: //00011
      //Si detectamos linea entre los dos sensores derechos...
      //... debemos girar a la derecha (pivotamos sobre la rueda derecha).
      LMotor.Go(lspeed);
      RMotor.Stop();
      break;
    case 2: //00010
      //Si detectamos linea en el sensor centro derecho...
      //... debemos girar MUY POCO a la derecha (avanzamos a media velocidad con la rueda derecha).
      LMotor.Go(lspeed);
      RMotor.Go(rspeed * 0.33);
      break;
    case 6: //00110
      //Si detectamos linea en el sensor central y centro derecho...
      //... debemos girar POCO a la derecha (avanzamos a media velocidad con la rueda derecha).
      LMotor.Go(lspeed);
      RMotor.Go(rspeed * 0.66);
      break;
    case 4: //00100
      //Si detectamos linea en el sensor central...
      //... debemos seguir adelante.
      LMotor.Go(lspeed);
      RMotor.Go(rspeed);
      break;
    case 12: //01100
      //Si detectamos linea en el sensor central y centro izquierdo...
      //... debemos girar POCO a la izquierda (avanzamos a media velocidad con la rueda izquierda).
      LMotor.Go(lspeed * 0.66);
      RMotor.Go(rspeed);
      break;
    case 8: //01000
      //Si detectamos linea en el sensor centro izquierdo...
      //... debemos girar MUY POCO a la izquierda (avanzamos a media velocidad con la rueda izquierda).
      LMotor.Go(lspeed * 0.33);
      RMotor.Go(rspeed);
      break;
    case 24: //11000
      //Si detectamos linea entre los dos sensores izquierdos...
      //... debemos girar a la izquierda (pivotamos sobre la rueda izquierda).
      LMotor.Stop();
      RMotor.Go(rspeed);
      break;
    case 16: //10000
      //Si detectamos en el sensor extremo izquierdo...
      //... debemos girar MUCHO a la izquierda (retrocedemos ligeramente con la rueda izquierda).
      LMotor.Back(lspeed/2);
      RMotor.Go(rspeed);
      break;
    default:
      //En principio la intencion era poder detectar cuando habiamos perdido la linea.
      //Sin embargo, para poder hacer eso deberiamos estar seguros que por construccion, siempre habra algun sensor detectando linea
      //y que nunca se nos colara la linea entre dos sensores sin que la detecte ninguno de ellos.
      //Eso en nuestro chasis no es facil, por no contar con los agujeros necesarios.
      //Como no podemos asegurar que nunca se nos colara la linea entre dos sensores sin ser detectada,
      //no podemos programar una accion concreta para cuando supuestamente la hayamos perdido.
      //Asi que con 5 sensores conseguimos una mayor resolucion en las correcciones de la trayectoria, pero seguimos sin poder detectar cuando estamos perdidos.
      //La accion por defecto sigue siendo no hacer nada.
    break;
  }
  
}

