// Created by: Skyler Howard
// Roll engine controls spin of lander, clockwise or counterclockwise, affects accelerometerX, gyroscopeX

class Roll
{
public:
	Roll();
	~Roll();
	void setThrust(double);

private:
	const double POWER = 30;
	double thrust;
};