#include <iostream>
#include <string>
#include "residential.h"

using namespace std;

Residential::Residential() {
	zoneType = 'R';
	residentialPopulation = 0;
	residentialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Residential::Residential(char zone, int population, int pollution, int xPosition, int yPosition) {
	this->zoneType = zone;
	this->residentialPopulation = population;
	this->residentialPollution = pollution;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
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

void Residential::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int Residential::getXCoord() const {
	return xCoord;
}

void Residential::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int Residential::getYCoord() const {
	return yCoord;
}

void Residential::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> Residential::getNeighbors() const {
	return neighbors;
}