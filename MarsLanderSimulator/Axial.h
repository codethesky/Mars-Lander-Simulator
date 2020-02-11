// Created by: Skyler Howard
// Axial engine controls velocity and angle of lander, can only be positive no negative
// affects accelerometerY, acceloerometerZ, gyroscopeY, gyroscopeZ

class Axial
{
public:
	Axial();
	~Axial();
	void setThrust(double);
private:
	const double POWER = 50;
	double thrust;
};