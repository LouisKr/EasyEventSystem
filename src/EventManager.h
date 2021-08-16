#pragma once

#include "Event.h"
#include "EventHandler.h"

#include <vector>
#include <functional>
#include <map>
#include <memory>
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

    using SlotType = std::function<void(const Event&)>;

    void subscribe(EventHandler handler);
    void deSubscribe(EventHandler handler);

private:
    EventManager() {};
    std::map<EventType, std::list<EventHandler>> Observeres;
};