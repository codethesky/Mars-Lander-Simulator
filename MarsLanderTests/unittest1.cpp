#include "stdafx.h"
#include "CppUnitTest.h"
#include "windows.h"
#include <iostream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MarsLanderTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Testing the Simulator output
			cout << "To run Mars Lander Simulation press enter. . ." << endl;
			cin.get();

			cout << "Sleep test" << endl;
			cout << "Sleep 3 seconds" << endl;
			Sleep(3);
			cout << "Sleep 5 seconds" << endl;
			Sleep(5);
			
		}

	};
}