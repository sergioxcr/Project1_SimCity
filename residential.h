#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Residential : public City {
	public:
		//constructors
		Residential();
		Residential(char zone, int population, int pollution);
		//Sets
		void setZoneType(char zone);
		void setPopulation(int population);
		void setPollution(int pollution);
		//Gets
		int getPopulation() const;
		int getPollution() const;
		char getZoneType() const;
	private:
		int residnetialPopulation;
		int residentialPollution;
		char zoneType;
};

#endif