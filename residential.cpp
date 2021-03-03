#include <iostream>
#include <string>
#include "residential.h"

using namespace std;

Residential::Residential() {
	zoneType = 'R';
	residnetialPopulation = 0;
	residentialPollution = 0;
}

Residential::Residential(char zone, int population, int pollution) {
	this->zoneType = zone;
	this->residnetialPopulation = population;
	this->residentialPollution = pollution;
}

void Residential::setZoneType(char zone) {
	this->zoneType = zone;
}

char Residential::getZoneType() const {
	return zoneType;
}

void Residential::setPopulation(int population) {
	this->residnetialPopulation = population;
}

int Residential::getPopulation() const {
	return residnetialPopulation;
}

void Residential::setPollution(int pollution) {
	this->residentialPollution = pollution;
}

int Residential::getPollution() const {
	return residentialPollution;
}