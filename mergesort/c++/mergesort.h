#ifndef _MERGESORT_H
#define _MERGESORT_H
#include <vector>
#include <string>
#include <sstream>

//Returns true if a vector is sorted, false otherwise
bool isSorted(std::vector<int> &v);

//Prints a debug message if DEBUG flag is set to true
void dPrint(std::stringstream &ss);

//print a vector
void printVec(const std::vector<int> &v);

//Transform a vector into a string
std::string toString(std::vector<int> &v);

//Sorts a vector using the bubble-sort algorithm
std::vector<int> bubbleSort(const std::vector<int> &v);

//Merges two vectors into one sorted vector
std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right);

//Splits one vector into two halves
std::vector<std::vector<int> > split(const std::vector<int> &v);

//Sorts a vector using the mergesort algorithm
std::vector<int> mergesort(const std::vector<int> &left, const std::vector<int> &right);

#endif 