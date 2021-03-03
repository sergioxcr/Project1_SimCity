#include <iostream>
#include <string>
#include "city.h"

using namespace std;

City::City() {
	numWorkers = 0;
	numGoods = 0;
	timeLimit = 0;
	refreshRate = 0;
}

City::City(int workers, int goods, int time, int rate) {
	this->numWorkers = workers;
	this->numGoods = goods;
	this->timeLimit = time;
	this->refreshRate = rate;
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

char City::getZoneType() const {
	return zoneType;
}
