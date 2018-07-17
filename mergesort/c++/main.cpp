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

/* Test that the bubbleSort algorithm returns a sorted list of numbers. */
void testBubbleSort() {
	//Save a copy of the original vector for comparison
	vector<int> v = {5,6,3,4,1}; 
	vector<int> orig = v;
	cout << "***** testBubbleSort ***** " << endl;
	cout << "Unsorted vector: \n";
	printVec(v);
	cout << "Sorting vector with bubblesort...\n";
	v = bubbleSort(v);
	cout << "Sorted vector: \n";
	printVec(v);
	//Assert that the size of the sorted vector is the same as the original vector
	assert(v.size() == orig.size());
	//Assert that the vector is indeed sorted
	assert(isSorted(v));

}

/* 
 * Tests that a list of an even number of elements is split correctly.
 * Asserts: the two split vectors of a source vector have the same number of elements, and that they each have half the number of elements.

*/
void testEvenSplit() {
	cout << " ***** testEvenSplit ***** \n";
	vector<int> v = genVector(10,1,50);
	vector<vector<int> > splitV = split(v);
	assert(splitV[0].size() == splitV[1].size());
	assert(splitV[0].size() == v.size()/2);
	assert(splitV[1].size() == v.size()/2);

}

/* 
 * Tests that a list of an odd number of elements is split correctly:
 * Asserts:
 *	- The left vector has v.size()/2 elements
	- The right vector has v.size()/2 + 1 elements
*/
void testOddSplit() {
	cout << " ***** testOddSplit ***** \n";
	vector<int> v = genVector(11,1,50);
	vector<vector<int> > splitV = split(v);
	assert(splitV[0].size()+1 == splitV[1].size());
	assert(splitV[0].size() == v.size()/2);
	assert(splitV[1].size() == v.size()/2+1);
}

int main(int argc, char** argv) {
	vector<int> rand = genVector(20, 1, 1000);
	vector<int> sorted {};
	vector<int> left{}, right{};

	// Function tests
	testBubbleSort();
	testEvenSplit();
	testOddSplit();

	// ***** Testing mergesort ***** 
	cout << "Random vector: \n";
	printVec(rand);
	cout << "Splitting vector: \n";
	vector<vector<int> > pair = split(rand);
	cout << "Printing left half...\n";
	printVec(pair[0]);
	cout << "Printing right half...\n";
	printVec(pair[1]);
	cout << "Merging split vectors: \n";
	vector<int> merged = merge(pair[0], pair[1]);
	printVec(merged);
	cout << "Testing mergesort: \n";

	cout << "DEBUG: split(rand)[0] == ";
	printVec(split(rand)[0]);
	cout << "DEBUG: split(rand)[1] == ";
	printVec(split(rand)[1]);
	//sorted = mergesort((split(rand))[0], (split(rand))[1]);
	vector<int> test;
	sorted = mergesort(split(rand)[0], split(rand)[1]);
	printVec(sorted);


	return 0;
}

