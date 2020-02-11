// Created by: Skyler Howard

#include "Axial.h"
#include <iostream>

using namespace std;

Axial::Axial()
{
	thrust = 0.0;
}

Axial::~Axial()
{

}

void Axial::setThrust(double amt)
{
	double pwr = this->POWER;
	this->thrust = pwr * amt;
}