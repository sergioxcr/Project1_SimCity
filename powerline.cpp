#include <iostream>
#include <string>
#include "powerline.h"

using namespace std;

Powerline::Powerline() {
	zoneType = 'T';
	xCoord = -1;
	yCoord = -1;
}

Powerline::Powerline(char zone, int xPosition, int yPosition) {
	this->zoneType = zone;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
}

void Powerline::setZoneType(char zone) {
	this->zoneType = zone;
}

char Powerline::getZoneType() const {
	return zoneType;
}

void Powerline::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int Powerline::getXCoord() const {
	return xCoord;
}

void Powerline::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int Powerline::getYCoord() const {
	return yCoord;
}

void Powerline::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> Powerline::getNeighbors() const {
	return neighbors;
}

void Powerline::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> Powerline::getNeighborsPopulation() const {
	return neighborsPopulation;
}