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
	displayRegion();
/*
	while (isContinue() == true) {
		displayRegion();
	}
*/
	return 0;
}