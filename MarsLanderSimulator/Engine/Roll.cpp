#include "Roll.h"

using namespace std;

Roll::Roll()
{
	POWER = 30;
	setThrust(0.0);
}

Roll::~Roll()
{

}

// the input amt is a decimal of the percentage of thrust you want to have
// the overall thrust that gets set is the new amount of power the output is, by pounds per second
void Roll::setThrust(double amt)
{
	double pwr = this->POWER;
	this->thrust = pwr * amt;
}

double Roll::getThrust()
{
	return this->thrust;
}