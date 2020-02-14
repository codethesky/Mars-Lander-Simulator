#include "Control.h"
#include "Engine/Engine.h"
#include "Sensor/Sensor.h"
#include "DataLog.h"
#include <iostream>
#include <array>

using namespace std;

void quickPause(int sec);

Control::Control()
{
	lander = new Lander;
	count = 0;
	initialize();
}

Control::~Control()
{

	delete lander;
}

/*
* Creates the initial values of when the lander enters the Mars atmosphere
*/
void Control::initialize()
{
	lander->accelerometerX = 60;        // Accelerometer(x-axis): RPH Rotations Per Hour
	lander->accelerometerY = 0;       // Accelerometer(y-axis): RPH
	lander->accelerometerZ = 0;        // Accelerometer(z-axis): RPH
	lander->dopplerRadar = 10750;      // Velocity: 10,750 miles per hour
	lander->altimeter = 28.1;          // 28.1 miles above surface
	lander->temperatureEngine = 100;   // Temperature of Engines: Degrees Fahrenheit     
	lander->temperatureVehicle = 2700; // Temperature of Vehicle: Degrees Fahrenheit
	lander->gyroscopeX = 60.0;         // X-Axis Gyroscope: Degrees
	lander->gyroscopeY = 15.0;         // Y-Axis Gyroscope: Degrees
	lander->gyroscopeZ = 10.0;         // Z-Axis Gyroscope: Degrees
	lander->rollEngineOne = 0.0;       // Rotation Engine: Percentage of Thrust
	lander->rollEngineTwo = 0.0;       // Rotation Engine: Percentage of Thrust
	lander->rollEngineThree = 0.0;     // Rotation Engine: Percentage of Thrust
	lander->axialThrustOne = 0.0;      // Descent Engine: Percentage of Thrust
	lander->axialThrustTwo = 0.0;      // Descent Engine: Percentage of Thrust
	lander->axialThrustThree = 0.0;    // Descent Engine: Percentage of Thrust
	lander->parachute = false;         // If the parachute is deployed
	lander->touchDown = false;         // If the vehicle has landed 
}

void Control::landMarsLander()
{
	// TODO: Calculation runtime of program and make each iteration one second long to be congruent with calculations

	Sensor sensor;
	DataLog dataLog;
	Engine engine;

	/*
	* calcSensorData(Lander* vehicle)
	*/

	while (!lander->touchDown)
	{
		dataLog.logData(lander);     // logs data in txt file and sends to console output simulator
		calcSensorData(lander);      // Calls for updated data for next position. 
		dataLog.logData(lander);       // Sends lander data to be logged in file and sent to simulator
		engine.getEngineData(lander);  // Sends lander data for engines to react, and update lander object data
		dataLog.logData(lander);
		calcSensorData(lander);
	}


}

/*
* Takes newly inputted sensor data and calculates the vehicles new trajectory and updates it.
*/
void Control::calcSensorData(Lander* vehicle)
{
	double landerWeight = 437;       // weight of lander with Mars gravity
	calcRotationPerHour(vehicle, landerWeight);
	calcAxialData(vehicle, landerWeight);
	calcVelocity(vehicle, landerWeight);
	calcAltitude(vehicle);
	calcTemperature(vehicle);
}

/*
* updates the sensors with new calculated data on the lander. 
* Can use this function when updating software to take different types of input
*/
void Control::updateSensorInput(Lander* vehicle)
{

}

/*
* Calculates the landers spin on axis X and Z and updates gyroscope X and Z. Takes accelerometer data (rotations per hour) 
* converts to weight of spin to apply power output from roll engines (weight per second), then converts back to rotation per hour to update lander
* positioning.
*/
void Control::calcRotationPerHour(Lander* vehicle, double lbs)
{
	double rotationX = vehicle->accelerometerX;
	double rotationZ = vehicle->accelerometerZ;      //Roll engines account for 1/3rd of z-axis spin, 2/3rd is axial engine
	double rollOne = vehicle->rollEngineOne;
	double rollTwo = vehicle->rollEngineTwo;
	double rollThree = vehicle->rollEngineThree;
	double powerOutput = rollOne + rollTwo + rollThree;
	double gyroX = vehicle->gyroscopeX;
	double gyroZ = vehicle->gyroscopeZ;

	// must convert accelerometerX rotation per hour to per second
	rotationX = (rotationX / 60) / 60;
	rotationZ = (rotationZ / 60) / 60;

	// convert rotation per second to weight of spin
	rotationX = rotationX * lbs;
	rotationZ * rotationZ * lbs;

	// adjust weight of spin by roll engine power output
	rotationX = rotationX - powerOutput;
	rotationZ = rotationZ - (.33 * powerOutput);     // roll engin accounts for 1/3rd z-axis spin

	// adjust the overall weight of spin to the percentage of overall weight
	rotationX = rotationX / lbs;
	rotationZ = rotationZ / lbs;

	// calculate degree adjustment for gyroscope, still based on per second
	gyroX = 360 * rotationX;
	gyroZ = 360 * rotationZ;
	gyroX = static_cast<int>(vehicle->gyroscopeX + gyroX) % 360;
	gyroZ = static_cast<int>(vehicle->gyroscopeZ + gyroZ) % 360;

	// update lander gyroscope data
	vehicle->gyroscopeX = gyroX;
	vehicle->gyroscopeZ = gyroZ;

	// convert weight of spin back to the rotation per hour
	rotationX = (rotationX * 60) * 60;
	rotationZ = (rotationZ * 60) * 60;

	// applying roll engine power to adjust axis spin
	vehicle->accelerometerX = rotationX;
	vehicle->accelerometerZ = rotationZ;
}

void Control::calcAxialData(Lander* vehicle, double lbs)
{
	double rotationY = vehicle->accelerometerY;
	double rotationZ = vehicle->accelerometerZ;
	double gyroY = vehicle->gyroscopeY;
	double gyroZ = vehicle->gyroscopeZ;
	double axialOne = vehicle->axialThrustOne;
	double axialTwo = vehicle->axialThrustTwo;
	double axialThree = vehicle->axialThrustThree;

	// adding up positive (clockPower) and negative (counterClockPower) for later calculations
	double counterClockPower = axialOne + axialThree;
	double clockPower = axialTwo;

	// convert rotation per hour to per second
	rotationY = (rotationY / 60) / 60;
	rotationZ = (rotationZ / 60) / 60;

	// convert rotation per hour to weight of spin
	rotationY = rotationY * lbs;
	rotationZ = rotationZ * lbs;

	// adjust spin based on power output
	rotationY = rotationY + (clockPower - counterClockPower);
	rotationZ = rotationZ + (.66 * (clockPower - counterClockPower));    // Axial counts for 2/3rds of Z-axis

	// convert amount of change back into rotation per hour
	rotationY = rotationY / lbs;
	rotationZ = rotationZ / lbs;

	// convert rotation into degree shift for gyroscope
	gyroY = rotationY * 360;
	gyroZ = rotationZ * 360;
	gyroY = static_cast<int>(vehicle->gyroscopeY + gyroY) % 360;  // takes old position, adds on new amount changed
	gyroZ = static_cast<int>(vehicle->gyroscopeZ + gyroZ) % 360;

	// update lander gyroscope
	vehicle->gyroscopeY = gyroY;
	vehicle->gyroscopeZ = gyroZ;

	// convert rotation per second back to rotation per hour
	rotationY = (rotationY * 60) * 60;
	rotationZ = (rotationZ * 60) * 60;

	// update lander accelerometers
	vehicle->accelerometerY = rotationY;
	vehicle->accelerometerZ = rotationZ;

}

void calcVelocity(Lander* vehicle, double weight)
{
	double velocity = vehicle->dopplerRadar;   // is in miles per hour
	double axialOne = vehicle->axialThrustOne;
	double axialTwo = vehicle->axialThrustTwo;
	double axialThree = vehicle->axialThrustThree;
	double totalPower = axialOne + axialTwo + axialThree;
	double altitude = vehicle->altimeter;
	bool parachute = vehicle->parachute;
	double changeInVelocity = 0;

	if (altitude > 1)
	{
		double distance = 0;
		double speed = 0;

		if (!parachute)    // Speed is slowing down by the atmosphere
		{
			distance = altitude - 7.5;
			speed = velocity - 3800;
			changeInVelocity = speed / distance; 
		}
		else if (parachute)      // Speed slowing down by the parachute
		{
			if (altitude > 7)
			{
				distance = altitude - 7;
				speed = velocity - 861;
				changeInVelocity = speed / distance;
			}
			if (altitude > 5.7 && altitude <= 7)
			{
				distance = altitude - 5.7;
				speed = velocity - 268;
				changeInVelocity = speed / distance;
			}
			if (altitude > .62 && altitude <= 5.7)
			{
				distance = altitude - .62;
				speed = velocity - 134;
				changeInVelocity = speed / distance;
			}
		}
		
		// Test to ensure successful change in speed.
		speed = velocity - changeInVelocity;
		if (speed > 0)
		{
			vehicle->dopplerRadar = speed;
		}
		else
		{
			system("CLS");
			cout << "Error: Lander is flying back out of Atmosphere!" << endl;
			cin.get();
		}
	}
	else if (altitude < 1 && !parachute)
	{
		// adjust velocity from engine output
		velocity = velocity - (totalPower * .25) * .25;

		// update lander velocity
		if (velocity > 0)
		{
			vehicle->dopplerRadar = velocity;
		}
		else
		{
			system("CLS");
			cout << "Error: Lander is increasing altitude!" << endl;
			cin.get();
		}
	}
}

void calcAltitude(Lander* vehicle)
{
	double altitude = vehicle->altimeter;
	double velocity = vehicle->dopplerRadar;

	// Convert velocity miles per hour to miles per second
	velocity = (velocity / 60) / 60;

	// calculate distance travelled
	altitude = altitude - velocity;

	// Deploy parachute or announce touch down
	if (altitude <= 7.5)
	{
		vehicle->parachute = true;
	}
	else if (altitude < .03 && velocity > 17)
	{
		for (int i = 0; i < 8; i++)
		{
			system("CLS");
			cout << "ERROR: Lander crashed! Speed too Fast! | SPEED: " << velocity << " mph" << endl;
			quickPause(1);
		}
		cin.get();
	}
	else if (altitude < .03 && velocity < 17)
	{
		vehicle->touchDown = true;
		system("CLS");
		cout << "CONGRATULATIONS! We have touch down! " << endl;
		cin.get();
	}

	// update lander
	vehicle->altimeter = altitude;
}

void calcTemperature(Lander* vehicle)
{
	bool parachute = vehicle->parachute;
	double velocity = vehicle->dopplerRadar;
	double altitude = vehicle->altimeter;
	double maxEngineTemp = 250;          // the limit the engines warm up to before ignition
	double maxVehicleTemp = 2700;
	double percentComplete = 0.0;

	// By the 2 mile mark, temperatures will be stable
	if (parachute)
	{
		// calculate engine temperature, based on linear progression from altitude 7 - 2 miles
		double dataHolder = altitude - 2;      // engines should be warmed up by 2 miles in altitude
		percentComplete = static_cast<int>(dataHolder / 5) % 5;       // takes 5 miles to warm up engine, just getting a percentage to work with
		
		// updating lander engine temperature
		vehicle->temperatureEngine = maxEngineTemp * percentComplete;

		// calculate vehicle temperature, based on linear regression from altitude 22 - 2 miles
		dataHolder = altitude - 2;
		percentComplete = static_cast<int>(dataHolder / 20) % 20;     // conversion over 20 miles for the temperature drop
		dataHolder = percentComplete * maxVehicleTemp;

		// update lander vehicle temperature
		vehicle->temperatureVehicle = maxVehicleTemp - dataHolder;
	}
	else
	{
		// calculate temperatures before parachute deployment
		if (altitude > 7.5)
		{
			vehicle->temperatureEngine = 100.00;
			vehicle->temperatureVehicle = 2700;
		}
		else
		{
			vehicle->temperatureEngine = maxEngineTemp;
			vehicle->temperatureVehicle = maxVehicleTemp;
		}
	}
}

void Control::quickPause(int sec)
{
	int seconds = sec * 1000;
	for (int i = 0; i < seconds; i++)
	{
		i = i;
	}
}


