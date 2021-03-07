#include <iostream>
#include <string>
#include "road.h"

using namespace std;

Road::Road() {
	zoneType = ' ';
	xCoord = -1;
	yCoord = -1;
}

Road::Road(char zone, int xPosition, int yPosition) {
	this->zoneType = zone;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
}

void Road::setZoneType(char zone) {
	this->zoneType = zone;
}

char Road::getZoneType() const {
	return zoneType;
}

void Road::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int Road::getXCoord() const {
	return xCoord;
}

void Road::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int Road::getYCoord() const {
	return yCoord;
}