#include <iostream>
#include <string>
#include "industrial.h"

using namespace std;

Industrial::Industrial() {
	zoneType = 'I';
	hasGrown = 'N';
	industrialIndex = 0;
	industrialPopulation = 0;
	industrialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Industrial::Industrial(char zone, int population, int pollution, int xPosition, int yPosition, int index, char grown) {
	this->zoneType = zone;
	this->industrialIndex = index;
	this->industrialPopulation = population;
	this->industrialPollution = pollution;
	this->xCoord = xPosition;
	this->yCoord = yPosition;
	this->hasGrown = grown;
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

void Industrial::clearNeighborsPopulation() {
	neighborsPopulation.clear();
}

void Industrial::setIndex(int index) {
	this->industrialIndex = index;
}

int Industrial::getIndex() const {
	return industrialIndex;
}

void Industrial::setGrown(char grown) {
	this->hasGrown = grown;
}

char Industrial::getGrown() const {
	return hasGrown;
}

void increaseIndustrial(vector<vector<City*>>& tmpRegion, City& tmpResources, bool &isDone) {
	vector<City*> canGrow;
	vector<char> neighbors;
	vector<int> neighborsPopulation;
	int index = -1;

	if (tmpResources.getWorkers() > 1) {
		for (auto& row : tmpRegion) {
			for (auto& cell : row) {
				neighbors = cell->getNeighbors();
				neighborsPopulation = cell->getNeighborsPopulation();
				if (cell->getZoneType() == 'I') {
					if (cell->getPopulation() == 0 && isPowerlineAdjacent(neighbors) == true && cell->getGrown() == 'N') {
						canGrow.push_back(cell);
					}
					else if (cell->getPopulation() == 0 && isPopulationAdjacent(neighborsPopulation, 1) > 0 && cell->getGrown() == 'N') {
						canGrow.push_back(cell);
					}
					else if (cell->getPopulation() == 1 && isPopulationAdjacent(neighborsPopulation, 1) > 1 && cell->getGrown() == 'N') {
						canGrow.push_back(cell);
					}
					else if (cell->getPopulation() == 2 && isPopulationAdjacent(neighborsPopulation, 2) > 3 && cell->getGrown() == 'N') {
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
		}
		increasePopulation(tmpRegion, index);
		alreadyGrew(tmpRegion, index);

		tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
		tmpResources.setIndPopulation(tmpResources.getIndPopulation() + 1);
		tmpResources.setNumWorkers(tmpResources.getWorkers() - 2);
		tmpResources.setNumGoods(tmpResources.getGoods() + 1);
	}
}