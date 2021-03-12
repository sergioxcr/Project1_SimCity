#include <iostream>
#include <string>
#include "powerplant.h"

using namespace std;

Powerplant::Powerplant() {
	zoneType = 'P';
	powerplantIndex = 0;
	xCoord = -1;
	yCoord = -1;
}

Powerplant::Powerplant(char zone, int xPosition, int yPosition, int index) {
	this->zoneType = zone;
	this->powerplantIndex = index;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
}

void Powerplant::setZoneType(char zone) {
	this->zoneType = zone;
}

char Powerplant::getZoneType() const {
	return zoneType;
}

void Powerplant::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int Powerplant::getXCoord() const {
	return xCoord;
}

void Powerplant::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int Powerplant::getYCoord() const {
	return yCoord;
}

void Powerplant::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> Powerplant::getNeighbors() const {
	return neighbors;
}

void Powerplant::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> Powerplant::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void Powerplant::setIndex(int index) {
	this->powerplantIndex = index;
}

int Powerplant::getIndex() const {
	return powerplantIndex;
}