#include <iostream>
#include <string>
#include "powerplant.h"

using namespace std;

Powerplant::Powerplant() {
	zoneType = 'P';
	xCoord = -1;
	yCoord = -1;
}

Powerplant::Powerplant(char zone, int xPosition, int yPosition) {
	this->zoneType = zone;
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