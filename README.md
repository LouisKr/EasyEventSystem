# EasyEventSystem
When creating bigger Projects, I would often find my self being really frustrated because my code become a mess, 
that was when I got into EventSystems.
I had to realize though that EventSystems often arent as simple and straight forward as i wished them to be.
Thats why I created my own.

## Setup
Just Include the Headers and cpp files and you are good to go.

## Creating an Event
You only have to create your "EventType" and add an entry in the EventType list

Event.h
```c++
enum class EventType
{
    DefaultEvent,
    MausEvent //Add the name of your Event
};
...
```
MausEvent.h
```c++
#include "Event.h"
#include "EventManager.h"

class MausEvent : public Event
{
public:
    MausEvent(int x, int y)
        :Event(EventType::MausEvent)
    {
        MausEvent::x = x;
        MausEvent::y = y;

        //call(); //uncomment this if you want your Event to be called automatic
    }

    int x;
    int y;
};
```
Call Event in any Part of your Code
```c++
MausEvent MEvent(23, 12);
MEvent.call();
```
