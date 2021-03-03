#include <iostream>
#include <string>
#include "industrial.h"

using namespace std;

Industrial::Industrial() {
	zoneType = 'I';
	industrialPopulation = 0;
	industrialPollution = 0;
}

Industrial::Industrial(char zone, int population, int pollution) {
	this->zoneType = zone;
	this->industrialPopulation = population;
	this->industrialPollution = pollution;
}

void Industrial::setZoneType(char zone) {
	this->zoneType = zone;
}

char Industrial::getZoneType() const {
	return zoneType;
}

void Industrial::setPopulation(int population) {
	this->industrialPopulation = population;
}

int Industrial::getPopulation() const {
	return industrialPopulation;
}

void Industrial::setPollution(int pollution) {
	this->industrialPollution = pollution;
}

int Industrial::getPollution() const {
	return industrialPollution;
}