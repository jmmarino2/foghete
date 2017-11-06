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


float foghete::Read_Error(float prev_err)
{
  int sensor;
  float error;
  
  sensor = LSensor.Read();
  sensor = (sensor << 1 ) + MLSensor.Read();
  sensor = (sensor << 1 ) + CSensor.Read();
  sensor = (sensor << 1 ) + MRSensor.Read();
  sensor = (sensor << 1 ) + RSensor.Read();

  switch (sensor) {
    case 1: //00001 - Si detectamos linea en el sensor extremo derecho...
      error = 4;
      break;
    case 3: //00011 - Si detectamos linea entre los dos sensores derechos...
      error = 3;
      break;
    case 2: //00010 - Si detectamos linea en el sensor centro derecho...
      error = 2;
      break;
    case 6: //00110 - Si detectamos linea en el sensor central y centro derecho...
      error = 1;
      break;
    case 4: //00100 - Si detectamos linea en el sensor central...
      error = 0;
      break;
    case 12: //01100 - Si detectamos linea en el sensor central y centro izquierdo...
      error = -1;
      break;
    case 8: //01000 - Si detectamos linea en el sensor centro izquierdo...
      error = -2;
      break;
    case 24: //11000 - Si detectamos linea entre los dos sensores izquierdos...
      error = -3;
      break;
    case 16: //10000 - Si detectamos en el sensor extremo izquierdo...
      error = -4;
      break;
    default: //En cualquier otro caso, devolveremos como lectura de error el valor previo de error que se ha pasado en la llamada.
      error = prev_error;
    break;
  }
}


void foghete::Go(int KP, int KI, int KD, int lspeed, int rspeed)
{
    int max_lspeed = lspeed;
    int max_rspeed = rspeed;
    
    float error = 0;
    float P = 0;
    float I = 0;
    float D = 0;
    float PID = 0;
    float prev_err = 0;
    float prev_I = 0;

    //Pasamos el error actual a la funcion Read_Error, para que lo devuelva si los sensores dan una lectura erronea.
    //El parametro P sera igual al error.
    P = Read_Error(error);
    //El parametro I sera la integral, esto es, la suma acumulada de errores.
    I = I + error;
    //El parametro D sera la derivada, esto es, la diferencia entre el error actual y el error anterior.
    D = P - error;
    
    //Ya podemos almacenar el nuevo error para la siguiente iteracion.
    error = P;
    
    PID = (KP*P) + (KI*I) + (KD*D);
    
    //Hemos adoptado el convenio de que el error es positivo hacia la derecha (los sensores de la derecha son positivos y los de la izquierda negativos).
    //Entonces el error debemos sumarlo al motor izquierdo, y restarlo en el motor derecho.
    int lspeed = lspeed + PID;
    int rspeed = rspeed - PID;

    //Limitamos la velocidad entre cero y nuestro maximo.
    constrain(lspeed,0,max_lspeed);
    constrain(rspeed,0,max_rspeed);
    
    LMotor.Go(lspeed);
    RMotor.Go(rspeed);
    }


