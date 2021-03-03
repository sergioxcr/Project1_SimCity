#ifndef POWERLINE_H
#define POWERLINE_H

//#include <string>
#include "city.h"

using namespace std;

class Powerline : public City {
public:
	//constructors
	Powerline();
	Powerline(char zone);
	//Sets
	void setZoneType(char zone);
	//Gets
	char getZoneType() const;
private:
	char zoneType;
};

#endif