#include <iostream>
#include <string>
#include <vector>

#include "readfiles.h"
#include "city.h"
#include "residential.h"
#include "commercial.h"

using namespace std;

int main() {
	//initial setup
	readFiles();
	setIndex();
	setCoordinates();
	setNeighbors();
	//	displayNeighbors();


	while (isContinue() == true) {
		displayRegion();
		nextStep();
	}
	
	//	displayNeighborsPopulation();
	//	displayIndex();
	//	displayPopulation();

	return 0;
}