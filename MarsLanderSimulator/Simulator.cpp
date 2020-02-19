#include "Simulator.h"
#include "stdlib.h"
#include "windows.h"

#include <iostream>

using namespace std;

Simulator::Simulator()
{
	tracker = false;
}

Simulator::~Simulator()
{

}

void Simulator::display(Lander* lander)
{
	double altitude = lander->altimeter;
	bool parachute = lander->parachute;
	int progress = static_cast<int>((altitude / 28.1) * 100) % 100;     // getting a percentage of the progress
	progress = 100 - progress;
	bool prev = this->tracker;
	int para = NULL;

	if (parachute)
	{
		para = progress - 10;
	}
	
	system("CLS");

	cout << "     PROGRESS     |                                  MARS LANDER SIMULATION                       \n                  |   " << endl;

	displayProgress(10, progress, para);

	cout << "        |          Altitude: " << lander->altimeter << " mi" << "          "
		<< "                     Descent: " << lander->dopplerRadar << " mph" << endl;
	
	displayProgress(20, progress, para);
	
	cout << "        |              Roll: " << lander->gyroscopeX << " degrees" << "          "
		<< "                    X-Axis Speed: " << lander->accelerometerX << " rph" << endl;
	
	displayProgress(30, progress, para);
	
	cout << "        |             Pitch: " << lander->gyroscopeY << " degrees" << "          "
		<< "                    Y-Axis Speed: " << lander->accelerometerY << " rph" << endl;
	
	displayProgress(40, progress, para);
	
	cout << "        |               Yaw: " << lander->gyroscopeZ << " degrees" << "          "
		<< "                    Z-Axis Speed: " << lander->accelerometerZ << " rph\n";
	displayProgress(50, progress, para);
	
	cout << "        | " << endl;

	displayProgress(50, progress, para);
	
	cout << "        |          ___________________________________________________________________\n";

	displayProgress(60, progress, para);

	cout << "        | \n";

	displayProgress(60, progress, para);

	cout << "        |                                       Engines                            " << endl;
	
	displayProgress(60, progress, para);
	
	cout << "        |               Roll 1: " << lander->rollEngineOne.getThrust() << "% " << "          "
		<< "                    Axial 1: " << lander->axialThrustOne.getThrust() << "% " << endl;
	
	displayProgress(70, progress, para);
	
	cout << "        |               Roll 2: " << lander->rollEngineTwo.getThrust() << "% " << "          "
		<< "                    Axial 2: " << lander->axialThrustTwo.getThrust() << "% " << endl;
	
	displayProgress(80, progress, para);
	
	cout << "        |               Roll 3: " << lander->rollEngineThree.getThrust() << "% " << "          "
		<< "                    Axial 3: " << lander->axialThrustThree.getThrust() << "% " << endl;

	
	displayProgress(80, progress, para);
	
	cout << "        |          ___________________________________________________________________\n";
	
	displayProgress(90, progress, para);
	
	cout << "        | " << endl;
	
	displayProgress(100, progress, para);
	
	cout << "        |           Parachute Deployed: ";
	displayBool(lander->parachute);
	cout << endl;
	cout << "      LAND        |           Vehicle Landed: ";
	displayBool(lander->touchDown);
	cout << endl;
	cout << "       " << progress << "%        |" << endl;

	cout << endl;
	cout << endl;
	// TODO: Add a method to add a few second pause in process
	Sleep(3);
}

/*
* Takes boolean variable and outputs YES (true) or NO (false)
*/
void Simulator::displayBool(bool item)
{
	if (item)
	{
		cout << "YES";
	}
	else
		cout << "NO";
}

/*
* Displays the progress of the lander
*/
void Simulator::displayProgress(int stage, int progress, int parachute)
{
	int prevStage = stage - 10;
	bool previous = false;     // if lander has past this point

	if (progress > stage)
	{
		previous = true;
	}

	if (parachute <= stage && parachute >= prevStage && stage > 10)
	{
		cout << "       Y  ";
		return;
	}
	else if (progress <= stage && progress >= prevStage)
	{
		cout << "       v  ";
		previous = true;
		return;
	}
	else
	{
		if (stage == 100)
		{
			if (progress <= stage && progress >= prevStage)
			{
				cout << "       M  ";
				previous = true;
				return;
			}
			else
			{
				cout << "      ___ ";
				return;
			}
		}
		else
		{
			if (previous)

			{
				cout << "       *  ";
			}
			else
			{
				cout << "          ";
			}
		}
		
	}
}