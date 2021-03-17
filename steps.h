#ifndef STEPS_H
#define STEPS_H

#include "city.h"
#include "residential.h"
#include "industrial.h"
#include "commercial.h"
#include "powerplant.h"
#include "powerline.h"
#include "powerlineroad.h"
#include "road.h"
#include "emptyzone.h"


using namespace std;

//config data
struct Config {
	string configFileName;
	string regionFileName;
	int maxTime = 0;
	int timeLimit = 0;
	int refreshRate = 0;
	int timeStep = -1;
};

//region data
struct Region {
	int width = 0;
	int height = 0;
};

extern Config configFile;
extern Region regionFile;
extern vector<vector<City*>> region;

//Sets the X and Y Coordinates for each Cell
void setCoordinates();

//Sets Neighbors(zoneType) for each cell
void setNeighbors();

//Displays Neighbors(zoneType) for each cell
void displayNeighbors();

//Sets the population of each adjacent zone to each zone
void setNeighborsPopulation();

//Displays the population of each adjacent zone to each zone
void displayNeighborsPopulation();

//Displays the X and Y coordinates of each cell
void displayCoordinates();

//Sets a number indicating position in the 2D vector
void setIndex();

//Displays the numbered position of each zone
void displayIndex();

//Displays the current population of each zone
void displayPopulation();

//Prints the 2d vector containing the region layout
void displayRegion();

//Checks if the time limit or if region layout has not changed from previous time step. If yes, sends flag to end program.
bool isContinue();

//Checks if Region vector needs to be displayed depending on the Refresh Rate given by config file
bool isValidRefresh(int);

//Increases the next zones available for population growth
void nextStep();

#endif