//
//  mergeSort.h
//  Header File for mergeSort class
//

#ifndef __Sorting__mergeSort__
#define __Sorting__mergeSort__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class mergeSort {
public:
        mergeSort(); // constructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
        void sort();
	void sort(int *a, int *b, int low, int high);
	void merge(int *a, int low, int mid, int high, int *b);
        
        // print the array
        void printArray();
        
	//destructor
	~mergeSort();

private:
        arrayWithLength sortArray;
};

#endif /* defined(__Sorting_mergeSort__) */

