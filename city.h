#ifndef CITY_H
#define CITY_H

//#include <string>
#include <vector>

using namespace std;

class City {
public:
	//constructors
	City();
	City(int workers, int goods, int time, int rate, int xPosition, int yPosition, int population, int index);

	//Sets
	void setNumWorkers(int numWorkers);
	void setNumGoods(int numGoods);
	void setTimeLimit(int timeLimit);
	void setRefreshRate(int refreshRate);

	virtual void setIndex(int index);
	virtual void setXCoord(int xPosition);
	virtual void setYCoord(int yPosition);
	virtual void setNeighbor(char tmpZone);
	virtual void setNeighborPopulation(int tmpPopulation);
	virtual void setPopulation(int population);

	//Gets
	int getWorkers() const;
	int getGoods() const;
	int getTimeLimit() const;
	int getRefreshRate() const;

	virtual char getZoneType() const;
	virtual int getPopulation() const;
	virtual int getPollution() const;
	virtual int getIndex() const;
	virtual int getXCoord() const;
	virtual int getYCoord() const;
	virtual vector<char> getNeighbors() const;
	virtual vector<int> getNeighborsPopulation() const;

private:
	int numWorkers;
	int numGoods;
	int timeLimit;
	int refreshRate;
	int cityPopulation = 0;
	int pollution = 0;
	int index;
	int xCoord;
	int yCoord;
	char zoneType = 'E';
	vector<char>neighbors;
	vector<int>neighborsPopulation;
};

//check for larger population of same zone type
int isLargerPopulation(vector<City*>);

//check for larger num of neighbors of same zone type

//check for smaller y coordinate

//check for smaller x coordinate


void increasePopulation(vector<vector<City*>>&, int);

#endif