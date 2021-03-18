#include <iostream>
#include <string>
#include "city.h"

using namespace std;

City::City() {
	hasGrown = 'N';
	totPopulation = 0;
	resPopulation = 0;
	indPopulation = 0;
	comPopulation = 0;
	numWorkers = 0;
	numGoods = 0;
	timeLimit = 0;
	refreshRate = 0;
	index = 0;
	xCoord = 0;
	yCoord = 0;
	cityPopulation = 0;
}

City::City(int workers, int goods, int time, int rate, int xPositon, int yPosition, int population, int index, int totalPopulation, int rPopulation, int iPopulation, int cPopulation, char grown) {
	this->totPopulation = totalPopulation;
	this->resPopulation = rPopulation;
	this->indPopulation = iPopulation;
	this->comPopulation = cPopulation;
	this->numWorkers = workers;
	this->numGoods = goods;
	this->timeLimit = time;
	this->refreshRate = rate;
	this->index = index;
	this->xCoord = xPositon;
	this->yCoord = yPosition;
	this->cityPopulation = population;
	this->hasGrown = grown;
}

void City::setTotalPopulation(int totalPopulation) {
	this->totPopulation = totalPopulation;
}

int City::getTotalPopulation() const {
	return totPopulation;
}

void City::setResPopulation(int rPopulation) {
	this->resPopulation = rPopulation;
}

int City::getResPopulation() const {
	return resPopulation;
}

void City::setIndPopulation(int iPopulation) {
	this->indPopulation = iPopulation;
}

int City::getIndPopulation() const {
	return indPopulation;
}

void City::setComPopulation(int cPopulation) {
	this->comPopulation = cPopulation;
}

int City::getComPopulation() const {
	return comPopulation;
}

void City::setNumWorkers(int workers) {
	this->numWorkers = workers;
}

int City::getWorkers() const {
	return numWorkers;
}

void City::setNumGoods(int goods) {
	this->numGoods = goods;
}

int City::getGoods() const {
	return numGoods;
}

void City::setTimeLimit(int time) {
	this->timeLimit = time;
}

int City::getTimeLimit() const {
	return timeLimit;
}

void City::setRefreshRate(int rate) {
	this->refreshRate = rate;
}

int City::getRefreshRate() const {
	return refreshRate;
}

void City::setXCoord(int xPosition) {
	this->xCoord = xPosition;
}

int City::getXCoord() const {
	return xCoord;
}

void City::setYCoord(int yPosition) {
	this->yCoord = yPosition;
}

int City::getYCoord() const {
	return yCoord;
}

char City::getZoneType() const {
	return zoneType;
}

char City::getGrown() const {
	return hasGrown;
}

void City::setPopulation(int population) {
	this->cityPopulation = population;
}

int City::getPopulation() const {
	return cityPopulation;
}

int City::getPollution() const {
	return pollution;
}

void City::setNeighbor(char tmpZone) {
	neighbors.push_back(tmpZone);
}

vector<char> City::getNeighbors() const {
	return neighbors;
}

void City::setNeighborPopulation(int tmpPopulation) {
	neighborsPopulation.push_back(tmpPopulation);
}

vector<int> City::getNeighborsPopulation() const {
	return neighborsPopulation;
}

void City::clearNeighborsPopulation() {
	neighborsPopulation.clear();
}

void City::setIndex(int index) {
	this->index;
}

int City::getIndex() const {
	return index;
}

void City::setGrown(char grown) {
	this->hasGrown = grown;
}

void increasePopulation(vector<vector<City*>>& tmpRegion, int index) {
	for (auto& row : tmpRegion) {
		for (auto& cell : row) {
			if (cell->getIndex() == index) {
				cell->setPopulation(cell->getPopulation() + 1);
			}
		}
	}
}

void alreadyGrew(vector<vector<City*>>& tmpRegion, int index) {
	for (auto& row : tmpRegion) {
		for (auto& cell : row) {
			if (cell->getIndex() == index) {
				cell->setGrown('Y');
			}
		}
	}
}

int isLargerPopulation(vector<City*> &tmpRegion)
{
	int tmpPopulation = 0;
	int index = -1;
	vector<City*> canGrow;

	for (auto& cell : tmpRegion) {
		if (cell->getPopulation() > tmpPopulation) {
			tmpPopulation = cell->getPopulation();
			index = cell->getIndex();
		}
		else if (cell->getPopulation() == tmpPopulation) {
			index = -1;
		}
	}

	if (index == -1) {
		for (auto& cell : tmpRegion) {
			if (cell->getPopulation() == tmpPopulation) {
				canGrow.push_back(cell);
			}
		}
		tmpRegion = canGrow;
	}

	return index;
}

//checks which zone has a greater number of 
int totalAdjacentPopulation(vector<City*>& tmpRegion) {
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

int smallerYCoord(vector<City*>& tmpRegion) {
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

int smallerXCoord(vector<City*>& tmpRegion) {
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
int isPopulationAdjacent(vector<int> neighbors, int atLeast) {
	int numCells = 0;
	if (atLeast == 1) {
		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			if (neighbors[i] > 0) {
				numCells++;
			}
		}
	}
	else if (atLeast == 2) {
		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			if (neighbors[i] > 1) {
				numCells++;
			}
		}
	}
	else if (atLeast == 3) {
		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			if (neighbors[i] > 2) {
				numCells++;
			}
		}
	}
	else if (atLeast == 4) {
		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			if (neighbors[i] > 3) {
				numCells++;
			}
		}
	}

	return numCells;
}