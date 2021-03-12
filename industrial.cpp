#include <iostream>
#include <string>
#include "industrial.h"

using namespace std;

Industrial::Industrial() {
	zoneType = 'I';
	industrialIndex = 0;
	industrialPopulation = 0;
	industrialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Industrial::Industrial(char zone, int population, int pollution, int xPosition, int yPosition, int index) {
	this->zoneType = zone;
	this->industrialIndex = index;
	this->industrialPopulation = population;
	this->industrialPollution = pollution;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
}

void Industrial::setZoneType(char zone) {
	this->zoneType = zone;
}

char Industrial::getZoneType() const {
	return zoneType;
}

void Industrial::setPopulation(int population) {
	this->industrialPopulation = population;
}

int Industrial::getPopulation() const {
	return industrialPopulation;
}

void Industrial::setPollution(int pollution) {
	this->industrialPollution = pollution;
}

int Industrial::getPollution() const {
	return industrialPollution;
}

void Industrial::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int Industrial::getXCoord() const {
	return xCoord;
}

void Industrial::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int Industrial::getYCoord() const {
	return yCoord;
}

void Industrial::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> Industrial::getNeighbors() const {
	return neighbors;
}

void Industrial::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> Industrial::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void Industrial::setIndex(int index) {
	this->industrialIndex = index;
}

int Industrial::getIndex() const {
	return industrialIndex;
}