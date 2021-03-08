#include <iostream>
#include <string>
#include "commercial.h"

using namespace std;

Commercial::Commercial() {
	zoneType = 'C';
	commercialPopulation = 0;
	commercialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Commercial::Commercial(char zone, int population, int pollution, int xPosition, int yPosition) {
	this->zoneType = zone;
	this->commercialPopulation = population;
	this->commercialPollution = pollution;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
}

void Commercial::setZoneType(char zone) {
	this->zoneType = zone;
}

char Commercial::getZoneType() const {
	return zoneType;
}

void Commercial::setPopulation(int population) {
	this->commercialPopulation = population;
}

int Commercial::getPopulation() const {
	return commercialPopulation;
}

void Commercial::setPollution(int pollution) {
	this->commercialPollution = pollution;
}

int Commercial::getPollution() const {
	return commercialPollution;
}

void Commercial::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int Commercial::getXCoord() const {
	return xCoord;
}

void Commercial::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int Commercial::getYCoord() const {
	return yCoord;
}

void Commercial::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> Commercial::getNeighbors() const {
	return neighbors;
}

void Commercial::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> Commercial::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void increaseCommercial(vector<vector<City*>> &tmpRegion, City &tmpResources) {
	vector<City*> canGrowRule1, canGrowRule2, canGrowRule3;
	vector<char> neighbors;
	int flag = 0;

	if (tmpResources.getWorkers() > 0 && tmpResources.getGoods() > 0) {
		for (auto& row : tmpRegion) {
			for (auto& cell : row) {
				neighbors = cell->getNeighbors();
				if (cell->getZoneType() == 'C') {
					if (cell->getPopulation() == 0 && isPowerlineAdjacent(neighbors) == true) {
						canGrowRule1.push_back(cell);
						flag = 1;
					}
					else if (cell->getPopulation() == 0 && isPopulationAdjacent(neighbors) == true) {

					}
				}
			}
		}
	}
}
//if (isLargerPopulation(tmpRegion, cell->getPopulation(), cell->getZoneType()) == true) {

//cell->setPopulation(cell->getPopulation() + 1);

bool isPowerlineAdjacent(vector<char> neighbors) {
	for (int i = 0; i < neighbors.size(); i++)
	{
		if (neighbors[i] == 'T') {
			return true;
		}
	}

	return false;
}
