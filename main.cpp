#include <iostream>
#include <string>
#include <vector>

#include "readfiles.h"
#include "city.h"
#include "residential.h"
#include "commercial.h"

using namespace std;

int main() {
	vector<vector<City*>> region;

	readFiles();

	initRegion(region);

	displayRegion(region);

	return 0;
}