#include <iostream>
#include <vector>
#include "mergesort.h"

const bool DEBUG = true;
std::stringstream debug_msg;

//Print message if in DEBUG mode
void dPrint(std::stringstream& ss) {
	std::string s;
	std::cout << "DEBUG: ";
	while(std::getline(ss, s)) {
		std::cout << s;
	}
	std::cout << "\n";
	ss.clear();
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
bool isSorted(std::vector<int> &v) {
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
    for(auto i = v.begin(); i < v.end()-1; i++) {
        for(auto j = i+1; j < v.end(); j++) {
            if (*i > *j) {
                tmp = *i;
                *i = *j;
                *j = tmp;
				//debug_msg << "i == " << *i << ", j == " << *j; dPrint(debug_msg);
            }
        }
    }
}

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right) {
	std::vector<int> ret{};
	std::string sLeft = toString(left);
	std::string sRight = toString(right);
	debug_msg << "Left: " << toString(left) << "\tRight: " << toString(right); dPrint(debug_msg);
	return ret;
}

std::vector<std::vector<int> > split(std::vector<int> &v) {
	std::vector< std::vector<int> > ret{};
	std::vector<int> left{100}, right{100};
	std::vector<int>::iterator it;

	debug_msg << "v.size() == " << v.size() << ", v.size()/2 == " << v.size()/2; dPrint(debug_msg);

	//Return the vector if it has less than two elements
	if (v.size() < 2) {
		ret.push_back(v);
		return ret;
	}
	//Copy first half of vector to left vector
	std::copy(v.begin(), v.begin()+3, left.begin());
	ret.push_back(left);
	//Copy the second half of the vector to the right vector
	std::copy(v.begin()+3, v.end(), right.begin());
	ret.push_back(right);

	return ret;
}