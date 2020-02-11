// Simulator class will be used by DataLog class to output Mars Lander Data to the console screen
// Created by: Skyler Howard

#include "Control.h"
#include <iostream>

class Simulator
{
public:
	Simulator();
	~Simulator();
	void display(Lander*);
private:
	void displayBool(bool);
};