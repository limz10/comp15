//
//  main.cpp
//  Sorting
//

#include <iostream>
#include "quickSort.h"

using namespace std;

int main()
{
        quickSort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
        sorter.printArray();
}
