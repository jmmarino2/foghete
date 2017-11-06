// La clase maquinillo abstrae el funcionamiento de la mitad de un TB6612FNG.
//
// PINES DE CONTROL DEL TB6612FNG:
// IN1, IN2: Seleccionan el giro del motor (CW, CCW, STOP).
// Pwm: Selecciona la velocidad.

class maquinillo
{
  private:
  int IN1;
  int IN2;
  int Pwm;
 
  public:
  maquinillo(int in1, int in2, int pwm)
   {
   IN1 = in1;
   IN2 = in2;
   Pwm = pwm;
   }
  void Init();
  void Pasapadiante(int Lume);
  void Pasapatras(int Lume);
  void Shooo();
};
