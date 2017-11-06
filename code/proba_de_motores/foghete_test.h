#include "foghete_test_maquinillo.h"

class foghete_test
{  
  private:
  maquinillo Maquinillo_E;
  maquinillo Maquinillo_D;

  public:
  foghete_test(int AIN1, int AIN2, int PWMA, int BIN1, int BIN2, int PWMB) : Maquinillo_E(AIN1, AIN2, PWMA), Maquinillo_D(BIN1, BIN2, PWMB) {}
  void Init();
  void Pasapadiante(int Lume);
  void Pasapatras(int Lume);
  void Pasapali(int Lume);
  void Pasapala(int Lume);
  void Shooo();
};
