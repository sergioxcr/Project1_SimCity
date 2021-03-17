#ifndef READFILES_H
#define READFILES_H

#include "steps.h"


using namespace std;


//Calls functions to read and parse files needed to make region layout
void readFiles();

//Reads the region csv file and stores it in the 2d vector making the region layout
void ParseRegion(Config&, Region&);

//Reads the config txt file and stores the config data in a struct
void ParseConfig(Config&);



#endif
