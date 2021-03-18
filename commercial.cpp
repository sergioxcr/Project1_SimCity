#include <iostream>
#include <string>
#include "commercial.h"

using namespace std;

Commercial::Commercial() {
	zoneType = 'C';
	hasGrown = 'N';
	commercialIndex = 0;
	commercialPopulation = 0;
	commercialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Commercial::Commercial(char zone, int population, int pollution, int xPosition, int yPosition, int index, char grown) {
	this->zoneType = zone;
	this->commercialIndex = index;
	this->commercialPopulation = population;
	this->commercialPollution = pollution;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
	this->hasGrown = grown;
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

void Commercial::clearNeighborsPopulation() {
	neighborsPopulation.clear();
}

void Commercial::setIndex(int index) {
	this->commercialIndex = index;
}

int Commercial::getIndex() const {
	return commercialIndex;
}

void Commercial::setGrown(char grown) {
	this->hasGrown = grown;
}

char Commercial::getGrown() const {
	return hasGrown;
}

//checks all rules to increase commercial population by 1
void increaseCommercial(vector<vector<City*>> &tmpRegion, City &tmpResources, bool &isDone) {
	vector<City*> canGrow;
	vector<char> neighbors;
	vector<int> neighborsPopulation;
	int index = -1;

	if (tmpResources.getWorkers() > 0 && tmpResources.getGoods() > 0) {
		for (auto& row : tmpRegion) {
			for (auto& cell : row) {
				neighbors = cell->getNeighbors();
				neighborsPopulation = cell->getNeighborsPopulation();
				if (cell->getZoneType() == 'C') {
					if (cell->getPopulation() == 0 && isPowerlineAdjacent(neighbors) == true && cell->getGrown() == 'N') {
						canGrow.push_back(cell);
					}
					else if (cell->getPopulation() == 0 && isPopulationAdjacent(neighborsPopulation, 1) > 0 && cell->getGrown() == 'N') {
						canGrow.push_back(cell);
					}
					else if (cell->getPopulation() == 1 && isPopulationAdjacent(neighborsPopulation, 1) > 1 && cell->getGrown() == 'N') {
						canGrow.push_back(cell);
					}
				}
				neighborsPopulation.clear();
			}
		}
		if (canGrow.size() == 0) {
			isDone = true;
			return;
		}
		else if (canGrow.size() == 1) {
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

		tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
		tmpResources.setComPopulation(tmpResources.getComPopulation() + 1);
		tmpResources.setNumWorkers(tmpResources.getWorkers() - 1);
		tmpResources.setNumGoods(tmpResources.getGoods() - 1);
	}
}