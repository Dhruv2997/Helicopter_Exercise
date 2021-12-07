#include <iostream>
#include "Helicopter.h"
using namespace std;

int main()
{
	Helicopter helicopter;
	int select;
	bool success;

	do {
		cout << "Helicopter" << endl;
		cout << "1. Start" << endl;
		cout << "2. Stop" << endl;
		cout << "3. Fly up" << endl;
		cout << "4. Fly down" << endl;
		cout << "5. Land" << endl;
		cout << "6. Refuel" << endl;
		cout << "7. Helicopter Details Here" << endl;
		cout << "8. Exit" << endl;

		cout << "Select an option ::--> ";
		cin >> select;

		switch (select) {
		case 1:
			success = helicopter.startEngine();
			if (!success) {
				cout << endl << "Sorry!! Something Wrong Here..." << endl << endl;
			}
			else {
				cout << endl << "Engine Started." << endl << endl;
			}
			break;

		case 2:
			success = helicopter.stopEngine();
			if (!success) {
				cout << endl << "Sorry!! Something Wrong Here..." << endl << endl;
			}
			else {
				cout << endl << "Engine Stopped." << endl << endl;
			}
			break;

		case 3:
			success = helicopter.flyToAltitude(helicopter.getAltitude() + 400);
			if (helicopter.getFuelLevel() <= 0 && helicopter.getAltitude() != 0) {
				helicopter.stopEngine();
				helicopter.flyToAltitude(helicopter.getAltitude() - helicopter.getAltitude());
				cout << endl << "Fuel Low level!!" << endl;
				exit(0);
			}
			else if (!success) {
				cout << endl << "Sorry!! Something Wrong Here..." << endl << endl;
			}
			else {
				cout << endl << "New Altitude is " << helicopter.getAltitude() << endl << endl;
			}
			break;

		case 4:
			success = helicopter.flyToAltitude(helicopter.getAltitude() - 400);
			if (helicopter.getFuelLevel() <= 0 && helicopter.getAltitude() != 0) {
				helicopter.stopEngine();
				helicopter.flyToAltitude(helicopter.getAltitude() - helicopter.getAltitude());
				cout << endl << "Fuel Low level!!" << endl;
				exit(0);
			}
			else if (!success) {
				cout << endl << "Sorry!! Something Wrong Here..." << endl << endl;
			}
			else {
				cout << endl << "New Altitude is " << helicopter.getAltitude() << endl << endl;
			}
			break;

		case 5:
			success = helicopter.flyToAltitude(helicopter.getAltitude() - helicopter.getAltitude());
			if (helicopter.getFuelLevel() <= 0 && helicopter.getAltitude() != 0) {
				helicopter.stopEngine();
				helicopter.flyToAltitude(helicopter.getAltitude() - helicopter.getAltitude());
				cout << endl << "Fuel Low level!!" << endl;
				exit(0);
			}
			else if (!success) {
				cout << endl << "Sorry!! Something Wrong Here..." << endl << endl;
			}
			else {
				cout << endl << "Altitude is " << helicopter.getAltitude() << endl << endl;
			}
			break;

		case 6:
			success = helicopter.refuel(100);
			if (!success) {
				cout << endl << "Sorry!! Something Wrong Here..." << endl << endl;
			}
			else {
				cout << endl << "Fuel Level is " << helicopter.getFuelLevel() << endl << endl;
			}
			break;

		case 7:
			cout << helicopter.toString() << endl << endl;
			break;

		case 8:
			cout << endl << "Thank you.." << endl << endl;
			exit(0);
			break;

		default:
			cout << endl << "Select Correct Options.." << endl << endl;
			break;
		}

	} while (select != 8);

	return 0;
}