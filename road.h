#ifndef ROAD_H
#define ROAD_H

//#include <string>
#include "city.h"

using namespace std;

class Road : public City {
public:
	//constructors
	Road();
	Road(char zone, int xPosition, int yPosition, int index);
	//Sets
	void setZoneType(char zone);
	void setIndex(int index);
	void setXCoord(int xPosition);
	void setYCoord(int yPosition);
	void setNeighbor(char tmpZone);
	void setNeighborPopulation(int tmpPopulation);
	//Gets
	int getIndex() const;
	int getXCoord() const;
	int getYCoord() const;
	char getZoneType() const;
	vector<char> getNeighbors() const;
	vector<int> getNeighborsPopulation() const;
private:
	int roadIndex;
	int xCoord;
	int yCoord;
	char zoneType;
	vector<char>neighbors;
	vector<int>neighborsPopulation;
};
#endif