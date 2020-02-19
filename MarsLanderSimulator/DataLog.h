// Creatd by: Skyler Howard
#pragma once
#include "Control.h"
#include "Simulator.h"
#include <iostream>
#include <fstream>
#include <limits>

struct Lander;      // forward declaration

class DataLog
{
public:
	DataLog();
	~DataLog();
	void logData(Lander*);
private:
	int lineCount;
	void clearLogFile();
};