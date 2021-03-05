#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "readfiles.h"

using namespace std;

Config configFile;
Region regionFile;
Global resources;
//2D vector that stores region layout
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
	}
	ReadRegion.close();
}

void setIndex() {
	int counter = 1;

	for (auto& row : region) {
		cout << '|';
		for (auto& cell : row) {
			cell->setPosition(counter);
			counter++;
		}
		cout << '|' << endl;
	}
}

void displayRegion() {
	if (configFile.timeStep == 0) {
		cout << "Initial Region State" << endl;
	}
	else if (configFile.timeLimit == -2) {
		cout << "Final Region State" << endl;
	}
	else {
		cout << "Time Step: " << configFile.timeStep << endl;
		cout << "Available Workers: " << resources.numWorkers << " Available Goods: " << resources.numGoods << endl;
		if (isValidRefresh(configFile.timeStep) == false) {
			cout << endl;
		}
	}

	if (isValidRefresh(configFile.timeStep) == true)
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

		oldRegion = region;
}

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

void displayIndex() {

	for (auto& row : region) {
		cout << '|';
		for (auto& cell : row) {
			cout << cell->getPosition() << " ";
		}
		cout << '|' << endl;
	}
	cout << endl;
}

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

bool isContinue() {
	if (configFile.timeLimit == -1)  {
		configFile.timeLimit--;
		displayRegion();
		cout << "Pollution" << endl;
		displayPollution();
		cout << "The total populations for the region are:" << endl;
		cout << "Residential: " << endl;
		cout << "Industrial: " << endl;
		cout << "Commercial: " << endl;
		cout << "The total amount of pollution in the region is " << endl;
		return false;
	}
	else {
		configFile.timeStep++;
		configFile.timeLimit--;
		return true;
	}
}