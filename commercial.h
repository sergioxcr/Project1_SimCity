#ifndef COMMERCIAL_H
#define COMMERCIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Commercial : public City {
	public:
		//constructors
		Commercial();
		Commercial(char zone, int population, int pollution, int position);
		//Sets
		void setZoneType(char zone);
		void setPopulation(int population);
		void setPollution(int pollution);
		void setPosition(int position);
		//Gets
		int getPopulation() const;
		int getPollution() const;
		int getPosition() const;
		char getZoneType() const override;
	private:
		int commercialPopulation;
		int commercialPollution;
		int commercialPosition;
		char zoneType;
};

#endif
