//
//  runList.cpp
//  OrderedRunners
//  Modified by Mingzhe Li on 2/4/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "runList.h"
#include "runner.h"
#include <iostream>
using namespace std;

RunList::RunList() 
{
    head = NULL;
    tail = NULL;
}

RunnerNode *RunList::getHead()
{
    return head;
}

RunnerNode *RunList::getTail()
{
    return tail;
}

void RunList::insertInOrder(string runnerName,int runnerTime) 
{
    RunnerNode *newNode = new RunnerNode();
    newNode->aRunner = Runner(runnerName,runnerTime);
    
    RunnerNode *tempNode = head;
    
    if (tempNode == NULL)  // there aren't any nodes yet
    	insertBefore(head,newNode);

    else {
    	while (!newNode->aRunner.isFasterThan(tempNode->aRunner)) {
    		if (tempNode->next == NULL) {
    			insertAfter(tempNode, newNode);
    			return;
    		}
    		tempNode = tempNode->next;
    	}
    	insertBefore(tempNode, newNode);
    }
}

void RunList::insertBefore(RunnerNode *aNode,RunnerNode *newNode) 
{
    if (aNode == NULL) { // if empty list
	head = newNode;
	tail = newNode;
    }
    else {
	newNode->prev = aNode->prev;
	newNode->next = aNode;

	if (newNode->prev == NULL) { // at the head
	    head = newNode;
	}
	else {
	    newNode->prev->next = newNode;
	}
	aNode->prev = newNode;
    }
}

void RunList::insertAfter(RunnerNode *aNode, RunnerNode *newNode) 
{
    if (aNode == NULL) { // empty list
	head = newNode;
	tail = newNode;
    }
    else {
	newNode->prev = aNode;
	newNode->next = aNode->next;
	if (newNode->next == NULL) { // at the tail
	    tail = newNode;
	}
	else {
	    newNode->next->prev = newNode;
	}
                
	aNode->next = newNode;
    }

}

void RunList::printList(bool reversed)
{
    RunnerNode *iterator;
        
    if (reversed) {
	iterator = tail;
    }
    else {
	iterator = head;
    }
        
    while (iterator != NULL) {
	cout << iterator->aRunner.getName() << ": ";
	cout << iterator->aRunner.getTime() << "\n";
	if (reversed) {
	    iterator = iterator->prev;
	}
	else {
	    iterator = iterator->next;
	}
    }
}
