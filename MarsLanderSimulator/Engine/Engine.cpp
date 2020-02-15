// Created by: Marla Carrier, Skyler Howard
#include "Engine.h"
#include <iostream>

using namespace std;

Engine::Engine()
{
	POWER = 30;
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

// TODO: first set gyroY to within 10 degrees of 0. Then, control landing velocity.
void Engine::calcAxialEngine(Lander* vehicle)
{
	double gyroY = vehicle->gyroscopeY;
	double gyroZ = vehicle->gyroscopeZ;
	bool touchDown = vehicle->touchDown;
	bool parachute = vehicle->parachute;
	double velocity = vehicle->dopplerRadar;
	double altitude = vehicle->altimeter;
	double percent = 0.0;
	double speed = 0;
	bool upright = false;

	// checking if lander is in the upright position
	if (gyroY <= 10 && gyroY >= -10 && gyroZ <= 10 && gyroZ >= -10)
	{
		upright = true;
	}

	if (!touchDown)
	{
		if (!parachute)
		{
			if (!upright)
			{
				// Getting percentage of tilt, and applying that percent to the appropriate engines
				percent = gyroY / 180;
				if (gyroY < 180)
				{
					percent = percent / 2;
					vehicle->axialThrustOne.setThrust(percent);
					vehicle->axialThrustThree.setThrust(percent);
				}
				else if (gyroY >= 180)
				{
					percent = static_cast<int>(percent * 100) % 100;
					vehicle->axialThrustTwo.setThrust(percent);
				}
			}

			// Vehicle is upright, now using all engines to control descent
			if (upright)
			{
				if (velocity > 25)
				{
					vehicle->axialThrustOne.setThrust(1.0);
					vehicle->axialThrustTwo.setThrust(1.0);
					vehicle->axialThrustThree.setThrust(1.0);
				}
				else
				{
					percent = (altitude - .62) / velocity;
					vehicle->axialThrustOne.setThrust(percent);
					vehicle->axialThrustTwo.setThrust(percent);
					vehicle->axialThrustThree.setThrust(percent);
				}
			}
		}

		// while parachute deployed, the lander will slowly move upright
		if (parachute && !upright)
		{
			vehicle->gyroscopeY = gyroY - 10;
			vehicle->gyroscopeZ = gyroZ - 10;
		}
	}
}
