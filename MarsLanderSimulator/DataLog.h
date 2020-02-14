// Creatd by: Skyler Howard
#include "Control.h"
#include "Simulator.h"
#include <iostream>
#include <fstream>
#include <limits>

class DataLog
{
public:
	DataLog();
	~DataLog();
	void logData(Lander*);
private:
	Simulator* simulator;
	int lineCount;

	void clearLogFile();
};