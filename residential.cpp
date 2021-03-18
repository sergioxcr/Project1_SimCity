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

//checks all rules to increase commercial population by 1
void increaseResidential(vector<vector<City*>>& tmpRegion, City& tmpResources) {
	vector<City*> canGrow;
	vector<char> neighbors;
	vector<int> neighborsPopulation;
	int index = -1;

	for (auto& row : tmpRegion) {
		for (auto& cell : row) {
			neighbors = cell->getNeighbors();
			neighborsPopulation = cell->getNeighborsPopulation();
			if (cell->getZoneType() == 'R') {
				if (cell->getPopulation() == 0 && isPowerlineAdjacent(neighbors) == true && cell->getGrown() == 'N') {
					cell->setPopulation(cell->getPopulation() + 1);
					tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
					tmpResources.setResPopulation(tmpResources.getResPopulation() + 1);
					tmpResources.setNumWorkers(tmpResources.getWorkers() + 1);
				}
				else if (cell->getPopulation() == 0 && isPopulationAdjacent(neighborsPopulation, 1) > 0 && cell->getGrown() == 'N') {
					cell->setPopulation(cell->getPopulation() + 1);
					tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
					tmpResources.setResPopulation(tmpResources.getResPopulation() + 1);
					tmpResources.setNumWorkers(tmpResources.getWorkers() + 1);
				}
				else if (cell->getPopulation() == 1 && isPopulationAdjacent(neighborsPopulation, 1) > 1 && cell->getGrown() == 'N') {
					cell->setPopulation(cell->getPopulation() + 1);
					tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
					tmpResources.setResPopulation(tmpResources.getResPopulation() + 1);
					tmpResources.setNumWorkers(tmpResources.getWorkers() + 1);
				}
				else if (cell->getPopulation() == 2 && isPopulationAdjacent(neighborsPopulation, 2) > 3 && cell->getGrown() == 'N') {
					cell->setPopulation(cell->getPopulation() + 1);
					tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
					tmpResources.setResPopulation(tmpResources.getResPopulation() + 1);
					tmpResources.setNumWorkers(tmpResources.getWorkers() + 1);
				}
				else if (cell->getPopulation() == 3 && isPopulationAdjacent(neighborsPopulation, 3) > 5 && cell->getGrown() == 'N') {
					cell->setPopulation(cell->getPopulation() + 1);
					tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
					tmpResources.setResPopulation(tmpResources.getResPopulation() + 1);
					tmpResources.setNumWorkers(tmpResources.getWorkers() + 1);
				}
				else if (cell->getPopulation() == 4 && isPopulationAdjacent(neighborsPopulation, 4) > 7 && cell->getGrown() == 'N') {
					cell->setPopulation(cell->getPopulation() + 1);
					tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
					tmpResources.setResPopulation(tmpResources.getResPopulation() + 1);
					tmpResources.setNumWorkers(tmpResources.getWorkers() + 1);
				}
			}
			neighborsPopulation.clear();
		}
	}
/*
	if (canGrow.size() == 1) {
		for (auto& cell : canGrow) {
			index = cell->getIndex();
		}
	}
	else if (canGrow.size() > 1) {
		if (isLargerPopulation(canGrow) != -1) {
			index = isLargerPopulation(canGrow);
		}
		else if (totalAdjacentPopulation(canGrow) != -1) {
			index = totalAdjacentPopulation(canGrow);
		}
		else if (smallerXCoord(canGrow) != -1) {
			index = smallerXCoord(canGrow);
		}
		else if (smallerYCoord(canGrow) != -1) {
			index = smallerYCoord(canGrow);
		}
		else {
		}
	}
	increasePopulation(tmpRegion, index);
	alreadyGrew(tmpRegion, index);
*/
}