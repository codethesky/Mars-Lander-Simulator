// Created by: Marla Carrier, Skyler Howard
#pragma once
#include "Roll.h"
#include "Axial.h"
#include "../Control.h"

struct Lander;     // forward declaration

class Engine
{
public:
	Engine();
	~Engine();
	void getEngineData(Lander* vehicle);

protected:


private:
	void calcRollEngine(Lander* vehicle);
	void calcAxialEngine(Lander* vehicle);
	/*Roll* rollOne;             // affects accelerometerX, gyroscopeX
	Roll* rollTwo;
	Roll* rollThree;
	Axial* axialOne;           // affects gyroscopeY, accelerometerY, gyroscopeZ, accelerometerZ negatively
	Axial* axialTwo;           // affects gyroscopeY, accelerometerY, gyroscopeZ, accelerometerZ positively
	Axial* axialThree;         // affects gyroscopeY, accelerometerY, gyrozcopeZ, accelerometerZ negatively */
};