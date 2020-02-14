// Created by: Marla Carrier, Skyler Howard
#include "Engine.h"
#include <iostream>

using namespace std;

Engine::Engine()
{

}

Engine::~Engine()
{
	
}

// the input amt is a decimal of the percentage of thrust you want to have
// the overall thrust that gets set is the new amount of power the output is, by pounds per second
void Engine::setThrust(double amt)
{
	double pwr = this->POWER;
	this->thrust = pwr * amt;
}

double Engine::getThrust()
{
	return this->thrust;
}

/*
* Will take lander data, calculate new thrust for engines
*/
void Engine::getEngineData(Lander* vehicle)
{
	calcRollEngine(vehicle);
	calcAxialEngine(vehicle);
}

void Engine::calcRollEngine(Lander* vehicle)
{
	double rollOne = vehicle->rollEngineOne.getThrust();
	double rollTwo = vehicle->rollEngineTwo.getThrust();
	double rollThree = vehicle->rollEngineThree.getThrust();
	double rotationX = vehicle->accelerometerX;
	double rotationZ = vehicle->accelerometerZ;
	double gyroX = vehicle->gyroscopeX;
	double gyroZ = vehicle->gyroscopeZ;          // roll engines have 1/3rd the effect on Z-axis. Axial Engine 2/3rd
	int pwr = 0;
	double percent = 0.0;
	
	// calculate X-axis spin, break it down into a percentage
	pwr = (rotationX / 10);
	percent = pwr / 100;
	
	// calculate Z-axis spin
	pwr = ((rotationZ / 10) / 3);           // roll engine accounts for 1/3rd effect on Z-axis
	percent += (pwr / 100);

	if (percent > 1.0)
	{
		percent = 1.0;
	}
	else if (percent < -1.0)
	{
		percent = -1.0;
	}

	// set the new thrust percentage
	vehicle->rollEngineOne.setThrust(percent);
	vehicle->rollEngineTwo.setThrust(percent);
	vehicle->rollEngineThree.setThrust(percent);
}

void Engine::calcAxialEngine(Lander* vehicle)
{

}
