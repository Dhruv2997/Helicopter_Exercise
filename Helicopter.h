#pragma once
#include <string>
using namespace std;

class Helicopter
{
private:
	double fuelLevel, altitude;
	bool isEngineRunning;

public:
	Helicopter();
	double getFuelLevel();
	double getAltitude();
	bool getEngineStatus();
	bool startEngine();
	bool stopEngine();
	bool flyToAltitude(double altitude);
	bool refuel(double amount);
	string toString();
};