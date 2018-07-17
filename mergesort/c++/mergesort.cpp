#include <iostream>
#include <vector>
#include "mergesort.h"

const bool DEBUG = true;
std::stringstream debug_msg;

// Print vector 
void printVec(const std::vector<int> &v) {
	if (v.size() == 0) {
		std::cerr << "Error in printVec(): cannot print empty vector\n";
		return;
	}
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

/* Checks that a list of numbers is in non-decreasing order.
 * Returns: true if the list is in non-decreasing order, false otherwise.
*/
bool isSorted(std::vector<int> &v) {
	auto it = v.begin();
	while (it != v.end()-1) {
		if (*(it+1) < *it) {
			return false;
		}
		it++;
	}
	return true;
}

//Bubble-sort algorithm for a vector
std::vector<int> bubbleSort(const std::vector<int> &v) {
	std::vector<int> ret = v;

    int tmp = 0;
    for(auto i = ret.begin(); i < ret.end()-1; i++) {
        for(auto j = i+1; j < ret.end(); j++) {
            if (*i > *j) {
                tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
	return(ret);
}

/*
 * Summary: Takes two vectors of integers and merges them into one vector 
 * in order.
 * Arguments: Two vectors
 * Returns: A merged vector, with the elements of the left vector coming first
 * and the elements of the right vector coming after.
*/
std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right) {
	std::vector<int> ret{};
	if (!(&left) || !(&right)) {
		std::cerr << "Error in merge(): right or left vector is empty\n";
		return ret;
	}
	auto left_it = left.begin();
	auto right_it = right.begin();

	// Merge elements in-order
	while (left_it != left.end() || right_it != right.end()) {
		//Check left array for comparison
		if (left_it != left.end()) {
			if (*left_it < *right_it) {
				ret.push_back(*left_it);
				left_it++;
			}
			else if (right_it != right.end()) {
				ret.push_back(*right_it);
				right_it++;
			}
			// The right vector is finished and the left still has elements, 
			// so keep pushing left elements
			else {
				ret.push_back(*left_it);
				left_it++;
			}
		}
		//push remainder of right vector elements
		else if (right_it != right.end()) {
			ret.push_back(*right_it);
			right_it++;
		}
	}
	return ret;
}

/* 
 * Sorts a vector using the mergesort algorithm.
 * Arguments: a left and right vector
 * Returns: a sorted vector 
*/
std::vector<int> mergesort(const std::vector<int> &left, const std::vector<int> &right) {
	std::vector<int> ret{};
	if (left.size() == 0) {
		std::cerr << "Error in mergesort(): left vector is empty\n";
		return ret;
	}
	if (right.size() == 0) {
		std::cerr << "Error in mergesort(): right vector is empty\n";
		return ret;
	}
	// Base case: left or right (or both) arrays have one element. 
	// Use bubblesort to sort and merge the two arrays
	if (left.size() == 1 || right.size() == 1) {
		return(bubbleSort(merge(left,right)));
	}
	/* 
	 * Recursive definition: split the left and right arrays until one of the 
	 * two arrays has only one element.
	*/
	ret = merge( 
		mergesort((split(left))[0], (split(left))[1]),
		mergesort((split(right))[0], (split(right))[1])
	);

	return ret;
}

/*
 * Splits a vector into two halves.
 * Arguments: a vector
 * Returns: two vectors, evenly split (the left with the most elements if input vector not even) 
*/
std::vector<std::vector<int> > split(const std::vector<int> &v) {
	std::vector< std::vector<int> > ret{};
	std::vector<int> left{}, right{};
	//std::vector<int> right{};
	std::vector<int>::const_iterator mid = v.begin() + v.size()/2; //iterator to middle element of source vector

	//Return the vector if it has less than two elements
	if (v.size() < 2) {
		std::cerr << "Error in split(): vector not large enough to split\n";
	}
	//Copy first half of vector to left vector
	std::copy(v.begin(), mid, std::back_inserter(left));
	ret.push_back(left);
	//Copy the second half of the vector to the right vector
	std::copy(mid, v.end(), std::back_inserter(right));
	ret.push_back(right);

	return ret;
}