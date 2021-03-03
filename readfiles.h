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
	int timeLimit = 0;
	int refreshRate = 0;
};

//region data
struct Region {
	int width = 0;
	int height = 0;
};

//Calls functions to read and parse files needed to make region layout
void readFiles();

//Prints the 2d vector containing the region layout
void PrintRegion(Region& regionFile);

//Reads the region csv file and stores it in the 2d vector making the region layout
void ParseRegion(Config& configFile, Region& regionFile);

//Reads the config txt file and stores the config data in a struct
void ParseConfig(Config& configFile);

void initRegion(vector<vector<City*>> &r);

void displayRegion();

#endif
