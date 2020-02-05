#include "Control.h"
#include <iostream>
#include <array>

using namespace std;

Control::Control()
{
	lander = new Lander;
	lander->initialize();
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
	this->accelerometerX = 0;        // Accelerometer(x-axis): RPH Rotations Per Hour
	this->accelerometerY = 60;       // Accelerometer(y-axis): RPH
	this->accelerometerZ = 0;        // Accelerometer(z-axis): RPH
	this->dopplerRadar = 10750;      // Velocity: 10,750 miles per hour
	this->altimeter = 28.1;          // 28.1 miles above surface
	this->temperatureEngine = 100;   // Temperature of Engines: Degrees Fahrenheit     
	this->temperatureVehicle = 2700; // Temperature of Vehicle: Degrees Fahrenheit
	this->gyroscopeX = 60.0;         // X-Axis Gyroscope: Degrees
	this->gyroscopeY = 15.0;         // Y-Axis Gyroscope: Degrees
	this->gyroscopeZ = 10.0;         // Z-Axis Gyroscope: Degrees
	this->rollEngineOne = 0.0;       // Rotation Engine: Percentage of Thrust
	this->rollEngineTwo = 0.0;       // Rotation Engine: Percentage of Thrust
	this->rollEngineThree = 0.0;     // Rotation Engine: Percentage of Thrust
	this->axialThrustOne = 0.0;      // Descent Engine: Percentage of Thrust
	this->axialThrustTwo = 0.0;      // Descent Engine: Percentage of Thrust
	this->axialThrustThree = 0.0;    // Descent Engine: Percentage of Thrust
	this->parachute = false;         // If the parachute is deployed
	this->touchDown = false;         // If the vehicle has landed 
}

void Control::landMarsLander()
{
	// TODO: have a Sensor class that inititializes all sensor objects needed on lander
	Sensor sensor;
	DataLog dataLog;
	Engine engine;

	while (!this->touchDown)
	{
		dataLog.logData(this);
		sensor.getSensorData();      // Calls for updated data for next position. 
		dataLog.logData(this);       // Sends lander data to be logged in file and sent to simulator
		engine.getEngineData(this);  // Sends lander data for engines to react, and update lander object data

	}
}

