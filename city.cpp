#include <iostream>
#include <string>
#include "city.h"

using namespace std;

City::City() {
	int position;
}

City::City(int location) {
	this->position = location;
}

void City::setPosition(int location) {
	this->position;
}

char City::getZoneType() const {
	return zoneType;
}

int City::getPopulation() const {
	return population;
}

int City::getPollution() const {
	return pollution;
}

int City::getPosition() const {
	return position;
}