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
vector<vector<char>> zone;

//Calls functions to read and parse files needed to make region layout
void readFiles() {

	cout << "Please enter config file name: ";
	getline(cin, configFile.configFileName);

	ParseConfig(configFile);

	ParseRegion(configFile, regionFile);

	//PrintRegion(regionFile);
}

//Prints the 2d vector containing the region layout
void PrintRegion(Region& regionFile)
{
	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
	cout << endl;

	for (auto& row : zone) {
		cout << '|';
		for (auto& cell : row) {
			cout << cell << " ";
		}
		cout << '|' << endl;
	}

	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
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

		vector<char> row;
		stringstream s(mySymbol);
		while (s.get(tmp)) {
			if (tmp == ',') {
				//do nothing
			}
			else {
				row.push_back(tmp);
			}
		}
		zone.push_back(row);

		regionFile.width = row.size();
	}

	ReadRegion.close();
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


void initRegion(vector<vector<City*>> &r) {
	for (auto& row : zone) {
		vector<City*> c;
		for (auto& cell : row) {
			switch (cell) {
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
		r.push_back(c);
	}
}

void displayRegion(vector<vector<City*>> &r) {
	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
	cout << endl;

	for (auto& row : r) {
		cout << '|';
		for (auto& cell : row) {
			cout << cell->getZoneType() << " ";
		}
		cout << '|' << endl;
	}

	for (int i = 0; i < regionFile.width * 2 + 2; i++)
	{
		cout << '-';
	}
	cout << endl;
}