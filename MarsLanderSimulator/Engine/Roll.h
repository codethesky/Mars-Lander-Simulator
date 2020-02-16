// Created by: Skyler Howard
// Roll engine controls spin of lander, clockwise or counterclockwise, affects accelerometerX, gyroscopeX
#pragma once

#include <iostream>

class Roll
{
public:
	Roll();
	~Roll();
	void setThrust(double amt);
	double getThrust();
private:
	const double POWER = 30;
	double thrust;
};