#ifndef CITY_H
#define CITY_H

//#include <string>

using namespace std;

class City {
public:
	//constructors
	City();
	City(int position);
	//Sets
//	void setNumWorkers(int numWorkers);
//	void setNumGoods(int numGoods);

	virtual void setPosition(int position);

	//Gets
//	int getWorkers() const;
//	int getGoods() const;

	virtual char getZoneType() const;
	virtual int getPopulation() const;
	virtual int getPollution() const;
	virtual int getPosition() const;

private:
//	int numWorkers;
//	int numGoods;
//	int timeLimit;
//	int refreshRate;
	int population = 0;
	int pollution = 0;
	int position = 0;
	char zoneType = 'E';
};

struct Global {
	int numWorkers;
	int numGoods;
	int pollution = 4;
};


#endif