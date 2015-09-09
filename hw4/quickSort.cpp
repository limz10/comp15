//
//  quickSort.cpp
//  Sorts integers using the quickSort algorithm
//

#include "quickSort.h"

using namespace std;

quickSort::quickSort()
{ // constructor
    sortArray.length = 0;
    sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void quickSort::readList()
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

void quickSort::sort()
{
    sort(sortArray.arr, 0, sortArray.length);
}

void quickSort::sort(int *a, int left, int right)
{
    //if the length of the subarray is less than one, no need to sort 
    if ((right-left+1) <= 1)
	return;

    //set pivot index to the middle 
    int i = left; int j = right-1;
    int pivot = a[(i+j)/2];
    int tmp;

    while (i <= j) {
	while (a[i] < pivot)	i++;
	while (a[j] > pivot)	j--;
	if (i <= j) {
	    tmp = a[i];
	    a[i] = a[j];
	    a[j] = tmp;
	    i++;	
	    j--;
	}
    }
    if (left < j)
	sort(a,left,j+1);
    if (i < right)
	sort(a,i,right);
}

void quickSort::printArray()
{
    for (int i = 0; i < sortArray.length; i++)
	cout << sortArray.arr[i] << endl;
}


