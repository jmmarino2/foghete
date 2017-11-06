#include "TB6612FNG.h"
#include "TCRT5000.h"

class foghete
{
private:
        D_TCRT5000 LSensor;
        D_TCRT5000 RSensor;
        TB6612FNG LMotor;
        TB6612FNG RMotor;

public:
	foghete(  int ls,
                  int rs,
                  int ain1,
                  int ain2,
                  int apwm,
                  int bin1,
                  int bin2,
                  int bpwm) : LSensor(ls), RSensor(rs), LMotor(ain1, ain2, apwm), RMotor(bin1, bin2, bpwm) {}
	
	void Init();
	void Go(int lspeed, int rspeed);
}; 
