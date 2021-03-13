#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Residential : public City {
	public:
		//constructors
		Residential();
		Residential(char zone, int population, int pollution, int xPosition, int yPosition, int index);
		//Sets
		void setZoneType(char zone);
		void setPopulation(int population);
		void setPollution(int pollution);
		void setIndex(int index);
		void setXCoord(int xPosition);
		void setYCoord(int yPosition);
		void setNeighbor(char tmpZone);
		void setNeighborPopulation(int tmpPopulation);
		//Gets
		int getPopulation() const;
		int getPollution() const;
		int getIndex() const;
		int getXCoord() const;
		int getYCoord() const;
		char getZoneType() const;
		vector<char> getNeighbors() const;
		vector<int> getNeighborsPopulation() const;
		//Others
		void clearNeighborsPopulation();
	private:
		int residentialPopulation;
		int residentialPollution;
		int residentialIndex;
		int xCoord;
		int yCoord;
		char zoneType;
		vector<char>neighbors;
		vector<int>neighborsPopulation;
};

#endif