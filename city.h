#ifndef CITY_H
#define CITY_H

//#include <string>
#include <vector>

using namespace std;

class City {
public:
	//constructors
	City();
	City(int workers, int goods, int time, int rate, int xPosition, int yPosition, int population);

	//Sets
	void setNumWorkers(int numWorkers);
	void setNumGoods(int numGoods);
	void setTimeLimit(int timeLimit);
	void setRefreshRate(int refreshRate);

	virtual void setXCoord(int xPosition);
	virtual void setYCoord(int yPosition);
	virtual void setNeighbor(char tmpZone);
	virtual void setPopulation(int population);

	//Gets
	int getWorkers() const;
	int getGoods() const;
	int getTimeLimit() const;
	int getRefreshRate() const;

	virtual char getZoneType() const;
	virtual int getPopulation() const;
	virtual int getPollution() const;
	virtual int getXCoord() const;
	virtual int getYCoord() const;
	virtual vector<char> getNeighbors() const;

private:
	int numWorkers;
	int numGoods;
	int timeLimit;
	int refreshRate;
	int cityPopulation = 0;
	int pollution = 0;
	int xCoord;
	int yCoord;
	char zoneType = 'E';
	vector<char>neighbors;
};

//check for larger population of same zone type
bool isLargerPopulation(vector<vector<City*>>, int, char);

//check for larger num of neighbors of same zone type

//check for smaller y coordinate

//check for smaller x coordinate


#endif