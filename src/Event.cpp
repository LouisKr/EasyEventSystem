#include "Event.h"
#include "EventManager.h"

Event::Event(EventType type)
    :type(type)
{}

void Event::call()
{
    EventManager::getInstance().callEvent(*this);
}