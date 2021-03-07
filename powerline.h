#ifndef POWERLINE_H
#define POWERLINE_H

//#include <string>
#include "city.h"

using namespace std;

class Powerline : public City {
public:
	//constructors
	Powerline();
	Powerline(char zone, int xPosition, int yPosition);
	//Sets
	void setZoneType(char zone);
	void setXCoord(int xPosition);
	void setYCoord(int yPosition);
	void setNeighbor(char tmpZone);
	//Gets
	int getXCoord() const;
	int getYCoord() const;
	char getZoneType() const;
	vector<char> getNeighbors() const;
private:
	int xCoord;
	int yCoord;
	char zoneType;
	vector<char>neighbors;
};

#endif