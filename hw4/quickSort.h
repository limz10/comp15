//
//  quickSort.h
//  Header File for quickSort class
//

#ifndef __Sorting__quickSort__
#define __Sorting__quickSort__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class quickSort {
public:
        quickSort(); // constructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
	void sort();
        void sort(int *a, int left, int right);
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
};

#endif /* defined(__Sorting__quickSort__) */

