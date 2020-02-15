// Created by: Skyler Howard

#include "Axial.h"

using namespace std;

Axial::Axial()
{
	POWER = 50;
	setThrust(0.0);
}

Axial::~Axial()
{

}

void Axial::setThrust(double amt)
{
	double pwr = this->POWER;
	this->thrust = pwr * amt;
}

double Axial::getThrust()
{
	return this->thrust;
}