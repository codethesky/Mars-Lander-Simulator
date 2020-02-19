#include "Control.h"
#include "windows.h"
#include <iostream>

using namespace std;


int main()
{
	cout << "\n   Welcome to the Mars Lander Simulation! \n" << endl;

	cout << "   This program will simulate a Mars Lander entering the Mars Atmosphere.\n"
		<< "   The lander enters the atmosphere at an altitude of 28.1 miles and is \n"
		<< "   travelling at 10,750 miles per hour. The lander will read sensor data \n"
		<< "   and will activate a parachute and engines as needed to control the descent.\n"
		<< "   The following sensors and engines are used:\n\n"
		<< "   SENSORS:\n"
		<< "      - 3 Accelerometers: one for an X-Axis, Y-Axis, and Z-Axis.\n"
		<< "      - 1 Altimeter: reads the altitude.\n"
		<< "      - 1 Doppler Radar: reads the descent velocity.\n"
		<< "      - 3 Gyroscopes: tells orientation of X-Axis, Y-Axis, and Z-Axis.\n"
		<< "      - 2 Temperature Sensors: reads temperature of the engine and vehicle.\n"
		<< "      - 1 Touch-Down Sensor: reads if vehicle has landed.\n\n"
		<< "   ENGINES:\n"
		<< "      - 3 Roll Engines: controls the X-Axis and Z-Axis spin.\n"
		<< "      - 3 Axial Engines: controls descent speed, Y-Axis and Z-Axis spin.\n\n";
	
	cout << "   To run Mars Lander Simulation press enter. . ." << endl;
	cin.get();

	Control controller;
	controller.landMarsLander();

	cout << "SIMULATION COMPLETE. . ." << endl;
	cin.get();

	return 0;
}
