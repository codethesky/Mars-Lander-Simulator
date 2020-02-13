#include "Control.h"
#include "Engine/Engine.h"
#include "Sensor/Sensor.h"
#include "DataLog.h"
#include <iostream>
#include <array>

using namespace std;

Control::Control()
{
	lander = new Lander;
	count = 0;
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
	lander->accelerometerX = 60;        // Accelerometer(x-axis): RPH Rotations Per Hour
	lander->accelerometerY = 0;       // Accelerometer(y-axis): RPH
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
	// TODO: Calculation runtime of program and make each iteration one second long to be congruent with calculations

	Sensor sensor;
	DataLog dataLog;
	Engine engine;

	while (!lander->touchDown)
	{
		dataLog.logData(lander);
		sensor.getSensorData(lander);      // Calls for updated data for next position. 
		dataLog.logData(lander);       // Sends lander data to be logged in file and sent to simulator
		engine.getEngineData(lander);  // Sends lander data for engines to react, and update lander object data

	}
}

/*
* Takes newly inputted sensor data and calculates the vehicles new trajectory and updates it.
*/
void Control::calcSensorData(Lander* vehicle)
{
	double landerWeight = 437;       // weight of lander with Mars gravity
	calcRotationPerHour(vehicle, landerWeight);
}

void Control::updateSensorInput(Lander* vehicle)
{

}

/*
* Calculates the landers spin on axis X and Z. Takes accelerometer data (rotations per hour) converts to weight of spin
* to apply power output from roll engines (weight per second), then converts back to rotation per hour to update lander
* positioning.
*/
void Control::calcRotationPerHour(Lander* vehicle, double lbs)
{
	double rotationX = vehicle->accelerometerX;
	double rotationZ = vehicle->accelerometerZ;      //Roll engines account for 1/3rd of z-axis spin, 2/3rd is axial engine
	double rollOne = vehicle->rollEngineOne;
	double rollTwo = vehicle->rollEngineTwo;
	double rollThree = vehicle->rollEngineThree;
	double powerOutput = rollOne + rollTwo + rollThree;
	double gyroX = vehicle->gyroscopeX;
	double gyroZ = vehicle->gyroscopeZ;

	// must convert accelerometerX rotation per hour to per second
	rotationX = (rotationX / 60) / 60;
	rotationZ = (rotationZ / 60) / 60;

	// convert rotation per second to weight of spin
	rotationX = rotationX * lbs;
	rotationZ * rotationZ * lbs;

	// adjust weight of spin by roll engine power output
	rotationX = rotationX - powerOutput;
	rotationZ = rotationZ - (.33 * powerOutput);     // roll engin accounts for 1/3rd z-axis spin

	// adjust the overall weight of spin to the percentage of overall weight
	rotationX = rotationX / lbs;
	rotationZ = rotationZ / lbs;

	// calculate degree adjustment for gyroscope, still based on per second
	gyroX = static_cast<int>(gyroX * rotationX) % 360;
	gyroZ = static_cast<int>(gyroZ * rotationZ) % 360;

	// update lander gyroscope data
	vehicle->gyroscopeX = gyroX;
	vehicle->gyroscopeZ = gyroZ;

	// convert weight of spin back to the rotation per hour
	rotationX = (rotationX * 60) * 60;
	rotationZ = (rotationZ * 60) * 60;

	// applying roll engine power to adjust axis spin
	vehicle->accelerometerX = rotationX;
	vehicle->accelerometerZ = rotationZ;
}



