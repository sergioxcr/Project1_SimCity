#include <iostream>
#include <string>
#include "residential.h"

using namespace std;

Residential::Residential() {
	zoneType = 'R';
	hasGrown = 'N';
	residentialIndex = 0;
	residentialPopulation = 0;
	residentialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Residential::Residential(char zone, int population, int pollution, int xPosition, int yPosition, int index, char grown) {
	this->zoneType = zone;
	this->residentialIndex = index;
	this->residentialPopulation = population;
	this->residentialPollution = pollution;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
	this->hasGrown = grown;
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

void Residential::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> Residential::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void Residential::clearNeighborsPopulation() {
	neighborsPopulation.clear();
}

void Residential::setIndex(int index) {
	this->residentialIndex = index;
}

int Residential::getIndex() const {
	return residentialIndex;
}

void Residential::setGrown(char grown) {
	this->hasGrown = grown;
}

char Residential::getGrown() const {
	return hasGrown;
}