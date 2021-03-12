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

void Commercial::setIndex(int index) {
	this->commercialIndex = index;
}

int Commercial::getIndex() const {
	return commercialIndex;
}

void increaseCommercial(vector<vector<City*>> &tmpRegion, City &tmpResources) {
	vector<City*> canGrowRule1, canGrowRule2, canGrowRule3;
	vector<char> neighbors;
	vector<int> neighborsPopulation;
	int flag = 0;
	int index = -1;

	if (tmpResources.getWorkers() > 0 && tmpResources.getGoods() > 0) {
		for (auto& row : tmpRegion) {
			for (auto& cell : row) {
				neighbors = cell->getNeighbors();
				neighborsPopulation = cell->getNeighborsPopulation();
				if (cell->getZoneType() == 'C') {
					if (cell->getPopulation() == 0 && isPowerlineAdjacent(neighbors) == true) {
						canGrowRule1.push_back(cell);
						flag = 1;
					}
					else if (cell->getPopulation() == 0 && isPopulationAdjacent(neighborsPopulation) > 0 && flag != 1) {
						canGrowRule2.push_back(cell);
						flag = 2;
					}
					else if (cell->getPopulation() == 1 && isPopulationAdjacent(neighborsPopulation) > 1 && flag != 2) {
						canGrowRule3.push_back(cell);
						flag = 3;
					}
				}
			}
		}

		if (canGrowRule1.size() == 1) {
			for (auto& cell : canGrowRule1) {
				index = cell->getIndex();
				increasePopulation(tmpRegion, index);
			}
		}
		else if (canGrowRule1.size() > 1) {
			if (isLargerPopulation(canGrowRule1) != -1) {
				index = isLargerPopulation(canGrowRule1);
				increasePopulation(tmpRegion, index);
			}
			else if (totalAdjacentPopulation(canGrowRule1) != -1) {
				index = totalAdjacentPopulation(canGrowRule1);
				increasePopulation(tmpRegion, index);
			}
			else if (smallerYCoord(canGrowRule1) != -1) {
				index = smallerYCoord(canGrowRule1);
				increasePopulation(tmpRegion, index);
			}
			else if (smallerXCoord(canGrowRule1) != -1) {
				index = smallerXCoord(canGrowRule1);
				increasePopulation(tmpRegion, index);
			}
		}
		else if (canGrowRule2.size() == 1) {
			for (auto& cell : canGrowRule2) {
				index = cell->getIndex();
				increasePopulation(tmpRegion, index);
			}
		}
		else if (canGrowRule2.size() > 1) {
			if (isLargerPopulation(canGrowRule2) != -1) {
				index = isLargerPopulation(canGrowRule2);
				increasePopulation(tmpRegion, index);
			}
			else if (totalAdjacentPopulation(canGrowRule2) != -1) {
				index = totalAdjacentPopulation(canGrowRule2);
				increasePopulation(tmpRegion, index);
			}
			else if (smallerYCoord(canGrowRule2) != -1) {
				index = smallerYCoord(canGrowRule2);
				increasePopulation(tmpRegion, index);
			}
			else if (smallerXCoord(canGrowRule2) != -1) {
				index = smallerXCoord(canGrowRule2);
				increasePopulation(tmpRegion, index);
			}
		}
		else if (canGrowRule3.size() == 1) {
			for (auto& cell : canGrowRule3) {
				index = cell->getIndex();
				increasePopulation(tmpRegion, index);
			}
		}
		else if (canGrowRule3.size() > 1) {
			if (isLargerPopulation(canGrowRule3) != -1) {
				index = isLargerPopulation(canGrowRule3);
				increasePopulation(tmpRegion, index);
			}
			else if (totalAdjacentPopulation(canGrowRule3) != -1) { 				
				index = totalAdjacentPopulation(canGrowRule3);
				increasePopulation(tmpRegion, index);
			}
			else if (smallerYCoord(canGrowRule3) != -1) {
				index = smallerYCoord(canGrowRule3);
				increasePopulation(tmpRegion, index);
			}
			else if (smallerXCoord(canGrowRule3) != -1) {
				index = smallerXCoord(canGrowRule3);
				increasePopulation(tmpRegion, index);
			}
		}
		tmpResources.setTotalPopulation(tmpResources.getTotalPopulation() + 1);
		tmpResources.setComPopulation(tmpResources.getComPopulation() + 1);
		tmpResources.setNumWorkers(tmpResources.getWorkers() - 1);
		tmpResources.setNumGoods(tmpResources.getGoods() - 1);
	}

}

bool isPowerlineAdjacent(vector<char> neighbors) {
	for (unsigned int i = 0; i < neighbors.size(); i++)
	{
		if (neighbors[i] == 'T' || neighbors[i] == '#') {
			return true;
		}
	}

	return false;
}

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

int totalAdjacentPopulation(vector<City*> tmpRegion) {
	int index = -1;
	int numCells = 0;
	int tmpNumCells = 0;
	vector<int>neighbors;

	for (auto& cell : tmpRegion) {
		numCells = 0;
		neighbors = cell->getNeighborsPopulation();
		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			if (neighbors[i] > 0) {
				numCells++;
			}
		}
		if (numCells > tmpNumCells) {
			index = cell->getIndex();
			tmpNumCells = numCells;
		}
		else if (numCells == tmpNumCells) {
			index = -1;
		}
	}

	return index;
}

int smallerYCoord(vector<City*> tmpRegion) {
	int index = -1;
	int tmpYCoord = 0;

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

	return index;
}

int smallerXCoord(vector<City*> tmpRegion) {
	int index = -1;
	int tmpXCoord = 0;

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

	return index;
}