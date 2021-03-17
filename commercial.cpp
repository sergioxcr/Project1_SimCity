#include <iostream>
#include <string>
#include "commercial.h"

using namespace std;



Commercial::Commercial() {
	zoneType = 'C';
	commercialIndex = 0;
	commercialPopulation = 0;
	commercialPollution = 0;
	xCoord = -1;
	yCoord = -1;
}

Commercial::Commercial(char zone, int population, int pollution, int xPosition, int yPosition, int index) {
	this->zoneType = zone;
	this->commercialIndex = index;
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

void Commercial::clearNeighborsPopulation() {
	neighborsPopulation.clear();
}

void Commercial::setIndex(int index) {
	this->commercialIndex = index;
}

int Commercial::getIndex() const {
	return commercialIndex;
}

//checks all rules to increase commercial population by 1
void increaseCommercial(vector<vector<City*>> &tmpRegion, City &tmpResources) {
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
					if (cell->getPopulation() == 0 && isPowerlineAdjacent(neighbors) == true) {
						canGrow.push_back(cell);
					}
					else if (cell->getPopulation() == 0 && isPopulationAdjacent(neighborsPopulation) > 0) {
						canGrow.push_back(cell);
					}
					else if (cell->getPopulation() == 1 && isPopulationAdjacent(neighborsPopulation) > 1) {
						canGrow.push_back(cell);
					}
					else
						cout << cell->getIndex() << endl;
				}
				neighborsPopulation.clear();
			}
		}

		if (canGrow.size() == 1) {
			for (auto& cell : canGrow) {
				index = cell->getIndex();
				increasePopulation(tmpRegion, index);
			}
		}
		else if (canGrow.size() > 1) {
			if (isLargerPopulation(canGrow) != -1) { 
				index = isLargerPopulation(canGrow);
				increasePopulation(tmpRegion, index);
			}
			else if (totalAdjacentPopulation(canGrow) != -1) {
				index = totalAdjacentPopulation(canGrow);
				increasePopulation(tmpRegion, index);
			}
			else if (smallerXCoord(canGrow) != -1) {
				index = smallerXCoord(canGrow);
				increasePopulation(tmpRegion, index);
			} 
			else if (smallerYCoord(canGrow) != -1) {
				index = smallerYCoord(canGrow);
				increasePopulation(tmpRegion, index);
			}
			else {
			}
		}
		tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
		tmpResources.setComPopulation(tmpResources.getComPopulation() + 1);
		tmpResources.setNumWorkers(tmpResources.getWorkers() - 1);
		tmpResources.setNumGoods(tmpResources.getGoods() - 1);
	}
}

//checks to see if there is a powerline adjacent to current zone
bool isPowerlineAdjacent(vector<char> neighbors) {
	for (unsigned int i = 0; i < neighbors.size(); i++)
	{
		if (neighbors[i] == 'T' || neighbors[i] == '#') {
			return true;
		}
	}

	return false;
}

//checks to see if there are adjacent zones with population and returns the number of zones with a population greater than 0
int isPopulationAdjacent(vector<int> neighbors) {
	int numCells = 0;

	for (unsigned int i = 0; i < neighbors.size(); i++)
	{
		if (neighbors[i] > 0) {
			numCells++;
		}
	}

	return numCells;
}

//checks which zone has a greater number of 
int totalAdjacentPopulation(vector<City*> &tmpRegion) {
	int index = -1;
	int totalPopulation = 0;
	int tmpTotalPopulation = 0;
	vector<int> neighbors;
	vector<City*> canGrow;

	for (auto& cell : tmpRegion) {
		totalPopulation = 0;
		neighbors = cell->getNeighborsPopulation();
		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			if (neighbors[i] > 0) {
				totalPopulation = totalPopulation + neighbors[i];
			}
		}
		if (totalPopulation > tmpTotalPopulation) {
			index = cell->getIndex();
			tmpTotalPopulation = totalPopulation;
		}
		else if (totalPopulation == tmpTotalPopulation) {
			index = -1;
		}
		neighbors.clear();
	}
	if (index == -1) {
		for (auto& cell : tmpRegion) {
			totalPopulation = 0;
			neighbors = cell->getNeighborsPopulation();
			for (unsigned int i = 0; i < neighbors.size(); i++)
			{
				if (neighbors[i] > 0) {
					totalPopulation = totalPopulation + neighbors[i];
				}
			}
			if (totalPopulation == tmpTotalPopulation) {
				canGrow.push_back(cell);
			}
			neighbors.clear();
		}
		tmpRegion = canGrow;
	}
	return index;
}

int smallerYCoord(vector<City*> &tmpRegion) {
	int index = -1;
	int tmpYCoord = 0;
	vector<City*> canGrow;

	for (auto& cell : tmpRegion) {
		if (cell->getYCoord() >= tmpYCoord) {
			tmpYCoord = cell->getYCoord() + 1;
		}
	}

	for (auto& cell : tmpRegion) {
		if (cell->getYCoord() < tmpYCoord) {
			index = cell->getIndex();
			tmpYCoord = cell->getYCoord();
		}
		else if (cell->getYCoord() == tmpYCoord) {
			index = -1;
		}
	}

	if (index == -1) {
		for (auto& cell : tmpRegion) {
			if (cell->getYCoord() == tmpYCoord) {
				canGrow.push_back(cell);
			}
		}
		tmpRegion = canGrow;
	}

	return index;
}

int smallerXCoord(vector<City*> &tmpRegion) {
	int index = -1;
	int tmpXCoord = 0;
	vector<City*> canGrow;

	for (auto& cell : tmpRegion) {
		if (cell->getXCoord() >= tmpXCoord) {
			tmpXCoord = cell->getXCoord() + 1;
		}
	}

	for (auto& cell : tmpRegion) {
		if (cell->getXCoord() < tmpXCoord) {
			index = cell->getIndex();
			tmpXCoord = cell->getXCoord();
		}
		else if (cell->getXCoord() == tmpXCoord) {
			index = -1;
		}
	}

	if (index == -1) {
		for (auto& cell : tmpRegion) {
			if (cell->getXCoord() == tmpXCoord) {
				canGrow.push_back(cell);
			}
		}
		tmpRegion = canGrow;
	}

	return index;
}