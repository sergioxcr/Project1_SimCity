#include <iostream>
#include <string>
#include "city.h"

using namespace std;

City::City() {
	numWorkers = 2;
	numGoods = 4;
	timeLimit = 0;
	refreshRate = 0;
	position;
}

City::City(int workers, int goods, int time, int rate, int location) {
	this->numWorkers = workers;
	this->numGoods = goods;
	this->timeLimit = time;
	this->refreshRate = rate;
	this->position = location;
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

void City::setPosition(int location) {
	this->position;
}

char City::getZoneType() const {
	return zoneType;
}

int City::getPopulation() const {
	return population;
}

int City::getPollution() const {
	return pollution;
}

int City::getPosition() const {
	return position;
}