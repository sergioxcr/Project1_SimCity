#include <iostream>
#include <string>
#include "powerplant.h"

using namespace std;

Powerplant::Powerplant() {
	zoneType = 'P';
}

Powerplant::Powerplant(char zone) {
	this->zoneType = zone;
}

void Powerplant::setZoneType(char zone) {
	this->zoneType = zone;
}

char Powerplant::getZoneType() const {
	return zoneType;
}