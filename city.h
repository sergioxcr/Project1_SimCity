#ifndef CITY_H
#define CITY_H

//#include <string>

using namespace std;

class City {
public:
	//constructors
	City();
	City(int numWorkers, int numGoods, int timeLimit, int refreshRate);
	//Sets
	void setNumWorkers(int numWorkers);
	void setNumGoods(int numGoods);
	void setTimeLimit(int timeLimit);
	void setRefreshRate(int refreshRate);
	//Gets
	int getWorkers() const;
	int getGoods() const;
	int getTimeLimit() const;
	int getRefreshRate() const;
	virtual char getZoneType() const;

private:
	int numWorkers;
	int numGoods;
	int timeLimit;
	int refreshRate;
	char zoneType;
};



#endif