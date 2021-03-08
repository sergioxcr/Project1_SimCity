#ifndef READFILES_H
#define READFILES_H

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

//Calls functions to read and parse files needed to make region layout
void readFiles();

//Sets the X and Y Coordinates for each Cell
void setIndex();

//Sets Neighbors(zoneType) for each cell
void setNeighbors();

//Displays Neighbors(zoneType) for each cell
void displayNeighbors();

void setNeighborsPopulation();

void displayNeighborsPopulation();

//Displays the X and Y coordinates of each cell
void displayIndex();

//Prints the 2d vector containing the region layout
void displayRegion();

//Reads the region csv file and stores it in the 2d vector making the region layout
void ParseRegion(Config& configFile, Region& regionFile);

//Reads the config txt file and stores the config data in a struct
void ParseConfig(Config& configFile);

//Checks if the time limit or if region layout has not changed from previous time step. If yes, sends flag to end program.
bool isContinue();

//Checks if Region vector needs to be displayed depending on the Refresh Rate given by config file
bool isValidRefresh(int currentStep);

void nextStep();

#endif
