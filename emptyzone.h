#ifndef EMPTYZONE_H
#define EMPTYZONE_H

//#include <string>
#include "city.h"

using namespace std;

class EmptyZone : public City {
public:
	//constructors
	EmptyZone();
	EmptyZone(char zone);
	//Sets
	void setZoneType(char zone);
	//Gets
	char getZoneType() const;
private:
	char zoneType;
};

#endif