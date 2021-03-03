#include <iostream>
#include <string>
#include "powerlineroad.h"

using namespace std;

PowerlineRoad::PowerlineRoad() {
	zoneType = '#';
}

PowerlineRoad::PowerlineRoad(char zone) {
	this->zoneType = zone;
}

void PowerlineRoad::setZoneType(char zone) {
	this->zoneType = zone;
}

char PowerlineRoad::getZoneType() const {
	return zoneType;
}