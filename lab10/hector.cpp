#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//

// constructor
Hector::Hector()
{
    for(int i = 0; i < TSIZE; i++)
    {
	cheneyTable[i] = NULL;
	linnyTable[i] = -1;
	doublesTable[i] = -1;
    }
}


// linear probing
//
//  returns number of collisions before finding a spot
//
int Hector::linny(int value)
{
    int attempt = 0;
    int index;
    bool found = false;

    int jump = 1;

    while (!found) {
	index = (3*value + 7 + jump*attempt) % 17;
	if (linnyTable[index] == -1) {
	    linnyTable[index] = value;
	    found = true;
	}
	else 
	    attempt++;
    }

    return attempt;
}

// double hashing using a second function
//  
//  returns number of collisions before finding a spot
//
int Hector::doubles(int value)
{
    int attempt = 0;
    int index;
    bool found = false;

    int jump = 13 - (value % 13);

    while (!found) {
	index = (3*value + 7 + jump*attempt) % 17;
	if (doublesTable[index] == -1) {
	    doublesTable[index] = value;
	    found = true;
	}
	else 
	    attempt++;
    }

    return attempt;	
}

// chained hashing -- each spot in table is a linked list 
//
//  returns number of items in that spot before insertion
//
int Hector::cheney(int value)
{
    int index = (3*value + 7) % 17;

    Node *newNode = new Node;
    newNode->key = value;
    newNode->next = NULL;

    if (cheneyTable[index] == NULL) {
	cheneyTable[index] = newNode;
	return 0;
    }
    else {
	newNode->next = cheneyTable[index];
	cheneyTable[index] = newNode;
	return length(cheneyTable[index]->next);
    }

    return -1;
}

int Hector::length(Node *a)
{
    int counter = 0;
    while (a != NULL) {
	a = a->next;
	counter++;
    }

    return counter;
}

// print the hash tables
void Hector::print()
{
    for(int i=0; i < TSIZE; i++)
    {
	cout << linnyTable[i] << " ";
		
    }
	
    cout << endl;
	
    for(int i=0; i < TSIZE; i++)
    {
	cout << doublesTable[i] << " ";
		
    }
    cout << endl;
	
    Node* iter = NULL;
    for(int i=0; i < TSIZE; i++)
    {
	iter = cheneyTable[i];
	cout << " [";
	while(iter != NULL)
	{
	    cout << iter->key << " ";
	    iter = iter->next;
	}
	cout << "]";
    }
    cout << endl;
}
