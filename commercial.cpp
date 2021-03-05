#include <iostream>
#include <string>
#include "commercial.h"

using namespace std;

Commercial::Commercial() {
	zoneType = 'C';
	commercialPosition = 0;
	commercialPopulation = 0;
	commercialPollution = 0;
}

Commercial::Commercial(char zone, int population, int pollution, int position) {
	this->zoneType = zone;
	this->commercialPosition = position;
	this->commercialPopulation = population;
	this->commercialPollution = pollution;
}

void Commercial::setZoneType(char zone) {
	this->zoneType = zone;
}

char Commercial::getZoneType() const {
	return zoneType;
}

void Commercial::setPopulation(int population) {
	this->commercialPopulation = population;
}

int Commercial::getPopulation() const {
	return commercialPopulation;
}

void Commercial::setPollution(int pollution) {
	this->commercialPollution = pollution;
}

int Commercial::getPollution() const {
	return commercialPollution;
}

void Commercial::setPosition(int position) {
	this->commercialPosition = position;
}

int Commercial::getPosition() const {
	return commercialPosition;
}