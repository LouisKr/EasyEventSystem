#pragma once
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

        callEvent();
    }

    int x;
    int y;
};