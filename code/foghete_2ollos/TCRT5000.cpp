#include <Arduino.h>
#include "TCRT5000.h"

void D_TCRT5000::Init()
{
  pinMode(Pin, INPUT);
}

int D_TCRT5000::Read()
{
  return digitalRead(Pin);
}

