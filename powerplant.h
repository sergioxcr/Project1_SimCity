#ifndef POWERPLANT_H
#define POWERPLANT_H

//#include <string>
#include "city.h"

using namespace std;

class Powerplant : public City {
public:
	//constructors
	Powerplant();
	Powerplant(char zone, int xPosition, int yPosition, int index, char grown);
	//Sets
	void setZoneType(char zone);
	void setIndex(int index);
	void setXCoord(int xPosition);
	void setYCoord(int yPosition);
	void setNeighbor(char tmpZone);
	void setNeighborPopulation(int tmpPopulation);
	void setGrown(char grown);
	//Gets
	int getIndex() const;
	int getXCoord() const;
	int getYCoord() const;
	char getZoneType() const;
	char getGrown() const;
	vector<char> getNeighbors() const;
	vector<int> getNeighborsPopulation() const;
	//Others
	void clearNeighborsPopulation();
private:
	int powerplantIndex;
	int xCoord;
	int yCoord;
	char zoneType;
	char hasGrown;
	vector<char>neighbors;
	vector<int>neighborsPopulation;
};

#endif