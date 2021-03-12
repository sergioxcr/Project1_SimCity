#include <iostream>
#include <string>
#include "powerlineroad.h"

using namespace std;

PowerlineRoad::PowerlineRoad() {
	zoneType = '#';
	powerlineRoadIndex = 0;
	xCoord = -1;
	yCoord = -1;
}

PowerlineRoad::PowerlineRoad(char zone, int xPosition, int yPosition, int index) {
	this->zoneType = zone;
	this->powerlineRoadIndex = index;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
}

void PowerlineRoad::setZoneType(char zone) {
	this->zoneType = zone;
}

char PowerlineRoad::getZoneType() const {
	return zoneType;
}

void PowerlineRoad::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int PowerlineRoad::getXCoord() const {
	return xCoord;
}

void PowerlineRoad::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int PowerlineRoad::getYCoord() const {
	return yCoord;
}

void PowerlineRoad::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> PowerlineRoad::getNeighbors() const {
	return neighbors;
}

void PowerlineRoad::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> PowerlineRoad::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void PowerlineRoad::setIndex(int index) {
	this->powerlineRoadIndex = index;
}

int PowerlineRoad::getIndex() const {
	return powerlineRoadIndex;
}