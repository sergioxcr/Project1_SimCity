#include <iostream>
#include <string>
#include "emptyzone.h"

using namespace std;

EmptyZone::EmptyZone() {
	zoneType = ' ';
	xCoord = -1;
	yCoord = -1;
}

EmptyZone::EmptyZone(char zone, int xPosition, int yPosition) {
	this->zoneType = zone;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
}

void EmptyZone::setZoneType(char zone) {
	this->zoneType = zone;
}

char EmptyZone::getZoneType() const {
	return zoneType;
}

void EmptyZone::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int EmptyZone::getXCoord() const {
	return xCoord;
}

void EmptyZone::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int EmptyZone::getYCoord() const {
	return yCoord;
}