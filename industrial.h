#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Industrial : public City {
public:
	//constructors
	Industrial();
	Industrial(char zone, int population, int pollution);
	//Sets
	void setZoneType(char zone);
	void setPopulation(int population);
	void setPollution(int pollution);
	//Gets
	int getPopulation() const;
	int getPollution() const;
	char getZoneType() const;
private:
	int industrialPopulation;
	int industrialPollution;
	char zoneType;
};

#endif
