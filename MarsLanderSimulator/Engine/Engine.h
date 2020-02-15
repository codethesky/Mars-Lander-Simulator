// Created by: Marla Carrier, Skyler Howard
#pragma once
#include "Roll.h"
#include "Axial.h"
#include "../Control.h"

class Engine
{
public:
	Engine();
	~Engine();
	void getEngineData(Lander*);
	virtual void setThrust(double amt);
	virtual double getThrust();

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