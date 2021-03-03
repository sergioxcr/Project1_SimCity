#ifndef ROAD_H
#define ROAD_H

//#include <string>
#include "city.h"

using namespace std;

class Road : public City {
public:
	//constructors
	Road();
	Road(char zone);
	//Sets
	void setZoneType(char zone);
	//Gets
	char getZoneType() const;
private:
	char zoneType;
};

#endif