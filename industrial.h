#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Industrial : public City {
	public:
		//constructors
		Industrial();
		Industrial(char zone, int population, int pollution, int xPosition, int yPosition, int index, char grown);
		//Sets
		void setZoneType(char zone);
		void setPopulation(int population);
		void setPollution(int pollution);
		void setIndex(int index);
		void setXCoord(int xPosition);
		void setYCoord(int yPosition);
		void setNeighbor(char tmpZone);
		void setNeighborPopulation(int tmpPopulation);
		void setGrown(char grown);
		//Gets
		int getPopulation() const;
		int getPollution() const;
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
		int industrialPopulation;
		int industrialPollution;
		int industrialIndex;
		int xCoord;
		int yCoord;
		char zoneType;
		char hasGrown;
		vector<char>neighbors;
		vector<int>neighborsPopulation;
};

#endif
