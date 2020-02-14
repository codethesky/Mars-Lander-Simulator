// Created by: Skyler Howard
// Axial engine controls velocity and angle of lander, can only be positive no negative
// affects accelerometerY, acceloerometerZ, gyroscopeY, gyroscopeZ

class Axial : public Engine
{
public:
	Axial();
	~Axial();

private:
	const double POWER = 50;

};