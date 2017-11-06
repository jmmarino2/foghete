class D_TCRT5000
{
  private:
    int Pin;

  public:
    D_TCRT5000(int pin) : Pin(pin) {}
      void Init(); 
      int Read();
};
