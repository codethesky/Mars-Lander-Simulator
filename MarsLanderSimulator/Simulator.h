// Simulator class will be used by DataLog class to output Mars Lander Data to the console screen
// Created by: Skyler Howard

#pragma once
#include "Control.h"
#include <iostream>

struct Lander;      // forward declaration

class Simulator
{
public:
	Simulator();
	~Simulator();
	void display(Lander*);
private:
	bool tracker;          // used in tracking current stage of lander (progress towards landing)
	void displayBool(bool);
	void displayProgress(int, int, int);
};