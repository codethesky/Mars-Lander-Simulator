// Created by: Marla Carrier, Skyler Howard
#include "Engine.h"
#include <iostream>

using namespace std;

Engine::Engine()
{
	rollOne = new Roll;
	rollTwo = new Roll;
	rollThree = new Roll;
	axialOne = new Axial;
	axialTwo = new Axial;
	axialThree = new Axial;
}

Engine::~Engine()
{

}

/*
* Will take lander data, calculate new thrust for engines, then update lander data based on engine output.
*/
void Engine::getEngineData(Lander* vehicle)
{

}


