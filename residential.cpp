#include <iostream>
#include <string>
#include "residential.h"

using namespace std;

Residential::Residential() {
	zoneType = 'R';
	residentialPosition = 0;
	residentialPopulation = 0;
	residentialPollution = 0;
}

Residential::Residential(char zone, int population, int pollution, int position) {
	this->zoneType = zone;
	this->residentialPosition = position;
	this->residentialPopulation = population;
	this->residentialPollution = pollution;
}

void Residential::setZoneType(char zone) {
	this->zoneType = zone;
}

char Residential::getZoneType() const {
	return zoneType;
}

void Residential::setPopulation(int population) {
	this->residentialPopulation = population;
}

int Residential::getPopulation() const {
	return residentialPopulation;
}

void Residential::setPollution(int pollution) {
	this->residentialPollution = pollution;
}

int Residential::getPollution() const {
	return residentialPollution;
}

void Residential::setPosition(int position) {
	this->residentialPosition = position;
}

int Residential::getPosition() const {
	return residentialPosition;
}