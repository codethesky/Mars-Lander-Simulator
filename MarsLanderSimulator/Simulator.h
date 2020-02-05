#include "Control.h"
#include <iostream>

class Simulator
{
public:
	Simulator();
	~Simulator();
	void display(Lander*);
private:
	void displayBool(bool);
};