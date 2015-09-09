//
//  SelectionSort.cpp
//  Sorts integers using the SelectionSort algorithm
//

#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort()
{ // constructor
    sortArray.length = 0;
    sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList()
{
    int currentCapacity = 10;
    sortArray.arr = new int[currentCapacity];
        
    while (cin >> sortArray.arr[sortArray.length]) {
	++sortArray.length;
	if (sortArray.length==currentCapacity) {
	    int *temp = new int[currentCapacity*2];
	    for (int i=0;i<currentCapacity;i++) {
		temp[i] = sortArray.arr[i];
	    }
	    delete [] sortArray.arr;
	    sortArray.arr = temp;
	    currentCapacity *= 2;
	}
    }
}

void SelectionSort::sort()
{
    if (sortArray.length <= 1)
	return;

    int min;
    for (int i = 0; i < sortArray.length-1; i++) {
	min = i;
	for (int j = i; j < sortArray.length; j++)
	    if (sortArray.arr[j] < sortArray.arr[min])
		min = j;
	if (min != i) {
	    int tmp = sortArray.arr[i];
	    sortArray.arr[i] = sortArray.arr[min];
	    sortArray.arr[min] = tmp;
	}
    }
}

void SelectionSort::printArray()
{
    for (int i = 0; i < sortArray.length; i++)
	cout << sortArray.arr[i] << endl;
}

SelectionSort::~SelectionSort()
{
    delete[] sortArray.arr;
}
