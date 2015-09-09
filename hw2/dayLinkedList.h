//
//  dayLinkedList.h
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#ifndef __CalendarOrderedLists__dayLinkedList__
#define __CalendarOrderedLists__dayLinkedList__

#include <iostream>
#include "event.h"

struct EventNode {
        Event theEvent;
        EventNode *next;
};

class Day {
public:        
	Day(); // constructor
        void scheduleEvent(); // default event for full day
        void scheduleEvent(int startTime, int endTime, string description);
        void scheduleEvent(Event anEvent);
        void cancelEvent(Event anEvent);
        void printDay();
        string exportDay();
        ~Day(); // destructor
private:
	EventNode *eventList;
        int eventCount;        
};


#endif /* defined(__CalendarOrderedLists__dayLinkedList__) */
