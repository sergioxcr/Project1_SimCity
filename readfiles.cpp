#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "readfiles.h"

using namespace std;

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

