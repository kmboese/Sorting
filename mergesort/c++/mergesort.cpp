#include <iostream>
#include <vector>
#include "mergesort.h"

const bool DEBUG = true;

//Print message if in DEBUG mode
void dPrint(std::string message) {
	if(DEBUG) {
		std::cout << "DEBUG: " << message << std::endl;
	}
}
bool isSorted(std::vector<int> v) {
	bool sorted = true;
	for (auto it = v.begin(); it < v.end()-1; it++) {
		if(*it > *(it+1) ) {
			sorted = false;
			break;
		}
	}
	return sorted;
}