#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Industrial : public City {
	public:
		//constructors
		Industrial();
		Industrial(char zone, int population, int pollution, int xPosition, int yPosition);
		//Sets
		void setZoneType(char zone);
		void setPopulation(int population);
		void setPollution(int pollution);
		void setXCoord(int xPosition);
		void setYCoord(int yPosition);
		void setNeighbor(char tmpZone);
		//Gets
		int getPopulation() const;
		int getPollution() const;
		int getXCoord() const;
		int getYCoord() const;
		char getZoneType() const;
		vector<char> getNeighbors() const;
	private:
		int industrialPopulation;
		int industrialPollution;
		int xCoord;
		int yCoord;
		char zoneType;
		vector<char>neighbors;
};

#endif
