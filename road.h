#ifndef ROAD_H
#define ROAD_H

//#include <string>
#include "city.h"

using namespace std;

class Road : public City {
public:
	//constructors
	Road();
	Road(char zone, int xPosition, int yPosition);
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