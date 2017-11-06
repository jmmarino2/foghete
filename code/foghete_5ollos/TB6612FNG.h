class TB6612FNG
{
  private:
    int IN1;
    int IN2;
    int Pwm;
 
  public:
    TB6612FNG(int in1,int in2,int pwm) : IN1(in1), IN2(in2), Pwm(pwm) {}
    void Init();
    void Go(int spd);
    void Back(int spd);
    void Stop();
};
