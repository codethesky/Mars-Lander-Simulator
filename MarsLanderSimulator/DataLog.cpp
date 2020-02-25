// Creatd by: Skyler Howard

#include "DataLog.h"

using namespace std;

DataLog::DataLog()
{
	lineCount = 0;
	clearLogFile();
}

DataLog::~DataLog()
{

}

/*
// Move to the end of the current file
while (!logfile.eof())
{
	lineCount++;
	logfile.ignore(numeric_limits<streamsize>::max(), '\n');
}
*/

void DataLog::logData(Lander* vehicle)
{
	// Open the log file
	ofstream logfile;
	logfile.open("log.txt");

	// Add the new data
	logfile << "X-Axis Accelerometer: " << vehicle->accelerometerX << "\n";
	logfile << "Y-Axis Accelerometer: " << vehicle->accelerometerY << "\n";
	logfile << "Z-Axis Accelerometer: " << vehicle->accelerometerZ << "\n";
	logfile << "Doppler Radar: " << vehicle->dopplerRadar << "\n";
	logfile << "Altimeter: " << vehicle->altimeter << "\n";
	logfile << "Engine Temperature: " << vehicle->temperatureEngine << "\n";
	logfile << "Vehicle Temperature: " << vehicle->temperatureVehicle << "\n";
	logfile << "X-Axis Gyroscope: " << vehicle->gyroscopeX << "\n";
	logfile << "Y-Axis Gyroscope: " << vehicle->gyroscopeY << "\n";
	logfile << "Z-Axis Gyroscope: " << vehicle->gyroscopeZ << "\n";
	logfile << "Roll Engine One Thrust: " << vehicle->rollEngineOne.getThrust() << "\n";
	logfile << "Roll Engine Two Thrust: " << vehicle->rollEngineTwo.getThrust() << "\n";
	logfile << "Roll Engine Three Thrust: " << vehicle->rollEngineThree.getThrust() << "\n";
	logfile << "Axial Engine One Thrust: " << vehicle->axialThrustOne.getThrust() << "\n";
	logfile << "Axial Engine Two Thrust: " << vehicle->axialThrustTwo.getThrust() << "\n";
	logfile << "Axial Engine Three Thrust: " << vehicle->axialThrustThree.getThrust() << "\n";
	logfile << "Parachute Deployed: " << vehicle->parachute << "\n";
	logfile << "Vehicle Landing Sensor: " << vehicle->touchDown << "\n";


	logfile.close();
}

// Will delete everything in the log.txt file
void DataLog::clearLogFile()
{

}