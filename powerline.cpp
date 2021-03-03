#include <iostream>
#include <string>
#include "powerline.h"

using namespace std;

Powerline::Powerline() {
	zoneType = 'T';
}

Powerline::Powerline(char zone) {
	this->zoneType = zone;
}

void Powerline::setZoneType(char zone) {
	this->zoneType = zone;
}

char Powerline::getZoneType() const {
	return zoneType;
}