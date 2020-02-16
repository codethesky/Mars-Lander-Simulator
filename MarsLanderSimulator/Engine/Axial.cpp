// Created by: Skyler Howard

#include "Axial.h"

using namespace std;

Axial::Axial()
{
	setThrust(0.0);
}

Axial::~Axial()
{

}

// the input amt is a decimal of the percentage of thrust you want to have
// the overall thrust that gets set is the new amount of power the output is, by pounds per second
void Axial::setThrust(double amt)
{
	double pwr = this->POWER;
	this->thrust = pwr * amt;
}

double Axial::getThrust()
{
	return this->thrust;
}