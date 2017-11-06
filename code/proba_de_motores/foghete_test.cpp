
#include "foghete_test.h"

void foghete_test::Init()
{
  Maquinillo_E.Init();
  Maquinillo_D.Init();
}

//Pasapadiante hace avanzar el robot hacia adelante.
//Lume: Velocidad.

void foghete_test::Pasapadiante(int Lume)
{
  Maquinillo_E.Pasapadiante(Lume);
  Maquinillo_D.Pasapadiante(Lume);
}


//Pasapatras hace retroceder el robot hacia atras.
//Lume: Velocidad.

void foghete_test::Pasapatras(int Lume)
{
  Maquinillo_E.Pasapatras(Lume);
  Maquinillo_D.Pasapatras(Lume);
}


//Shooo hace detenerse al robot.

void foghete_test::Shooo()
{
  Maquinillo_E.Shooo();
  Maquinillo_D.Shooo();
}


//Pasapali hace girar al robot hacia la izquierda, pivotando sobre la rueda de ese lado.
//Lume: Velocidad motor derecho.

void foghete_test::Pasapali(int Lume)
{
  Maquinillo_E.Shooo();
  Maquinillo_D.Pasapadiante(Lume);
}


//Pasapala hace girar al robot hacia la derecha, pivotando sobre la rueda de ese lado.
//Lume: Velocidad motor izquierdo.

void foghete_test::Pasapala(int Lume)
{
  Maquinillo_E.Pasapadiante(Lume);
  Maquinillo_D.Shooo();
}

