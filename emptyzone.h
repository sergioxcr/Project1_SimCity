#ifndef EMPTYZONE_H
#define EMPTYZONE_H

//#include <string>
#include "city.h"

using namespace std;

class EmptyZone : public City {
	public:
		//constructors
		EmptyZone();
		EmptyZone(char zone, int xPosition, int yPosition);
		//Sets
		void setZoneType(char zone);
		void setXCoord(int xPosition);
		void setYCoord(int yPosition);
		void setNeighbor(char tmpZone);
		void setNeighborPopulation(int tmpPopulation);
		//Gets
		int getXCoord() const;
		int getYCoord() const;
		char getZoneType() const;
		vector<char> getNeighbors() const;
		vector<int> getNeighborsPopulation() const;
	private:
		int xCoord;
		int yCoord;
		char zoneType;
		vector<char>neighbors;
		vector<int>neighborsPopulation;
};

#endif