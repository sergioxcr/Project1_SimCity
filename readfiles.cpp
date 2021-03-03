#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "readfiles.h"

using namespace std;

Config configFile;
Region regionFile;
//2D vector that stores region layout
vector<vector<City*>> region;

//Calls functions to read and parse files needed to make region layout
void readFiles() {

	cout << "Please enter config file name: ";
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

void displayRegion() {
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
	cout << endl;
}