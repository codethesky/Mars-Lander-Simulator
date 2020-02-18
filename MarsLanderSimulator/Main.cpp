#include "Control.h"
#include "windows.h"
#include <iostream>

using namespace std;


int main()
{
	cout << "To run Mars Lander Simulation press enter. . ." << endl;
	cin.get();

	Control controller;
	controller.landMarsLander();

	cout << "SIMULATION COMPLETE. . ." << endl;
	cin.get();

	return 0;
}
