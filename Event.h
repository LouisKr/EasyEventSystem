#pragma once

enum class EventType
{
    MausEvent,
    ButtonEvent
};

class Event
{
public:
    Event(EventType type)
        : type (type)
    {}

    EventType type;
};