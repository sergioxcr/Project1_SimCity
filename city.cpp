#include <iostream>
#include <string>
#include "city.h"

using namespace std;

City::City() {
	numWorkers = 0;
	numGoods = 0;
	timeLimit = 0;
	refreshRate = 0;
	xCoord = 0;
	yCoord = 0;
	cityPopulation = 0;
}

City::City(int workers, int goods, int time, int rate, int xPositon, int yPosition, int population) {
	this->numWorkers = workers;
	this->numGoods = goods;
	this->timeLimit = time;
	this->refreshRate = rate;
	this->xCoord = xPositon;
	this->yCoord = yPosition;
	this->cityPopulation = population;
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

bool isLargerPopulation(vector<vector<City*>>& tmpRegion, int tmpPopulation, char tmpZoneType)
{
	for (auto& row : tmpRegion) {
		for (auto& cell : row) {
			if (cell->getZoneType() == tmpZoneType) {
				if (cell->getPopulation() > tmpPopulation) {
					return false;
				}
			}
		}
	}

	return true;
}