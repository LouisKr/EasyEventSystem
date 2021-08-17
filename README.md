# EasyEventSystem
When creating bigger Projects, I would often find my self being really frustrated because my code become a mess, 
that was when I got into EventSystems.
I had to realize though that EventSystems often arent as simple and straight forward as i wished them to be.
Thats why I created my own.

## Setup
Just Include the Headers and cpp files from "src/" and you are good to go.

## Creating an Event
You only have to create your "EventType" and add an entry in the EventType-enum.

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
        :Event(EventType::MausEvent),
        x(x),
        y(y)
    {
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

## Subscribing to an Event
You only have to Create an EventHandler in your class and connect your function thats supposed to react to it.

Gui.h
```c++
#define FUNCTION_OneParam( funkce ) std::bind( (funkce), (this), std::placeholders::_1)

class Gui 
{
public:
    Gui() 
    {
        EventHandler MausEventHandler(EventType::MausEvent, FUNCTION_OneParam(&Gui::OnMausEvent)); 
        //if you dont want to use macro, use "std::bind(&Gui::OnMausEvent, this, std::placeholders::_1)"
        manager.deSubscribe(MausEventHandler); //DeSubscribing from an Event

        EventHandler MausEventHandler2(EventType::MausEvent, FUNCTION_OneParam(&Gui::OnMausEvent2));
    }

    void OnMausEvent(const Event& event)
    {
        const MausEvent& mausEvent = static_cast<const MausEvent&>(event);

        std::cout << "Maus Event! cords:" << mausEvent.x << ":" << mausEvent.y << "\n";
    }

    void OnMausEvent2(const Event& event)
    {
        const MausEvent& mausEvent = static_cast<const MausEvent&>(event);

        std::cout << "Maus Event2! cords:" << mausEvent.x << ":" << mausEvent.y << "\n";
    }
}
