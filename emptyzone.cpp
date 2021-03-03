#include <iostream>
#include <string>
#include "emptyzone.h"

using namespace std;

EmptyZone::EmptyZone() {
	zoneType = ' ';
}

EmptyZone::EmptyZone(char zone) {
	this->zoneType = zone;
}

void EmptyZone::setZoneType(char zone) {
	this->zoneType = zone;
}

char EmptyZone::getZoneType() const {
	return zoneType;
}