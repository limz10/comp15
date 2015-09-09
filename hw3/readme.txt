This program is modified by Mingzhe Li to complete a basic calendar app.

The key of this program is the nextFreeBlock function. When scheduling an
event, we first check if it overlaps with other events. If not, then we just
schedule it and add it to the calendar. If it does conflict with other events,
we will try to find the next free time slot to fit in the event. If there is
no available time slot in that day, then we could not schedule this event.

My approach is pretty straighforward: if there is not a conflict, then just
add the event to the calendar.  If it does conflict with other events,
then I will start searching the free time slot from the end time
of the conflicted event.  So I create a temp event starting at the end time
of the conflicted event and ending after the duration of the original event.
If this temp event does not conflict with any other events in the calendar,
then we return the start time of the temp event and thus get the next
free block.

Currently it works well on all conditions except for the situation of 
multiple overlapping events, where it loses first event.
