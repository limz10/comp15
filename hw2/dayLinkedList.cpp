//
//  dayLinkedList.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.

//  Modified by Mingzhe Li on 2/9/14

#include "dayLinkedList.h"
#include <cassert>

Day::Day()
{ 
    eventList = NULL;
    eventCount = 0;
}

void Day::scheduleEvent() // add default Event for a full Day
{ 
    scheduleEvent(0,2359,"");
}

void Day::scheduleEvent(int startTime, int endTime, string description)
{
    EventNode * newEvent = new EventNode();
    newEvent->theEvent = Event(startTime, endTime, description);
    EventNode * tempNode = eventList;
    //if the list is empty
    if (eventList == NULL) {
	eventList = newEvent;
	eventList->next = NULL;
	eventCount++;
    }
    //insert the event at the beginning of the list
    if (newEvent->theEvent.amIBefore(eventList->theEvent)) {
	newEvent->next = eventList;
	eventList = newEvent;
	eventCount++;
	return;
    }
    //insert the event at the middle or the end of the list
    //the loop searches the first event before the new event
    while (tempNode != NULL) {	
	//insert at the end of the list
	if (tempNode->next == NULL) {
	    tempNode->next = newEvent;
	    newEvent->next = NULL;
	    eventCount++;
	    return;
	}
	//insert in the middle of the list
	if (newEvent->theEvent.amIBefore(tempNode->next->theEvent)) {
	    //insert a simultaneous event
	    if (!tempNode->theEvent.amIBefore(newEvent->theEvent)) {
		newEvent->next = tempNode->next;
		tempNode->next = newEvent;
		eventCount++;
		return;
	    }
	    newEvent->next = tempNode->next;
	    tempNode->next = newEvent;
	    eventCount++;
	    return;
	}		
	tempNode = tempNode->next;
    }
}

void Day::scheduleEvent(Event anEvent)
{
    scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),
		  anEvent.getDescription());
}

void Day::cancelEvent(Event anEvent)
{
    //creates a temp node and a follower node
    EventNode * tempNode = eventList;
    EventNode * follower = tempNode;

    //if the event to cancel is at the beginning of the list
    if (eventList == NULL)
	return;
    else if (eventList->theEvent.isSameEventAs(anEvent)) {
	eventList = eventList->next;
//	delete tempNode;
	eventCount--;
	return;
    }
    //loop thru the list to locate the event to cancel
    //delete the temp node and link follower to the next
    while (tempNode != NULL) {
	if (tempNode->theEvent.isSameEventAs(anEvent)) {
	    follower->next = tempNode->next;
	    delete tempNode;
	    eventCount--;
	    return;
	}
	follower = tempNode;
	tempNode = tempNode->next;
    }
}

void Day::printDay() 
{
    EventNode * tempNode = eventList;

    while (tempNode != NULL) {
	tempNode->theEvent.printEvent();
	tempNode = tempNode->next;
    }
}

string Day::exportDay()
{
    string csvString = "";
    EventNode *tempEventNode = eventList;
    while (tempEventNode != NULL) {
	csvString+= tempEventNode->theEvent.eventCSV() + "\n";
	tempEventNode = tempEventNode->next;
    }
    return csvString;
}

Day::~Day() 
{
    while (eventList != NULL) {
	EventNode *tempNextNode = eventList->next;
	delete eventList;
	eventList = tempNextNode;
    }
}
