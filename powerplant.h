#ifndef POWERPLANT_H
#define POWERPLANT_H

//#include <string>
#include "city.h"

using namespace std;

class Powerplant : public City {
public:
	//constructors
	Powerplant();
	Powerplant(char zone, int xPosition, int yPosition);
	//Sets
	void setZoneType(char zone);
	void setXCoord(int xPosition);
	void setYCoord(int yPosition);
	//Gets
	int getXCoord() const;
	int getYCoord() const;
	char getZoneType() const;
private:
	int xCoord;
	int yCoord;
	char zoneType;
};

#endif