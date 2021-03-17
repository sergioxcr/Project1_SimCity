#include <iostream>
#include <string>
#include "road.h"

using namespace std;

Road::Road() {
	zoneType = '-';
	hasGrown = 'N';
	roadIndex = 0;
	xCoord = -1;
	yCoord = -1;
}

Road::Road(char zone, int xPosition, int yPosition, int index, char grown) {
	this->zoneType = zone;
	this->roadIndex = index;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
	this->hasGrown = grown;
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

void Road::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> Road::getNeighbors() const {
	return neighbors;
}

void Road::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> Road::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void Road::clearNeighborsPopulation() {
	neighborsPopulation.clear();
}

void Road::setIndex(int index) {
	this->roadIndex = index;
}

int Road::getIndex() const {
	return roadIndex;
}

void Road::setGrown(char grown) {
	this->hasGrown = grown;
}

char Road::getGrown() const {
	return hasGrown;
}