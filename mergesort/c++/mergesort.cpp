#include <iostream>
#include <vector>
#include "mergesort.h"

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