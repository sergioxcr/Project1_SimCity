#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "readfiles.h"

using namespace std;

//Variables
Config configFile;
Region regionFile;
City resources;
int oldTotalPopulation = -1;

//2D vectors that stores region layout
vector<vector<City*>> region;
vector<vector<City*>> oldRegion;


//Calls functions to read and parse files needed to make region layout
void readFiles() {
	cout << "Beginning simulation" << endl;
	cout << "Please enter the name of the configuration file: ";
	getline(cin, configFile.configFileName);

	ParseConfig(configFile);

	ParseRegion(configFile, regionFile);
}

//Reads the config txt file and stores the config data in a struct
void ParseConfig(Config& configFile)
{
	string myText;
	int lineCount = 0;

	ifstream ReadConfig(configFile.configFileName);
	if (!ReadConfig) {
		cout << "Invalid Config File, Exiting..." << endl;
		exit(0);
	}

	while (getline(ReadConfig, myText)) {

		if (lineCount == 0) {
			configFile.regionFileName = myText;
			configFile.regionFileName.erase(0, 14);
		}
		else if (lineCount == 1) {
			myText.erase(0, 11);
			configFile.timeLimit = stoi(myText);
			configFile.maxTime = configFile.timeLimit;
		}
		else if (lineCount == 2) {
			myText.erase(0, 13);
			configFile.refreshRate = stoi(myText);
		}

		lineCount++;
	}

	ReadConfig.close();
}

//Reads the region csv file and stores it in the 2d vector making the region layout
void ParseRegion(Config& configFile, Region& regionFile)
{
	string mySymbol;

	ifstream ReadRegion(configFile.regionFileName);
	if (!ReadRegion) {
		cout << "Invalid Region File, Exiting..." << endl;
		exit(0);
	}

	while (getline(ReadRegion, mySymbol)) {
		char tmp;

		stringstream s(mySymbol);


			vector<City*> c;
			while (s.get(tmp)) {
				switch (tmp) {
				case 'R':
					c.push_back(new Residential());
					break;
				case 'I':
					c.push_back(new Industrial());
					break;
				case 'C':
					c.push_back(new Commercial());
					break;
				case 'P':
					c.push_back(new Powerplant());
					break;
				case 'T':
					c.push_back(new Powerline());
					break;
				case '#':
					c.push_back(new PowerlineRoad());
					break;
				case '-':
					c.push_back(new Road());
					break;
				case ' ':
					c.push_back(new EmptyZone());
					break;
				default:
					break;
				}
			}
			region.push_back(c);
			regionFile.width = c.size();
			regionFile.height = region.size();
	}
	ReadRegion.close();
}

//Sets the X and Y Coordinates for each Cell
void setCoordinates() {
	int x = 0;
	int y = 0;

	for (auto& row : region) {
		for (auto& cell : row) {
			cell->setXCoord(x);
			cell->setYCoord(y);
			y++;
		}
		x++;
		y = 0;
	}
}

//Sets a number indicating position in the 2D vector
void setIndex() {
	int counter = 1;

	for (auto& row : region) {
		for (auto& cell : row) {
			cell->setIndex(counter);
			counter++;
		}
	}
}

//Displays the numbered position of each zone
void displayIndex() {

	for (auto& row : region) {
		for (auto& cell : row) {
			if (cell->getIndex() < 10) {
				cout << "00";
			}
			else if (cell->getIndex() < 100) {
				cout << "0";
			}
			cout << cell->getIndex() << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//Sets Neighbors(zoneType) for each zone
void setNeighbors() {
	int xMin, xMax;
	int yMin, yMax;
	char tmpZone = 'F';

	for (auto& row : region) {
		for (auto& cell : row) {
			xMin = cell->getXCoord() - 1;
			xMax = cell->getXCoord() + 1;
			yMin = cell->getYCoord() - 1;
			yMax = cell->getYCoord() + 1;
			for (auto& subRow : region) {
				for (auto& subCell : subRow) {
					if ((subCell->getXCoord() >= xMin && subCell->getXCoord() <= xMax) && (subCell->getYCoord() >= yMin && subCell->getYCoord() <= yMax) && (subCell->getXCoord() >= 0 && subCell->getXCoord() <=  regionFile.height) && (subCell->getYCoord() >= 0 && subCell->getYCoord() <= regionFile.width)) {
						if (subCell->getXCoord() == cell->getXCoord() && subCell->getYCoord() == cell->getYCoord()) {
							//do nothing
						}
						else {
							tmpZone = subCell->getZoneType();
							cell->setNeighbor(tmpZone);
						}
					}
				}
			}
		}
	}
}

//Displays Neighbors(zoneType) for each zone
void displayNeighbors() {
	vector<char> neighbors;

	for (auto& row : region) {
		for (auto& cell : row) {
			neighbors = cell->getNeighbors();
			cout << "Zone Coordinates: (" << cell->getXCoord() << "," << cell->getYCoord() << ")  Zone Type: " << cell->getZoneType() << endl;
			for (int i = 0; i < neighbors.size(); i++)
			{
				cout << "Neighbor " << i + 1 << ": " << neighbors[i] << endl;
			}
			cout << endl;
		}
	}
}

//Sets the population of each adjacent zone to each zone
void setNeighborsPopulation() {
	int xMin, xMax;
	int yMin, yMax;
	int tmpPopulation = 0;

	for (auto& row : region) {
		for (auto& cell : row) {
			cell->clearNeighborsPopulation();
		}
	}

	for (auto& row : region) {
		for (auto& cell : row) {
			xMin = cell->getXCoord() - 1;
			xMax = cell->getXCoord() + 1;
			yMin = cell->getYCoord() - 1;
			yMax = cell->getYCoord() + 1;
			for (auto& subRow : region) {
				for (auto& subCell : subRow) {
					if ((subCell->getXCoord() >= xMin && subCell->getXCoord() <= xMax) && (subCell->getYCoord() >= yMin && subCell->getYCoord() <= yMax) && (subCell->getXCoord() >= 0 && subCell->getXCoord() <= regionFile.height) && (subCell->getYCoord() >= 0 && subCell->getYCoord() <= regionFile.width)) {
						if (subCell->getXCoord() == cell->getXCoord() && subCell->getYCoord() == cell->getYCoord()) {
							//do nothing
						}
						else {
							tmpPopulation = subCell->getPopulation();
							cell->setNeighborPopulation(tmpPopulation);
						}
					}
				}
			}
		}
	}
}

//Displays the population of each adjacent zone to each zone
void displayNeighborsPopulation() {
	vector<int> neighborsPopulation;

	for (auto& row : region) {
		for (auto& cell : row) {
			neighborsPopulation = cell->getNeighborsPopulation();
			cout << "Zone Coordinates: (" << cell->getXCoord() << "," << cell->getYCoord() << ")  Zone Type: " << cell->getZoneType() << endl;
			for (int i = 0; i < neighborsPopulation.size(); i++)
			{
				cout << "Neighbor " << i + 1 << ": " << neighborsPopulation[i] << endl;
			}
			cout << endl;
		}
	}
}

//Displays the region layout by printing each cell stored in a 2D vector
void displayRegion() {
	if (configFile.timeStep == 0) {
		cout << "Initial Region State" << endl;
	}
	else if (configFile.timeLimit == -2) {
		cout << "Final Region State" << endl;
	}
	else {
		cout << "Time Step: " << configFile.timeStep << endl;
		cout << "Available Workers: " << resources.getWorkers() << " Available Goods: " << resources.getGoods() << endl;
		if (isValidRefresh(configFile.timeStep) == false) {
			cout << endl;
		}
	}

	if (isValidRefresh(configFile.timeStep) == true || configFile.timeLimit == -2)
	{
		for (int i = 0; i < regionFile.width * 2 + 2; i++)
		{
			cout << '-';
		}
		cout << endl;

		for (auto& row : region) {
			cout << '|';
			for (auto& cell : row) {
				if (cell->getPopulation() <= 0) {
					cout << cell->getZoneType() << " ";
				}
				else {
					cout << cell->getPopulation() << " ";
				}
			}
			cout << '|' << endl;
		}

		for (int i = 0; i < regionFile.width * 2 + 2; i++)
		{
			cout << '-';
		}
		cout << endl << endl;
	}
	else {
		//don't print
	}

		
}

//Displays the pollution in each cell
void displayPollution() {
	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
	cout << endl;

	for (auto& row : region) {
		cout << '|';
		for (auto& cell : row) {
			cout << cell->getPollution() << " ";
		}
		cout << '|' << endl;
	}

	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
	cout << endl;
}

//Displays the X and Y coordinates of each cell
void displayCoordinates() {

	for (auto& row : region) {
		cout << '|';
		for (auto& cell : row) {
			cout << cell->getXCoord() << "," << cell->getYCoord() << " ";
		}
		cout << '|' << endl;
	}
	cout << endl;
}

//Displays the current population of each zone
void displayPopulation() {
	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
	cout << endl;

	for (auto& row : region) {
		cout << '|';
		for (auto& cell : row) {
			cout << cell->getPopulation() << " ";
		}
		cout << '|' << endl;
	}

	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
	cout << endl;
}

//Checks if Region vector needs to be displayed depending on the Refresh Rate given by config file
bool isValidRefresh(int currentStep) {
	int counter = 1;
	while (counter <= configFile.maxTime) {
		counter += configFile.refreshRate;
		if (currentStep == 0 || currentStep == 1 || currentStep == counter) {
			return true;
		}
	}
	return false;
}

//Checks if the time limit or if region layout has not changed from previous time step. If yes, sends flag to end program.
bool isContinue() {
	if (configFile.timeLimit == -1 || resources.getTotalPopulation() == oldTotalPopulation)  {
		configFile.timeLimit = -2;
		displayRegion();
		cout << "Pollution" << endl;
		displayPollution();
		cout << "The total populations for the region are:" << endl;
		cout << "Residential: " << endl;
		cout << "Industrial: " << endl;
		cout << "Commercial: " << resources.getComPopulation() << endl;
		cout << "The total amount of pollution in the region is " << endl;
		return false;
	}
	else {
		configFile.timeStep++;
		configFile.timeLimit--;
		oldTotalPopulation = resources.getTotalPopulation();
		return true;
	}
}

//Increases the next zones available for population growth
void nextStep() {
	setNeighborsPopulation();

	switch (configFile.timeStep)
	{
	case 0:
		resources.setNumWorkers(4);
		resources.setNumGoods(1);
		break;
	case 1:
		resources.setNumWorkers(10);
		resources.setNumGoods(1);
		break;
	case 2:
		resources.setNumWorkers(6);
		resources.setNumGoods(4);
		break;
	case 3:
		resources.setNumWorkers(4);
		resources.setNumGoods(2);
		break;
	case 4:
		resources.setNumWorkers(0);
		resources.setNumGoods(1);
		break;
	default:
		break;
	}

	//check commercial increase
	while (resources.getWorkers() > 0 && resources.getGoods() > 0) {
		increaseCommercial(region, resources);
	}

	for (auto& row : region) {
		for (auto& cell : row) {
			cell->setGrown('N');
		}
	}
}

/*
for (auto& row : region) {
	for (auto& cell : row) {
		
	}
}
*/