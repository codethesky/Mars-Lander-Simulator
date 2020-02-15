// Created by: Skyler Howard
// Axial engine controls velocity and angle of lander, can only be positive no negative
// affects accelerometerY, acceloerometerZ, gyroscopeY, gyroscopeZ
#pragma once
#include <iostream>

class Axial : public Engine
{
public:
	Axial();
	~Axial();
	void setThrust(double);
	double getThrust();
private:
	double POWER = 50;

};