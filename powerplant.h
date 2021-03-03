#ifndef POWERPLANT_H
#define POWERPLANT_H

//#include <string>
#include "city.h"

using namespace std;

class Powerplant : public City {
public:
	//constructors
	Powerplant();
	Powerplant(char zone);
	//Sets
	void setZoneType(char zone);
	//Gets
	char getZoneType() const;
private:
	char zoneType;
};

#endif