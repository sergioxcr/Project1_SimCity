#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Residential : public City {
	public:
		//constructors
		Residential();
		Residential(char zone, int population, int pollution, int position);
		//Sets
		void setZoneType(char zone);
		void setPopulation(int population);
		void setPollution(int pollution);
		void setPosition(int position);
		//Gets
		int getPopulation() const;
		int getPollution() const;
		int getPosition() const;
		char getZoneType() const;
	private:
		int residentialPopulation;
		int residentialPollution;
		int residentialPosition;
		char zoneType;
};

#endif