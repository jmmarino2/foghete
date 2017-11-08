/*
   FOGHETE_ITS_ALIVE
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
 */


void setup() 
{
  //Configuramos los pines de los sensores como entrada.
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);

  //Configuramos los pines del driver de motores como salida.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  //Ordenamos el avance de ambos motores.
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);

  //Establecemos una velocidad baja.
  analogWrite(9, 50);
  analogWrite(10, 50);
}

void loop() 
{
} 
