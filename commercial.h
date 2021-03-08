#ifndef COMMERCIAL_H
#define COMMERCIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Commercial : public City {
	public:
		//constructors
		Commercial();
		Commercial(char zone, int population, int pollution, int xPosition, int yPosition);
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
		char getZoneType() const override;
		vector<char> getNeighbors() const;
	private:
		int commercialPopulation;
		int commercialPollution;
		int xCoord;
		int yCoord;
		char zoneType;
		vector<char>neighbors;
};

void increaseCommercial(vector<vector<City*>> &, City &);

#endif
