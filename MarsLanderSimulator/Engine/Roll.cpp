#include "Roll.h"
#include <iostream>

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
