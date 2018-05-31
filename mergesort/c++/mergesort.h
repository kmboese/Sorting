#ifndef _MERGESORT_H
#define _MERGESORT_H
#include <vector>
#include <string>

//Returns true if a vector is sorted, false otherwise
bool isSorted(std::vector<int> v);

//Prints a debug message if DEBUG flag is set to true
void dPrint(std::string message);

//Sorts a vector using the bubble-sort algorithm
void bubbleSort(std::vector<int> &v);

#endif 