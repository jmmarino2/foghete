#include "TB6612FNG.h"
#include "TCRT5000.h"

class foghete
{
private:
        D_TCRT5000 LSensor;
        D_TCRT5000 MLSensor;
        D_TCRT5000 CSensor;
        D_TCRT5000 MRSensor;
        D_TCRT5000 RSensor;
        TB6612FNG LMotor;
        TB6612FNG RMotor;

public:
	foghete(  int ls,
                  int mls,
                  int cs,
                  int mrs,
                  int rs,
                  int ain1,
                  int ain2,
                  int apwm,
                  int bin1,
                  int bin2,
                  int bpwm) : LSensor(ls), MLSensor(mls), CSensor(cs), MRSensor(mrs), RSensor(rs), LMotor(ain1, ain2, apwm), RMotor(bin1, bin2, bpwm) {}
	
	void Init();
        float foghete::Read_Error(float prev_err);
        void Go(int KP, int KI, int KD, int lspeed, int rspeed);
}; 
