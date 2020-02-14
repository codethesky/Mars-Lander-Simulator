// Header for the Control class. The Control class will facilitate the movement of 
// Mars Lander data in a logical order.
// Created by: Skyler Howard
#include "Engine/Engine.h"
#include "Sensor/Sensor.h"
#include "DataLog.h"
#include <iostream>
#include <array>

struct Lander
{
	double accelerometerX;    // accelerometer x-axis
	double accelerometerY;    // accelerometer y-axis
	double accelerometerZ;    // accelerometer z-axis
	double dopplerRadar;
	double altimeter;         // altitude in miles
	double temperatureEngine; // temperature sensor for engines
	double temperatureVehicle; // temperature of vehicle
	double gyroscopeX;        // orientation of x-axis
	double gyroscopeY;        // orientation of y-axis
	double gyroscopeZ;        // orientation of z-axis
	Roll rollEngineOne;     // rotation engine, thrust is pounds of thrust
	Roll rollEngineTwo;
	Roll rollEngineThree;
	Axial axialThrustOne;    // descent engine
	Axial axialThrustTwo;
	Axial axialThrustThree;
	bool parachute;           // If the parachute is deployed
	bool touchDown;
};

class Control
{
public:
	Lander* lander;
	Control();
	~Control();
	void landMarsLander();
private:
	int count;
	
	void initialize();
	void calcSensorData(Lander*);
	void updateSensorInput(Lander*);
	void calcRotationPerHour(Lander*, double);
	void calcAxialData(Lander*, double);
	void calcVelocity(Lander*, double);
	void calcAltitude(Lander*);
	void calcTemperature(Lander*);

};