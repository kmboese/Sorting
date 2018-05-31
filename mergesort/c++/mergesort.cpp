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

//Print vector 
void printVec(std::vector<int> &v) {
	std::cout << "[ ";
	for(auto x : v)
		std::cout << x << " ";
	std::cout << "]\n";
}

std::string toString(std::vector<int> &v) {
	std::string ret = "";
	for (auto x : v){
		ret += char(x);
		ret += " ";
	}
	return ret;
}

//Returns true if vector is sorted, false otherwise
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

//Bubble-sort algorithm for a vector
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

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right) {
	std::vector<int> ret{};
	std::string sLeft = toString(left);
	std::string sRight = toString(right);
	dPrint("Left: " + sLeft + "\tRight " + sRight);

	return ret;
}