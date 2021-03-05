#include <iostream>
#include <string>
#include <vector>

#include "readfiles.h"
#include "city.h"
#include "residential.h"
#include "commercial.h"

using namespace std;

int main() {

	readFiles();
	setIndex();
	while (isContinue() == true) {
		displayRegion();
	}

	displayIndex();

	return 0;
}