#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <random>
#include <chrono>

#include "mergesort.h"

using namespace std;

#define UPPER_BOUND 100 //largest number random generator will generate
//Globally define random seed
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 gen(seed);


//Format variables
string divider = "_____________________________________________\n";

//Testing Functions
/*
 * Generate an integer vector
 * Arguments:
 * 	size: Size of the vector to be generated
 * 	lower_bound: lower bound of integers to be generated
 * 	upper_bound: upper bound of integeres to be generated

*/

vector<int> genVector(int size, int lower_bound, int upper_bound) {
	vector<int> ret{};
	uniform_int_distribution<int> dist(lower_bound, upper_bound);
	for (int i = 0; i < size; i++) {
		ret.push_back(dist(gen));
	}
	return ret;
}

void testBubbleSort(vector<int>& v) {
	//Save a copy of the original vector for comparison
	vector<int> orig = v;
	cout << "***** Testing Bubblesort ***** " << endl;
	cout << "Unsorted vector: \n";
	printVec(v);
	cout << "Sorting vector with bubblesort...\n";
	bubbleSort(v);
	cout << "Sorted vector: \n";
	//Assert that the size of the sorted vector is the same as the original vector
	assert(v.size() == orig.size());
	//Assert that the vector is indeed sorted
	assert(isSorted(v));
	printVec(v);

}

int main(int argc, char** argv){
	vector<int> v = {5,6,3,4,1};
	vector<int> rand = genVector(10, 0, 10);
	vector<int> left{}, right{};
	vector<int> sorted = {1,2,3};

	//Function tests
	testBubbleSort(v);

	cout << "Random vector: \n";
	printVec(rand);
	vector<vector<int> > pair = split(rand);
	cout << "Printing left half...\n";
	printVec(pair[0]);
	cout << "Printing right half...\n";
	printVec(pair[1]);

	return 0;
}

