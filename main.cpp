#include <iostream>
#include <string>
#include <vector>

#include "readfiles.h"
#include "city.h"
#include "residential.h"
#include "commercial.h"

using namespace std;

int main() {

	readFiles();
	setIndex();
	setCoordinates();
	setNeighbors();
	setNeighborsPopulation();
	//	displayNeighbors();
	//	displayNeighborsPopulation();

	while (isContinue() == true) {
		displayRegion();
		nextStep();
	}

	//	displayIndex();
	displayPopulation();

	return 0;
}