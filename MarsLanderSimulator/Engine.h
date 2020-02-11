// Created by: Marla Carrier, Skyler Howard
#include "Roll.h"
#include "Axial.h"

class Engine
{
public:
	Engine();
	~Engine();
private:
	Roll* rollOne;             // affects accelerometerX, gyroscopeX
	Roll* rollTwo;
	Roll* rollThree;
	Axial* axialOne;           // affects gyroscopeY, accelerometerY, gyroscopeZ, accelerometerZ negatively
	Axial* axialTwo;           // affects gyroscopeY, accelerometerY, gyroscopeZ, accelerometerZ positively
	Axial* axialThree;         // affects gyroscopeY, accelerometerY, gyrozcopeZ, accelerometerZ negatively
};