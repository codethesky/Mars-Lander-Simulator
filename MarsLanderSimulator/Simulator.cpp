#include "Simulator.h"
#include "stdlib.h"
#include "windows.h"

#include <iostream>

using namespace std;

Simulator::Simulator()
{

}

Simulator::~Simulator()
{

}

void Simulator::display(Lander* lander)
{
	system("CLS");

	cout << "                 MARS LANDER SIMULATION                       \n" << endl;

	cout << "Altitude: " << lander->altimeter << " mi" << "          "
		<< " Descent: " << lander->dopplerRadar << " mph" << endl;
	cout << "    Roll: " << lander->gyroscopeX << " degrees" << "          "
		<< "X-Axis Speed: " << lander->accelerometerX << " rph" << endl;
	cout << "   Pitch: " << lander->gyroscopeY << " degrees" << "          "
		<< "Y-Axis Speed: " << lander->accelerometerY << " rph" << endl;
	cout << "     Yaw: " << lander->gyroscopeZ << " degrees" << "          "
		<< "Z-Axis Speed: " << lander->accelerometerZ << " rph\n" << endl;

	cout << "______________________________________________________________\n\n"
		<< "                             Engines                            " << endl;
	cout << "     Roll 1: " << lander->rollEngineOne << "% " << "          "
		<< "Axial 1: " << lander->axialThrustOne << "% " << endl;
	cout << "     Roll 2: " << lander->rollEngineTwo << "% " << "          "
		<< "Axial 2: " << lander->axialThrustTwo << "% " << endl;
	cout << "     Roll 3: " << lander->rollEngineThree << "% " << "          "
		<< "Axial 3: " << lander->axialThrustThree << "% " << endl;

	cout << "______________________________________________________________\n" << endl;
	cout << "Parachute Deployed: ";
	displayBool(lander->parachute);
	cout << endl;
	cout << "    Vehicle Landed: ";
	displayBool(lander->touchDown);
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