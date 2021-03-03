#include <iostream>
#include <string>
#include "road.h"

using namespace std;

Road::Road() {
	zoneType = '-';
}

Road::Road(char zone) {
	this->zoneType = zone;
}

void Road::setZoneType(char zone) {
	this->zoneType = zone;
}

char Road::getZoneType() const {
	return zoneType;
}