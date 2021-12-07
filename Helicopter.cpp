#include <iostream>
#include "Helicopter.h"
using namespace std;

Helicopter::Helicopter() {
	fuelLevel = 100;
	altitude = 0;
	isEngineRunning = false;
}

double Helicopter::getFuelLevel() {
	return fuelLevel;
}
double Helicopter::getAltitude() {
	return altitude;
}
bool Helicopter::getEngineStatus() {
	return isEngineRunning;
}

bool Helicopter::startEngine() {
	if (isEngineRunning || altitude != 0) {
		return false;
	}
	else {
		isEngineRunning = true;
		return true;
	}
}
bool Helicopter::stopEngine() {
	if (!isEngineRunning || altitude != 0) {
		return false;
	}
	else {
		isEngineRunning = false;
		return true;
	}
}
bool Helicopter::flyToAltitude(double newAltitude) {
	if (!isEngineRunning || fuelLevel <= 0) {
		return false;
	}
	else {
		if (newAltitude < 0 || newAltitude > 5000) {
			return false;
		}
		else {
			double fuelConsumption = rand() % 10 + 5;
			fuelLevel = fuelLevel - fuelConsumption;
			altitude = newAltitude;
			return true;
		}
	}
}

bool Helicopter::refuel(double amount) {
	if (isEngineRunning || altitude != 0 || fuelLevel == 100) {
		return false;
	}
	else {
		fuelLevel = amount;
		return true;
	}
}

string Helicopter::toString() {
	string helicopterDetails = "Helicopter Fuel -> " + to_string(fuelLevel) + ", Altitude -> " + to_string(altitude) + ", Engine Status -> " + to_string(isEngineRunning);
	return helicopterDetails;
}