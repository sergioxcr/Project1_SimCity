#ifndef CITY_H
#define CITY_H

//#include <string>

using namespace std;

class City {
public:
	//constructors
	City();
	City(int workers, int goods, int time, int rate, int position);
	//Sets
	void setNumWorkers(int numWorkers);
	void setNumGoods(int numGoods);
	void setTimeLimit(int timeLimit);
	void setRefreshRate(int refreshRate);

	virtual void setPosition(int position);

	//Gets
	int getWorkers() const;
	int getGoods() const;
	int getTimeLimit() const;
	int getRefreshRate() const;

	virtual char getZoneType() const;
	virtual int getPopulation() const;
	virtual int getPollution() const;
	virtual int getPosition() const;

private:
	int numWorkers;
	int numGoods;
	int timeLimit;
	int refreshRate;
	int population = 0;
	int pollution = 0;
	int position = 0;
	char zoneType = 'E';
};

#endif