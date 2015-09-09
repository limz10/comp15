/* sandwichList.cpp
 * Comp 15 
 * Spring 2014 
 * Lab 4
   Modified by Mingzhe Li on Feb 18, 2014
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
    capacity = INITIAL_SIZE;
    orders = new Order[INITIAL_SIZE];
    orderCount = 0;
    back = 0;
    front = 0;
}

bool SandwichList::isEmpty()
{
    if (size() == 0)
	return true;
    else
	return false;
}


int SandwichList::size()
{
    return orderCount;
    // you could use the following arithmetic (but be careful):
    //return (back - front + capacity) % capacity;
}

//function to remove Order from the front of the queue
Order SandwichList::dequeue()
{
    orderCount--;
 
    cerr << "remove" << endl;

    front++;

    if (front >= capacity)
	front = 0;

    cerr << "front: " << front << endl << endl;;

    if (front == 0)
	return orders[capacity - 1];
    else
	return orders[front - 1];
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::enqueue(const Order & sw)
{
    if (capacity == size()) {
//	cerr << "start expand" << endl;
	expandList();
    }


//    cerr << "check expand" << endl;
    cerr << "front: " << front << " back: " << back << endl;

    orders[back] = sw;
    orderCount++;

    cerr << "insert" << endl;

    if (back >= capacity - 1)
	back = 0;	
    else 
	back++;

    cerr << "capacity: " << capacity << " and Size:" << orderCount << endl;
    cerr << "front: " << front << " back: " << back << endl << endl;

    if (back == front)
	expandList();
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{
    orders = new Order[capacity * 2];

    int i = capacity - 1;
    capacity = capacity * 2;

//    cerr << "capacity" << capacity << endl;

    int j = capacity - 1;   

    while (i >= front) {

	cerr << "i: " << i << " j: " << j << endl;

	orders[j] = orders[i];

	cerr << "copy" << endl;
	
	i--;
	j--;
    }

    front = j + 1;
}

void SandwichList::printOrder(Order s)
{
    cout << s.sandwich << " " << s.customerName << " " 
	 << s.orderNbr << " " << s.fries << endl;
}



