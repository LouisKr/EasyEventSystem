#include "EventManager.h"
#include <iostream>

void EventManager::callEvent(const Event& event)
{
    if (Observeres.find(event.type) == Observeres.end())
        return;

    for (std::list<EventHandler>::iterator it = Observeres[event.type].begin(); it != Observeres[event.type].end(); it++)
    {
        it->func(event);
    }
}

void EventManager::subscribe(EventHandler handler)
{
    Observeres[handler.getType()].push_back(handler);
}

void EventManager::deSubscribe(EventHandler handler)
{
    Observeres[handler.getType()].remove(handler);
}