#include <iostream>
#include <string>
#include "commercial.h"

using namespace std;

Commercial::Commercial() {
	zoneType = 'C';
	commercialPopulation = 0;
	commercialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Commercial::Commercial(char zone, int population, int pollution, int xPosition, int yPosition) {
	this->zoneType = zone;
	this->commercialPopulation = population;
	this->commercialPollution = pollution;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
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

void Commercial::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int Commercial::getXCoord() const {
	return xCoord;
}

void Commercial::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int Commercial::getYCoord() const {
	return yCoord;
}

void Commercial::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> Commercial::getNeighbors() const {
	return neighbors;
}
