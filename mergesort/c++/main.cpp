#include <iostream>
#include <vector>
#include <assert.h>
#include "mergesort.h"

using namespace std;

int main(int argc, char** argv){
	vector<int> v = {9, 6, 3, 4, 1};
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

