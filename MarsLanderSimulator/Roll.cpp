#include "Roll.h"
#include <iostream>

using namespace std;

Roll::Roll()
{
	setThrust(0.0);
}

Roll::~Roll()
{

}

void Roll::setThrust(double amt)
{
	double pwr = this->POWER;
	this->thrust = pwr * amt;
}