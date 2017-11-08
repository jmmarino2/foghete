#include <Arduino.h> //Permite utilizar los comandos de Arduino
#include "foghete.h"

void foghete::Init()
{
  LSensor.Init();
  MLSensor.Init();
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
  sensor = (sensor << 1 ) + MRSensor.Read();
  sensor = (sensor << 1 ) + RSensor.Read();
  
  switch (sensor) {
    case 1: //0001
      //Si detectamos linea en el sensor extremo derecho...
      //... debemos girar MUCHO a la derecha (retrocedemos ligeramente con la rueda derecha).
      LMotor.Go(lspeed);
      RMotor.Back(rspeed/2);
      break;
    case 3: //0011
      //Si detectamos linea entre los dos sensores derechos...
      //... debemos girar a la derecha (pivotamos sobre la rueda derecha).
      LMotor.Go(lspeed);
      RMotor.Stop();
      break;
    case 2: //0010
      //Si detectamos linea en el sensor centro derecho...
      //... debemos girar POCO a la derecha (avanzamos a media velocidad con la rueda derecha).
      LMotor.Go(lspeed);
      RMotor.Go(rspeed/2);
      break;
    case 6: //0110
      //Si detectamos linea en los dos sensores centrales...
      //... debemos seguir adelante.
      LMotor.Go(lspeed);
      RMotor.Go(rspeed);
      break;
    case 4: //0100
      //Si detectamos linea en el sensor centro izquierdo...
      //... debemos girar POCO a la izquierda (avanzamos a media velocidad con la rueda izquierda).
      LMotor.Go(lspeed/2);
      RMotor.Go(rspeed);
      break;
    case 12: //1100
      //Si detectamos linea entre los dos sensores izquierdos...
      //... debemos girar a la izquierda (pivotamos sobre la rueda izquierda).
      LMotor.Stop();
      RMotor.Go(rspeed);
      break;
    case 8: //1000
      //Si detectamos en el sensor extremo izquierdo...
      //... debemos girar MUCHO a la izquierda (retrocedemos ligeramente con la rueda izquierda).
      LMotor.Back(lspeed/2);
      RMotor.Go(rspeed);
      break;
    default:
      //La accion por defecto es no hacer nada, con lo que sigue vigente la ultima orden que hayamos dado a los motores.
    break;
  }
  
}

