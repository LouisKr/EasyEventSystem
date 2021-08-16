#pragma once
#include "Event.h"
#include "EventManager.h"

class ButtonPressEvent : public Event
{
public:
    ButtonPressEvent(int ButtonId)
        :Event(EventType::ButtonEvent)
    {
        ButtonPressEvent::ButtonId = ButtonId;
        callEvent();
    }

    int ButtonId;
};
