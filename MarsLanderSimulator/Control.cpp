#include "Control.h"
#include "Engine/Engine.h"
#include <iostream>
#include <array>

using namespace std;

Control::Control()
{
	lander = new Lander;
	initialize();
}

Control::~Control()
{

	delete lander;
}

/*
* Creates the initial values of when the lander enters the Mars atmosphere
*/
void Control::initialize()
{
	lander->accelerometerX = 0;        // Accelerometer(x-axis): RPH Rotations Per Hour
	lander->accelerometerY = 60;       // Accelerometer(y-axis): RPH
	lander->accelerometerZ = 0;        // Accelerometer(z-axis): RPH
	lander->dopplerRadar = 10750;      // Velocity: 10,750 miles per hour
	lander->altimeter = 28.1;          // 28.1 miles above surface
	lander->temperatureEngine = 100;   // Temperature of Engines: Degrees Fahrenheit     
	lander->temperatureVehicle = 2700; // Temperature of Vehicle: Degrees Fahrenheit
	lander->gyroscopeX = 60.0;         // X-Axis Gyroscope: Degrees
	lander->gyroscopeY = 15.0;         // Y-Axis Gyroscope: Degrees
	lander->gyroscopeZ = 10.0;         // Z-Axis Gyroscope: Degrees
	lander->rollEngineOne = 0.0;       // Rotation Engine: Percentage of Thrust
	lander->rollEngineTwo = 0.0;       // Rotation Engine: Percentage of Thrust
	lander->rollEngineThree = 0.0;     // Rotation Engine: Percentage of Thrust
	lander->axialThrustOne = 0.0;      // Descent Engine: Percentage of Thrust
	lander->axialThrustTwo = 0.0;      // Descent Engine: Percentage of Thrust
	lander->axialThrustThree = 0.0;    // Descent Engine: Percentage of Thrust
	lander->parachute = false;         // If the parachute is deployed
	lander->touchDown = false;         // If the vehicle has landed 
}

void Control::landMarsLander()
{
	// TODO: have a Sensor class that inititializes all sensor objects needed on lander
	Sensor sensor;
	DataLog dataLog;
	Engine engine;

	while (!lander->touchDown)
	{
		dataLog.logData(lander);
		sensor.getSensorData();      // Calls for updated data for next position. 
		dataLog.logData(lander);       // Sends lander data to be logged in file and sent to simulator
		engine.getEngineData(lander);  // Sends lander data for engines to react, and update lander object data

	}
}

