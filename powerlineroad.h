#ifndef POWERLINEROAD_H
#define POWERLINEROAD_H

//#include <string>
#include "city.h"

using namespace std;

class PowerlineRoad : public City {
public:
	//constructors
	PowerlineRoad();
	PowerlineRoad(char zone);
	//Sets
	void setZoneType(char zone);
	//Gets
	char getZoneType() const;
private:
	char zoneType;
};

#endif