#pragma once

#include "Event.h"
#include "UUID.h"

#include <functional>

class EventHandler
{
public:
    EventHandler(EventType Type, std::function<void(const Event&)> Func);

    bool operator==(const EventHandler& other);

    std::function<void(const Event&)> func;

    const EventType& getType()
    {
        return type;
    }

private:
    const sole::uuid uuid;
    const EventType type;
};