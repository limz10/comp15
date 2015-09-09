//
//  mergeSort.cpp
//  Sorts integers using the SelectionSort algorithm
//

#include "mergeSort.h"

using namespace std;

mergeSort::mergeSort()
{ // constructor
    sortArray.length = 0;
    sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void mergeSort::readList()
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

void mergeSort::sort()
{
    int b[sortArray.length];
    sort(sortArray.arr,b,0,sortArray.length);
}

void mergeSort::sort(int *a, int *b, int low, int high)
{
    //if the subarray has one or less elements, no need to sort
    if (high-low+1 <= 2)
	return;

    int mid = (low+high)/2;
    sort(a,b,low,mid);
    sort(a,b,mid,high);
    merge(a,low,mid,high,b);
    for (int i = low; i < high; i++)
	a[i] = b[i];
}

void mergeSort::merge(int *a, int low, int mid, int high, int *b)
{
    int i = low; int j = mid;
    for (int k = low; k < high; k++)
	if (i < mid && (j >= high || a[i] <= a[j])) {
	    b[k] = a[i];
	    i++;
	}
	else {
	    b[k] = a[j];
	    j++;
	}
}

void mergeSort::printArray()
{
    for (int i = 0; i < sortArray.length; i++)
	cout << sortArray.arr[i] << endl;
}

mergeSort::~mergeSort()
{
    delete[] sortArray.arr;
}
