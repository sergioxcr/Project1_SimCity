#include <iostream>
#include <string>
#include "city.h"

using namespace std;

City::City() {
	totPopulation = 0;
	resPopulation = 0;
	indPopulation = 0;
	comPopulation = 0;
	numWorkers = 12;
	numGoods = 12;
	timeLimit = 0;
	refreshRate = 0;
	index = 0;
	xCoord = 0;
	yCoord = 0;
	cityPopulation = 0;
}

City::City(int workers, int goods, int time, int rate, int xPositon, int yPosition, int population, int index, int totalPopulation, int rPopulation, int iPopulation, int cPopulation) {
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

void increasePopulation(vector<vector<City*>>& tmpRegion, int index) {
	for (auto& row : tmpRegion) {
		for (auto& cell : row) {
			if (cell->getIndex() == index) {
				cell->setPopulation(cell->getPopulation() + 1);
			}
		}
	}
}

int isLargerPopulation(vector<City*> tmpRegion)
{
	int tmpPopulation = 0;
	int index = -1;

	for (auto& cell : tmpRegion) {
		if (cell->getPopulation() > tmpPopulation) {
			tmpPopulation = cell->getPopulation();
			index = cell->getIndex();
		}
		else if (cell->getPopulation() == tmpPopulation) {
			index = -1;
		}
	}

	return index;
}

