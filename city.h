#ifndef CITY_H
#define CITY_H

//#include <string>

using namespace std;

class City {
public:
	//constructors
	City();
	City(int workers, int goods, int time, int rate, int xPosition, int yPosition);

	//Sets
	void setNumWorkers(int numWorkers);
	void setNumGoods(int numGoods);
	void setTimeLimit(int timeLimit);
	void setRefreshRate(int refreshRate);

	virtual void setXCoord(int xPosition);
	virtual void setYCoord(int yPosition);

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

private:
	int numWorkers;
	int numGoods;
	int timeLimit;
	int refreshRate;
	int population = 0;
	int pollution = 0;
	int xCoord;
	int yCoord;
	char zoneType = 'E';
};

#endif