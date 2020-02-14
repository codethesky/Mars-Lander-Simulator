// Created by: Marla Carrier, Skyler Howard
#include "Roll.h"
#include "Axial.h"
#include "../Control.h"

class Engine
{
public:
	Engine();
	~Engine();
	void getEngineData(Lander*);
	void setThrust(double amt);
	double getThrust();

protected:
	double thrust;
	const double POWER;

private:
	void calcRollEngine(Lander*);
	void calcAxialEngine(Lander*);
	/*Roll* rollOne;             // affects accelerometerX, gyroscopeX
	Roll* rollTwo;
	Roll* rollThree;
	Axial* axialOne;           // affects gyroscopeY, accelerometerY, gyroscopeZ, accelerometerZ negatively
	Axial* axialTwo;           // affects gyroscopeY, accelerometerY, gyroscopeZ, accelerometerZ positively
	Axial* axialThree;         // affects gyroscopeY, accelerometerY, gyrozcopeZ, accelerometerZ negatively */
};