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

void bubbleSort(std::vector<int> &v) {
    int tmp = 0;
    for(auto i = v.begin(); i < v.end(); i++) {
        for(auto j = i+1; j < v.end()-1; j++) {
            if (*i > *j){
                tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}