//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "mergeSort.h"

using namespace std;

int main()
{
        mergeSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
