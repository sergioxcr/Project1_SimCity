#ifndef COMMERCIAL_H
#define COMMERCIAL_H

//#include <string>
#include "city.h"

using namespace std;

class Commercial : public City {
public:
	//constructors
	Commercial();
	Commercial(char zone, int population, int pollution);
	//Sets
	void setZoneType(char zone);
	void setPopulation(int population);
	void setPollution(int pollution);
	//Gets
	int getPopulation() const;
	int getPollution() const;
	char getZoneType() const override;
private:
	int commercialPopulation;
	int commercialPollution;
	char zoneType;
};

#endif
