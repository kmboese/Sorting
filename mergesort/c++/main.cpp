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
uniform_int_distribution<int>  dist(0, UPPER_BOUND);



int main(int argc, char** argv){
	vector<int> v = {5, 6, 3, 4, 1};
	vector<int> sorted = {1,2,3};

	//Assertions
	cout << "Asserting sorted vector is sorted..." << endl;
	assert(isSorted(sorted));

	if(isSorted(v)){
		cout << "Vector v is sorted" << endl;
	}
	else{
		cout << "Vector v is not sorted " << endl;
	}
	return 0;
}

