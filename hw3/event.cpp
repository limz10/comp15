//
//  event.cpp
//
// Enter overview information here.


#include "event.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Event::Event() 
{ // constructor
    startTime = 0;
    endTime = 2359;
    description = "";      
}

Event::Event(int startT, int endT, string desc) 
{
    startTime = startT;
    endTime = endT;
    description = desc;
}

int Event::getStartTime() 
{
    return startTime;
}

int Event::getEndTime() 
{
    return endTime;
}

std::string Event::getDescription() 
{
    return description;
}

void Event::setStartTime(int startT) 
{
    startTime = startT;
}

void Event::setEndTime(int endT) 
{
    endTime = endT;
}

void Event::setDescription(string str) 
{
    description = str;
}

bool Event::amIBefore(Event otherEvent) 
{
    if (startTime < otherEvent.getStartTime())
	return true;

    return false;
}

bool Event::isSameEventAs(Event otherEvent) 
{
    if (startTime == otherEvent.getStartTime() &&
	endTime == otherEvent.getEndTime() &&
	description == otherEvent.getDescription())
	return true;

    return false;
}

// conflictsWith returns true if this event overlaps with another event
// during the day
// events can "touch" but not overlap. I.e., one event can end
// at the same time the next event begins and this is not an overlap
bool Event::conflictsWith(Event anEvent) 
{
    if (startTime >= anEvent.getEndTime() || endTime <= anEvent.getStartTime())
	return false;

    return true;
}

void Event::printEvent()
{
    cout << "Start Time: " << convert24HourTime(startTime) << "\n";
    cout << "End Time: " << convert24HourTime(endTime) << "\n";
    cout << "Description: " << description << "\n\n";
}

string Event::eventCSV() 
{
    string EventString = convert24HourTime(startTime) + "," +
	convert24HourTime(endTime) + "," +
	description;
    return EventString;
        
}

// converts an integer in 24-hour time (e.g., 1330) to
// a string that is in 12-hour time with AM or PM, as follows:
// The int 1330 becomes
// the string "1:30 PM"
string Event::convert24HourTime(int time24)
{
    string fullTime, meridiem; // meridiem is used for "AM" or "PM"
       
    // ostringstream is used to convert an int to a string
    // use as follows, to read hourNum into hour_oss:
    // hour_oss << hourNum
    // To convert an osstringstream to a string,
    // use the .str() conversion:
    // hour_oss.str() will produce a string
    ostringstream hour_oss,minute_oss;     
    int hourNum, minuteNum;
        
    // first determine whether we are in AM or PM
    if (time24 < 1200) {
	meridiem = "AM";
	hourNum = time24 / 100;
    }
    else {
	meridiem = "PM";
	hourNum = (time24 - 1200) / 100;
    }
    if (hourNum == 0) hourNum = 12;
    minuteNum = time24 % 100;
    hour_oss << hourNum;    minute_oss << minuteNum;
    if (minuteNum == 0)
	fullTime = hour_oss.str() + ":" + minute_oss.str() + "0 " + meridiem;
    else fullTime = hour_oss.str() + ":" + minute_oss.str() + " " + meridiem;
    return fullTime;
}
