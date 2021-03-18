#include <iostream>
#include <string>
#include "emptyzone.h"

using namespace std;

EmptyZone::EmptyZone() {
	zoneType = ' ';
	hasGrown = 'N';
	emptyIndex = 0;
	xCoord = -1;
	yCoord = -1;
}

EmptyZone::EmptyZone(char zone, int xPosition, int yPosition, int index, char grown) {
	this->zoneType = zone;
	this->emptyIndex = index;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
	this->hasGrown = grown;
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

void EmptyZone::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> EmptyZone::getNeighbors() const {
	return neighbors;
}

void EmptyZone::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> EmptyZone::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void EmptyZone::clearNeighborsPopulation() {
	neighborsPopulation.clear();
}

void EmptyZone::setIndex(int index) {
	this->emptyIndex = index;
}

int EmptyZone::getIndex() const {
	return emptyIndex;
}

void EmptyZone::setGrown(char grown) {
	this->hasGrown = grown;
}

char EmptyZone::getGrown() const {
	return hasGrown;
}