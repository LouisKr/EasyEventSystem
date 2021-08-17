#pragma once

#include "Event.h"
#include "EventHandler.h"

#include <vector>
#include <map>
#include <list>


class EventManager
{
public:
    static EventManager& getInstance()
    {
        static EventManager instance; 
                             
        return instance;
    }

    void callEvent(const Event& event);

    void subscribe(EventHandler handler);
    void deSubscribe(EventHandler handler);

private:
    EventManager() {};
    std::map<EventType, std::list<EventHandler>> Observeres;
};
