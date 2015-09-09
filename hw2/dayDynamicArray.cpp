//
//  dayDynamicArray.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.

//  Modified by Mingzhe Li on 2/9/2014

#include "dayDynamicArray.h"
#include <cassert>
#include <string>

const int Day::INIT_CAPACITY;

Day::Day()
{
    eventList = new Event [INIT_CAPACITY];
    eventCount = 0;
    eventCapacity = INIT_CAPACITY;
}

void Day::scheduleEvent() 
{
    scheduleEvent(0,2359,"");
}

void Day::scheduleEvent(int startTime, int endTime, string description)
{
    //expand the dynamic array
    if (eventCount >= eventCapacity) {
	eventCapacity = eventCapacity * 2;
	Event * temp = new Event [eventCapacity];

	for (int i = 0; i < eventCount; i++)
	    temp[i] = eventList[i];

	delete [] eventList;
	eventList = temp;
    }

    Event newEvent(startTime, endTime, description);

    //if the list is empty
    if (eventCount == 0) {
	eventList[0] = newEvent;
	eventCount++;
    }
    else {
	//loop thru the list
	for (int i = 0; i < eventCount; i++)
	    if (newEvent.amIBefore(eventList[i])) {
	    	
		//move the elements backwards
		for (int j = eventCount-1; j >= i; j--)
		    eventList[j+1] = eventList[j];   

		eventList[i] = newEvent;
		eventCount++;

		return;    
	    }

	eventList[eventCount] = newEvent;
	eventCount++;
    }	   
}

void Day::scheduleEvent(Event anEvent)
{
    scheduleEvent(anEvent.getStartTime(),
		  anEvent.getEndTime(),anEvent.getDescription());
}

void Day::cancelEvent(Event anEvent)
{
    //loop thru the list to locate the event to cancel
    for (int i = 0; i < eventCount; i++) 
	if (eventList[i].isSameEventAs(anEvent)) {

	    //move the elements forwards
	    for (int j = i;j < eventCount-1; j++)
		eventList[j] = eventList[j+1];

	    eventCount--;
	    return;
	}
}

void Day::printDay() 
{
    for (int i = 0; i < eventCount; i++) 	
	eventList[i].printEvent();

}

string Day::exportDay()
{
    string csvString = "";
    for (int index = 0;index < eventCount; index++) 
	csvString+= eventList[index].eventCSV() + "\n";
    
    return csvString;
}

Day::~Day()
{
    delete [] eventList;
}
